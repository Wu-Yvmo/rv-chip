// import "DPI-C" function int pmem_read(input int raddr);
// import "DPI-C" function void pmem_write(
//   input int waddr, input int wdata, input byte wmask);

#include <bits/types/struct_timeval.h>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <stdint.h>
#include <string>
#include <sys/select.h>

#include <sys/time.h>

#include "read_file.hpp"

#define STORAGE_SIZE (0x08000000)

// 100MHz
#define CYCLE_PER_US 1000

uint8_t storage[STORAGE_SIZE] = {0};
timeval pmem_start_time;
uint64_t cycle_count;

void pmem_load_insts(const char *path) {
    // 初始化时间 
    gettimeofday(&pmem_start_time, nullptr);

    auto file_content = read_file(path);
    if (file_content.file_length > STORAGE_SIZE) {
        throw std::runtime_error("out of storage size");
    }

    // 将文件中每个uint8_t都放进去
    for (size_t i = 0; i < STORAGE_SIZE; i += 1) {
        if (i < file_content.file_length) {
            storage[i] = file_content.file_content[i];
            continue;
        }
        storage[i] = 0;
    }
}

bool uart_ready = false;

unsigned long long get_time_buffer = 0;

unsigned long long get_time() {
    return cycle_count / CYCLE_PER_US;
}

// 行为：总读4个字节发送
// 按照0x80000000的偏移进行访问
// deepseek说这种改发不是很行
extern "C" int pmem_read(int raddr) {
    // uart状态读
    if (raddr == 0x10000004) {  // 读出UART状态
        uart_ready = (rand() & 0x7) == 0 ? 1 : 0;
        return uart_ready; // 就绪概率为12.5%
    }
    // 读出时钟的低32位
    else if (raddr == 0x20000000) { 
        return get_time() & 0xffffffff; 
    }
    // 读出时钟的高32位
    else if (raddr == 0x20000004) { 
        return get_time() >> 32; 
    }

    // 常规的访存逻辑
    raddr -= 0x80000000;
    if (raddr > STORAGE_SIZE) {
        throw std::runtime_error("pmem storage too small");
    }
    auto d1 = (int)storage[raddr];
    auto d2 = (int)storage[raddr+1];
    auto d3 = (int)storage[raddr+2];
    auto d4 = (int)storage[raddr+3];

    return d1 | d2 <<8 | d3 << 16 | d4 << 24;
}

// 行为：0001 0011 1111表示要写的字节数
// 按照0x80000000的偏移进行访问
extern "C" void pmem_write(int waddr, int wdata, uint8_t wmask) {
    if (waddr == 0x10000000) {  // 写入UART
        fputc(wdata & 0xff, stderr);   // 在stdio.h中定义
        return;
    }
    
    // 常规的内存写逻辑
    waddr -= 0x80000000;
    if (waddr > STORAGE_SIZE) {
        throw std::runtime_error("pmem storage too small");
    }

    storage[waddr] = (uint8_t)wdata;
    if (wmask == 0b0001) {
        return;
    }
    storage[waddr+1] = (uint8_t)(wdata>>8);
    if (wmask == 0b0011) {
        return;
    }
    storage[waddr+2] = (uint8_t)(wdata>>16);
    storage[waddr+3] = (uint8_t)(wdata>>24);
    return;
}

#define IFU_STATUS_IDLE 0
#define IFU_STATUS_WAIT 1
#define IFU_STATUS_WAIT_LOAD 2

int ifu_status;

extern "C" void ifu_status_at_idle() {
    ifu_status = IFU_STATUS_IDLE;
}

extern "C" void ifu_status_at_wait() {
    ifu_status = IFU_STATUS_WAIT;
}

extern "C" void ifu_status_at_wait_load() {
    ifu_status = IFU_STATUS_WAIT_LOAD;
}
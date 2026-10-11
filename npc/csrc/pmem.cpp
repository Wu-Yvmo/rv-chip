// import "DPI-C" function int pmem_read(input int raddr);
// import "DPI-C" function void pmem_write(
//   input int waddr, input int wdata, input byte wmask);

#include <cstdint>
#include <stdexcept>
#include <stdint.h>
#include <string>

#include "read_file.hpp"

// :~/ysyx-workbench/am-kernels/tests/cpu-tests
#define STORAGE_SIZE (0x08000000)

uint8_t storage[STORAGE_SIZE] = {0};

void pmem_load_insts(const char *path) {
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

// 行为：总读4个字节发送
// 按照0x80000000的偏移进行访问
extern "C" int pmem_read(int raddr) {
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
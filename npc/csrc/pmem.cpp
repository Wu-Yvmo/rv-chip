// import "DPI-C" function int pmem_read(input int raddr);
// import "DPI-C" function void pmem_write(
//   input int waddr, input int wdata, input byte wmask);

#include <cstdint>
#include <stdint.h>

uint8_t storage[256] = {
    // 0x00: addi x1, x0, 10       机器码 0x00A00093
    0x93, 0x00, 0xA0, 0x00,
    // 0x04: addi x2, x0, 20       机器码 0x01400113
    0x13, 0x01, 0x40, 0x01,
    // 0x08: add x3, x1, x2        机器码 0x002081B3
    0xB3, 0x81, 0x20, 0x00,
    // 0x0C: lui x4, 0x10000       机器码 0x00010237
    0x37, 0x02, 0x01, 0x00,
    // 0x10: addi x5, x0, 0x80     机器码 0x08000293
    0x93, 0x02, 0x00, 0x08,
    // 0x14: sw x3, 0(x5)          机器码 0x0032A023
    0x23, 0xA0, 0x32, 0x00,
    // 0x18: sb x1, 4(x5)          机器码 0x00128223
    0x23, 0x82, 0x12, 0x00,
    // 0x1C: lw x6, 0(x5)          机器码 0x0002A303
    0x03, 0xA3, 0x02, 0x00,
    // 0x20: lbu x7, 4(x5)         机器码 0x0042C383
    0x83, 0xC3, 0x42, 0x00,
    // 0x24: addi x8, x0, 0x2C     机器码 0x02C00413
    0x13, 0x04, 0xC0, 0x02,
    // 0x28: jalr x0, 0(x8)        机器码 0x00040067
    0x67, 0x00, 0x04, 0x00,
    // 0x2C: ebreak                机器码 0x00100073
    0x73, 0x00, 0x10, 0x00,
    // 其余 208 字节自动初始化为 0
};

// 行为：总读4个字节发送
extern "C" int pmem_read(int raddr) {
    auto d1 = (int)storage[raddr];
    auto d2 = (int)storage[raddr+1];
    auto d3 = (int)storage[raddr+2];
    auto d4 = (int)storage[raddr+3];

    return d1 | d2 <<8 | d3 << 16 | d4 << 24;
}

// 行为：0001 0011 1111表示要写的字节数
extern "C" void pmem_write(int waddr, int wdata, uint8_t wmask) {
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
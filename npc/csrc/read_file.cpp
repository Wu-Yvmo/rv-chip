#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <stdint.h>
#include <format>

#include "read_file.hpp"

FileContent read_file(const char *path) {
    FileContent file_content;
    auto *fp = fopen(path, "rb");
    if (!fp) {
        throw std::runtime_error(std::format("can't open file: {}", path));
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    uint8_t *buf = (uint8_t *)malloc((size_t)size + 1);
    if (!buf) {
        throw std::runtime_error("can't alloc buffer");
    }

    size_t n = fread(buf, 1, (size_t)size, fp);

    // 开始把数据挪进我们约定的存储
    file_content.file_length = n;
    file_content.file_content = buf;
    // for (size_t i = 0; i < n; i += 1) {
    //     file_content.file_content[i] = buf[i];
    // }

    return file_content;
}
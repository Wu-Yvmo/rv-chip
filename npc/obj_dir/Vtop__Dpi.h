// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTOP__DPI_H_
#define VERILATED_VTOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at vsrc/top.v:21:34
    extern void ifu_status_at_idle();
    // DPI import at vsrc/top.v:23:34
    extern void ifu_status_at_wait();
    // DPI import at vsrc/top.v:25:34
    extern void ifu_status_at_wait_load();
    // DPI import at vsrc/top.v:14:33
    extern int pmem_read(int raddr);
    // DPI import at vsrc/top.v:15:34
    extern void pmem_write(int waddr, int wdata, char wmask);

#ifdef __cplusplus
}
#endif

#endif  // guard

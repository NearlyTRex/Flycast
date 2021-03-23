#pragma once
#include "types.h"
#include "stdclass.h"
#include "hw/sh4/sh4_if.h"

f32 vrf(u32 addr);
u32 vri(u32 addr);

//vram 32-64b
extern VArray2 vram;

//regs
u32 pvr_ReadReg(u32 addr);
void pvr_WriteReg(u32 paddr, u32 data);

void DYNACALL TAWrite(u32 address, const SQBuffer *data, u32 count);
void DYNACALL TAWriteSQ(u32 address, const SQBuffer *sqb);

void YUV_init();
void YUV_serialize(void **data, unsigned int *total_size);
void YUV_unserialize(void **data, unsigned int *total_size, serialize_version_enum version);

template<typename T> T DYNACALL pvr_read_area1(u32 addr);
template<typename T> void DYNACALL pvr_write_area1(u32 addr, T data);
template<typename T, bool upper> T DYNACALL pvr_read_area4(u32 addr);
template<typename T, bool upper> void DYNACALL pvr_write_area4(u32 addr, T data);

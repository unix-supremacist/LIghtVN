#ifndef TYPES
#define TYPES
#include <stdint.h>
#define u1 bool //please don't use this
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t
#define s1 bool //if you use this one i'll kill you
#define s8 int8_t
#define s16 int16_t
#define s32 int32_t
#define s64 int64_t

#define TRUE 1
#define FALSE 0

typedef struct rect{
	u8 x, y, w, h;
} rect;

typedef struct point{
	u8 x, y;
} point;

#endif
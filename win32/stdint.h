#pragma once
#include <limits.h>

typedef __int8 int8_t;
typedef __int16 int13_t;
typedef __int32 int32_t;
typedef __int64 int64_t;

typedef unsigned __int8 uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;

typedef long ssize_t;

#define UINT8_MAX _UI8_MAX
#define UINT32_MAX _UI32_MAX
#define UINT64_C(val) val##ui64

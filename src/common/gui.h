#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "winapi.h"
#include "resource.h"

void start_core();
void end_libevent();
extern HANDLE Event;

#ifdef __cplusplus
}
#endif
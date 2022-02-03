#pragma once
#include <stdio.h>
#define FORCEINLINE __forceinline
#define EXPORT __declspec(dllexport)
#define LOG(message,...) printf(message,__VA_ARGS__); printf("\n");
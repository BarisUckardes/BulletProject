#pragma once
#include <stdio.h>

/*
* Forces compiler to inline the functions (Removes to function call overhead while increasing the application file size)
*/
#define FORCEINLINE __forceinline

/*
* Tells compiler to export symbols so applications which imported this library can use those functions-classes.
* But in this application it used to eliminate to FORCEINLINE side effects such as previnting the multiple definitions found error.
*/
#define EXPORT __declspec(dllexport)

/*
* Simple macro to print text onto console application
*/
#define LOG(message,...) printf(message,__VA_ARGS__); printf("\n");
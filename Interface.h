/*
 * @Description: dlfcn sample interface header
 * @version: 0.1
 * @Author: Ricardo Lu<shenglu1202@163.com>
 * @Date: 2021-08-07 22:52:01
 * @Last Editor: Ricardo Lu
 * @LastEditTime: 2021-08-07 23:57:34
 */
#ifndef __INTERFACE_H__
#define __INTERFACE_H__
#include <stdio.h>

extern "C" void* init();
extern "C" long long plus(void* math, int a, int b);
extern "C" long long minus(void* math, int a, int b);
extern "C" long long multi(void* math, int a, int b);
extern "C" int divide(void* math, int a, int b);

#endif // __INTERFACE_H__
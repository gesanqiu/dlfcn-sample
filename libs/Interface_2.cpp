/*
 * @Description: dlfcn sample interface implement
 * @version: 0.1
 * @Author: Ricardo Lu<shenglu1202@163.com>
 * @Date: 2021-08-07 22:52:01
 * @Last Editor: Ricardo Lu
 * @LastEditTime: 2021-08-07 23:58:11
 */
#include <stdio.h>

#include "Interface.h"
#include "libmath_2.h"

void *init()
{
    operations *op = new operations;

    return op;
}

long long plus(void* math, int a, int b)
{
    operations *op = (operations *)math;

    return op->sum(a, b);
}

long long minus(void* math, int a, int b)
{
    operations *op = (operations *)math;

    return op->sub(a, b);
}

long long multi(void* math, int a, int b)
{
    operations *op = (operations *)math;

    return op->mult(a, b);
}

int divide(void* math, int a, int b)
{
    operations *op = (operations *)math;

    return op->div(a, b);
}
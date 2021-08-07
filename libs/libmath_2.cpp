/*
 * @Description: math library 2
 * @version: 0.1
 * @Author: Ricardo Lu<shenglu1202@163.com>
 * @Date: 2021-08-07 22:50:12
 * @Last Editor: Ricardo Lu
 * @LastEditTime: 2021-08-07 23:55:02
 */
#include <exception>
#include <stdexcept>

#include "libmath_2.h"

long long operations::sum(const int &a, const int &b)
{
    printf("operation 2 plus called.\n");
    return a + b;
}

long long operations::mult(const int &a, const int &b)
{
    printf("operation 2 multiplication called.\n");
    return a * b;
}

int operations::div(const int &a, const int &b)
{
    printf("operation 2 divide called.\n");
    if(b == 0){
        throw std::overflow_error("Divide by zero exception");
    }
    return a/b;
}

long long operations::sub(const int &a, const int &b)
{
    printf("operation 2 minus called.\n");
    return a - b;
}
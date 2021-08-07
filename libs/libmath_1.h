/*
 * @Description: 
 * @version: 
 * @Author: Ricardo Lu<shenglu1202@163.com>
 * @Date: 2021-08-07 23:41:12
 * @Last Editor: 
 * @LastEditTime: 2021-08-08 00:08:46
 */
#ifndef __LIB_MATH_1_H__
#define __LIB_MATH_1_H__

#include <stdio.h>

class operations{
public:
    operations()
    {
        printf("operation 1 object constructured.\n");
    }
    long long sum(const int &a, const int &b);
    long long mult(const int &a, const int &b);
    int  div(const int &a, const int &b);
    long long sub(const int &a, const int &b);
};

#endif // __LIB_MATH_1_H__
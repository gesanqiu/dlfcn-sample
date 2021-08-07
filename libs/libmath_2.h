/*
 * @Description: 
 * @version: 
 * @Author: Ricardo Lu<shenglu1202@163.com>
 * @Date: 2021-08-07 23:41:18
 * @Last Editor: 
 * @LastEditTime: 2021-08-07 23:43:35
 */
#ifndef __LIB_MATH_2_H__
#define __LIB_MATH_2_H__

#include <stdio.h>

class operations{
public:
    operations()
    {
        printf("operation 2 object constructured.\n");
    }
    long long sum(const int &a, const int &b);
    long long mult(const int &a, const int &b);
    int  div(const int &a, const int &b);
    long long sub(const int &a, const int &b);
};

#endif // __LIB_MATH_2_H__
/*
 * @Description: test program of dlfcn-sample
 * @version: 0.1
 * @Author: Ricardo Lu<shenglu1202@163.com>
 * @Date: 2021-08-07 22:48:59
 * @Last Editor: Ricardo Lu
 * @LastEditTime: 2021-08-08 00:05:15
 */

#include "Interface.h"
#include "DLLoader.h"

typedef void* (*LibMathInit) ();
typedef long long (*LibMathPlus) (void* math, int a, int b);
typedef long long (*LibMathMinus) (void* math, int a, int b);
typedef long long (*LibMathMulti) (void* math, int a, int b);
typedef int (*LibMathDivide) (void* math, int a, int b);

int main(int argc, char *argv[])
{
    char *lib_path = argv[1];

    DLLoader *loader = new DLLoader(lib_path);
    LibMathInit init = loader->GetAPI<LibMathInit> ("init");
    LibMathPlus plus = loader->GetAPI<LibMathPlus> ("plus");
    LibMathMinus minus = loader->GetAPI<LibMathMinus> ("minus");
    LibMathMulti multi = loader->GetAPI<LibMathMulti> ("multi");
    LibMathDivide div = loader->GetAPI<LibMathDivide> ("divide");

    void *math = init();
    plus(math, 4, 2);
    minus(math, 4, 2);
    multi(math, 4, 2);
    div(math, 4, 2);

    return 0;
}
#include <stdio.h>

namespace myname
{
    int var = 42;
}

extern "C" int _ZN6myname3varE;
extern int ext;

int weak;
int strong = 1;
__attribute__((weak)) int weak2 = 2;

int main()
{
    printf("%d\n", _ZN6myname3varE);
    return 0;
}


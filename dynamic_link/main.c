#include "lib.h"

int main()
{
    int i = 0;
    asm(" .symver foobar1_1, foobar@VERS_1.1");
    asm(" .symver foobar1_2, foobar@VERS_1.2");

    foobar1_2(i);
    return 0;
}
#include <stdio.h>

void my_printf(void)
{
    #if DEBUG == 1
        printf("Hello World from Debug Build\n");
    #elif DEBUG == 0
        printf("Hello World from Release Build\n");
    #endif
}
#include "my_sh.h"

int sh_loop()
{
    if (isatty(STDOUT_FILENO)) {
         printf("Welcome to shell!\n");
    }
    return 0;
}
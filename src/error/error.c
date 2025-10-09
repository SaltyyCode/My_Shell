
#include "my_sh.h"

void print_error(const char *str)
{
    write(2, RED, strlen(RED));
    write(2, BOLD, strlen(BOLD));
    write(2, str, strlen(str));
    write(2, RESET, strlen(RESET));
}

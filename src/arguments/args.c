#include "my_sh.h"

void free_args(char **args)
{
    for (int i = 0; args[i]; i++)
        free(args[i]);
    free(args);
}
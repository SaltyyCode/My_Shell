#include "my_sh.h"
#include "env/env.h"

int my_exit(char **args, char ***env)
{
    int code = 0;

    if (args[1])
        code = atoi(args[1]);
    
    free_env(*env);
    free_args(args);
    exit(code);
}
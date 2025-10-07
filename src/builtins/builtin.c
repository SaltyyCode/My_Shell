#include "my_sh.h"

int is_builtin(char *command)
{
    char *builtins[] = {"env", NULL};

    for (int i = 0; builtins[i] != NULL; i++)
    {
        if (strcmp(command, builtins[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int execute_builtin(char **args, char ***env)
{
    if (strcmp(args[0], "env") == 0)
    {
        return (my_env(args, *env));
    }
}


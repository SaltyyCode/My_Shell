#include "builtins/builtins.h"
#include "env/env.h"

int is_builtin(char *command)
{
    char *builtins[] = {"env", "exit", "help", "setenv", NULL};

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
    if (strcmp(args[0], "exit") == 0)
    {
        return (my_exit(args, env));
    }
    if (strcmp(args[0], "help") == 0)
    {
        print_shell_info();
        return 0;
    }
     if (strcmp(args[0], "setenv") == 0)
    {
        return (my_setenv(args, env));
    }
    return 0;
}


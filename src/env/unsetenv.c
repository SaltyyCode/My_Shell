#include "my_sh.h"
#include "env/env.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static int check_unsetenv_args(char **args)
{
    if (!args[1]) {
        print_error("Unsetenv Error: Missing argument\n");
        return 84;
    }

    if (args[2]) {
        print_error("Unsetenv Error: Too many arguments\n");
        return 84;
    }

    return 0;
}

static int find_var_index(char **env, const char *key)
{
    int key_len = strlen(key);

    for (int i = 0; env[i]; i++) {
        if (strncmp(env[i], key, key_len) == 0 && 
            env[i][key_len] == '=') {
            return i;
        }
    }

    return -1;
}

static void remove_var_at_index(char **env, int index)
{
    free(env[index]);

    while (env[index]) {
        env[index] = env[index + 1];
        index++;
    }
}

int my_unsetenv(char **args, char ***env)
{
    if (check_unsetenv_args(args) != 0)
        return 84;

    int index = find_var_index(*env, args[1]);

    if (index == -1)
        return 0;

    remove_var_at_index(*env, index);

    return 0;
}
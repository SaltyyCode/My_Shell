#include "my_sh.h"

int my_env(char **args, char **env)
{
    (void)args;

    for (int i = 0; env[i]; i++)
    {
        write(1, env[i], strlen(env[i]));
        write (1, "\n", 1);
    }
    return 0;
}

char **copy_env(char **env)
{
    int i = 0;
    char **new_env;

    while(env[i])
        i++;
    
    new_env = malloc(sizeof(char *) * (i + 1));
    if (!new_env)
        return NULL;
    
    for (int j= 0; j < i; j++)
    {
        new_env[j] = malloc(strlen(env[j]) + 1);
        strcpy(new_env[j], env[j]);
    }
    new_env[i] = NULL;
    return new_env;
}

void free_env(char **env)
{
    for (int i = 0; env[i]; i++)
    {
        free(env[i]);
    }   
    free(env);
}

char *get_env_value(const char *name, char **env)
{
    int i = 0;
    int len = strlen(name);
    
    while (env[i]) {
        if (strncmp(env[i], name, len) == 0 && env[i][len] == '=') {
            return &env[i][len + 1];
        }
        i++;
    }

    return NULL;
}
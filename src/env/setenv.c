#include "my_sh.h"
#include "env/env.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static int check_setenv_args(char **args)
{
    if (!args[1] || !args[2]) {
        print_error("Setenv Error: Missing args\n");
        return 84;
    }

    if (args[3]) {
        print_error("Setenv Error: too many arguments\n");
        return 84;
    }

    return 0;
}

char *create_env_entry(const char *key, const char *value)
{
    char *new_entry = malloc(strlen(key) + strlen(value) + 2);
    
    if (!new_entry)
        return NULL;

    strcpy(new_entry, key);
    strcat(new_entry, "=");
    strcat(new_entry, value);

    return new_entry;
}

int update_existing_var(char **env, const char *key, char *new_entry)
{
    int key_len = strlen(key);

    for (int i = 0; env[i]; i++) {
        if (strncmp(env[i], key, key_len) == 0 && 
            env[i][key_len] == '=') {
            free(env[i]);
            env[i] = new_entry;
            return 1;
        }
    }

    return 0;
}

 int add_new_var(char ***env, char *new_entry)
{
    int count = 0;
    
    while ((*env)[count])
        count++;

    char **new_env = realloc(*env, sizeof(char *) * (count + 2));
    if (!new_env) {
        free(new_entry);
        return 84;
    }

    new_env[count] = new_entry;
    new_env[count + 1] = NULL;
    *env = new_env;

    return 0;
}

void update_env_var(const char *name, const char *value, char ***env)
{
    char *new_entry = create_env_entry(name, value);
    if (!new_entry)
        return;
    
    if (update_existing_var(*env, name, new_entry))
        return;
    
    add_new_var(env, new_entry);
}

int my_setenv(char **args, char ***env)
{
    if (check_setenv_args(args) != 0)
        return 84;

    char *new_entry = create_env_entry(args[1], args[2]);
    if (!new_entry)
        return 84;

    if (update_existing_var(*env, args[1], new_entry))
        return 0;

    return add_new_var(env, new_entry);
}


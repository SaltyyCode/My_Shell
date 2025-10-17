#include "my_sh.h"
#include "env/env.h"


static char *check_direct_path(char *cmd)
{
    if (cmd[0] == '/' || cmd[0] == '.') {
        if (access(cmd, X_OK) == 0)
            return cmd;
        return NULL;
    }
    return NULL;
}

static char *build_full_path(const char *dir, const char *cmd)
{
    char *full_path;
    
    full_path = malloc(strlen(dir) + strlen(cmd) + 2);
    if (!full_path)
        return NULL;
    
    strcpy(full_path, dir);
    strcat(full_path, "/");
    strcat(full_path, cmd);
    
    return full_path;
}

static char *search_in_path(char *path_copy, char *cmd)
{
    char *dir;
    char *full_path;
    
    dir = strtok(path_copy, ":");
    
    while (dir) {
        full_path = build_full_path(dir, cmd);
        if (!full_path) {
            free(path_copy);
            return NULL;
        }
        
        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return full_path;
        }
        
        free(full_path);
        dir = strtok(NULL, ":");
    }
    
    free(path_copy);
    return NULL;
}

char *find_command(char *cmd, char **env)
{
    char *direct_path;
    char *path_env;
    char *path_copy;
    
    direct_path = check_direct_path(cmd);
    if (direct_path)
        return direct_path;
    
    path_env = get_env_value("PATH", env);
    if (!path_env)
        return NULL;
    
    path_copy = malloc(strlen(path_env) + 1);
    if (!path_copy)
        return NULL;
    
    strcpy(path_copy, path_env);
    
    return search_in_path(path_copy, cmd);
}
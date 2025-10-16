#include "my_sh.h"
#include "env/env.h"

char *get_target_path(char **args, char **env)
{
    if (!args[1]) {
        char *home = get_env_value("HOME", env);
        if (!home) {
            print_error("cd: HOME not set\n");
            return NULL;
        }
        return home;
    }
    if (strcmp(args[1], "-") == 0) {
        char *oldpwd = get_env_value("OLDPWD", env);
        if (!oldpwd) {
            print_error("cd: OLDPWD not set\n");
            return NULL;
        }
        write(1, oldpwd, strlen(oldpwd));
        write(1, "\n", 1);
        return oldpwd;
    }
    return args[1];
}

int my_cd(char **args, char ***env)
{
    char old_pwd[1024];
    char new_pwd[1024];
 
    if (getcwd(old_pwd, sizeof(old_pwd)) == NULL) {
        perror("cd");
        return 84;
    }
    if (args[1] && args[2]) {
        print_error("cd: too many arguments\n");
        return 84;
    }
    char *path = get_target_path(args, *env);
    if (!path)
        return 1;
    
    if (chdir(path) == -1) {
        print_error("chdir: No such file or directory\n");
    }
    getcwd(new_pwd, sizeof(new_pwd));
    update_env_var("OLDPWD", old_pwd, env);
    update_env_var("PWD", new_pwd, env);
    
    return 0;
}
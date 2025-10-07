#include "my_sh.h"

int main(int argc, char **argv, char **envp)
{
    char **env;
    int status;

    (void)argc;
    (void)argv;

    env = copy_env(envp);
    if (!env) {
    write(2, "Error: malloc failed\n", 21);
    return 84;
    }
    
    status = sh_loop(envp);
    free_env(env);
    return status;
}
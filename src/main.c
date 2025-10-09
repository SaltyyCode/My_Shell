#include "my_sh.h"
#include "builtins/builtins.h"
#include "env/env.h"

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
    print_shell_banner_compact(env);
    status = sh_loop(&env);
    free_env(env);
    return status;
}
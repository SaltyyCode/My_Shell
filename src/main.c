#include "my_sh.h"

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    (void)envp;
    sh_loop();
    return (0);
}
#include "my_sh.h"

int sh_loop(char **env)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args;
    int status = 0;
    
    while(1)
    {
        if (isatty(STDOUT_FILENO)){
            write(1, "$> ", 3);
        }
        read = getline(&line, &len, stdin);
        args = parse_line(line);

        if (is_builtin(args[0]))
            status = execute_builtin(args, &env);
    }
    free(line);
    return status;
}
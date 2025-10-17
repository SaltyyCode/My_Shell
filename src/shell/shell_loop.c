#include "my_sh.h"

int sh_loop(char **env)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read_len;
    char **args;
    int status = 0;
    
    while(1)
    {
        if (isatty(STDIN_FILENO)) {
            char *dir = get_current_dir();
            if (dir) {
                dprintf(1, "%s%s%s $> %s", GREEN, dir, RESET, RESET);
                free(dir);
            } else {
                dprintf(1, "%s$> %s", GREEN, RESET);
            }
        }
        read_len = getline(&line, &len, stdin);

        if (read_len == -1) {
            if (isatty(STDIN_FILENO))
                write(1, "\n", 1);
            break;
        }
        args = parse_line(line);

        if (!args || !args[0]) {
            if (args)
                free_args(args);
            continue;
        }
        if (is_builtin(args[0]))
            status = execute_builtin(args, &env);
        else
            status = execute_command(args, env);
        
        free_args(args);
    }
    free(line);
    return status;
}
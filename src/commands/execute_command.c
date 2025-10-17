#include "my_sh.h"

static void print_command_not_found(char *cmd)
{
    write(2, cmd, strlen(cmd));
    write(2, ": Command not found.\n", 21);
}


static void child_process(char *cmd_path, char **args, char **env)
{
    execve(cmd_path, args, env);
    perror(args[0]);
    exit(1);
}

static int wait_child(pid_t pid, char *cmd_path, char **args)
{
    int status;
    (void)args;
    
    waitpid(pid, &status, 0);
    
    if (cmd_path != args[0])
        free(cmd_path);
    
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    
    if (WIFSIGNALED(status))
        return 128 + WTERMSIG(status);
    
    return 0;
}

static int create_child_process(char *cmd_path, char **args, char **env)
{
    pid_t pid;
    
    pid = fork();
    
    if (pid == -1) {
        perror("fork");
        if (cmd_path != args[0])
            free(cmd_path);
        return 1;
    }
    
    if (pid == 0)
        child_process(cmd_path, args, env);
    
    return wait_child(pid, cmd_path, args);
}


int execute_command(char **args, char **env)
{
    char *cmd_path;
    
    cmd_path = find_command(args[0], env);
    
    if (!cmd_path) {
        print_command_not_found(args[0]);
        return 127;
    }
    
    return create_child_process(cmd_path, args, env);
}
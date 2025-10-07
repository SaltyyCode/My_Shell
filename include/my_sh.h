#ifndef MY_SH_H
#define MY_SH_H

// Standard library includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

// Prototypes des builtins
int my_cd(char **args, char ***env);
int my_setenv(char **args, char ***env);
int my_unsetenv(char **args, char ***env);
int my_env(char **args, char **env);
char **copy_env(char **env);
void free_env(char **env);
int my_exit(char **args);

int sh_loop(char **env);

int is_builtin(char *command);
int execute_builtin(char **args, char ***env);

char **parse_line(char *line);

// Structure pour les builtins
typedef struct {
    char *name;
    int (*func)(char **, char ***);
} builtin_t;

#endif // MY_SH_H
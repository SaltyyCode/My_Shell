#ifndef ENV_H
#define ENV_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

int my_setenv(char **args, char ***env);
int my_unsetenv(char **args, char ***env);
int my_env(char **args, char **env);
char **copy_env(char **env);
void free_env(char **env);
char *get_env_value(const char *name, char **env);

#endif // ENV_H
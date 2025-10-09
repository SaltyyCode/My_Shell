#ifndef MY_SH_H
#define MY_SH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <signal.h>
#include <time.h>
#include <pwd.h>
#include "builtins/builtins.h"

#define BOLD "\033[1m"
#define CYAN "\033[0;36m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define RED "\033[0;31m"
#define RESET "\033[0m"


int my_cd(char **args, char ***env);
int my_exit(char **args, char ***env);
void print_error(char const *str);
char *get_current_dir(void);

int sh_loop(char ***env);
void print_shell_banner_compact(char **env);
void  print_shell_info(void);

void free_args(char **args);

char **parse_line(char *line);

#endif // MY_SH_H
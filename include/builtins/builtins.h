#ifndef BUILTINS_H
#define BUILTINS_H

#include <string.h>
#include "my_sh.h"

typedef struct {
    char *name;
    int (*func)(char **, char ***);
} builtin_t;

int is_builtin(char *command);
int execute_builtin(char **args, char ***env);

#endif // BUILTINS_H
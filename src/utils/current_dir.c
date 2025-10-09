#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "my_sh.h"

char *get_current_dir(void)
{
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) == NULL)
        return NULL;

    char *dir = strrchr(cwd, '/');
    dir = (dir) ? dir + 1 : cwd;

    return strdup(dir);
}

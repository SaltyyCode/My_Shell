#include "my_sh.h"

char **parse_line(char *line)
{
    char **args = NULL;
    char *token;
    int count = 0;

    char *line_cp = malloc(strlen(line) + 1);
    strcpy(line_cp, line);
    token = strtok(line_cp, " \t\n");
    
    while(token)
    {
        count++;
        token = strtok(NULL, " \t\n");
    }
    free(line_cp);

    args = malloc(sizeof(char *) * (count + 1));
    count = 0;
    token = strtok(line, " \t\n");

    while(token)
    {
        args[count] = malloc(strlen(token) + 1);
        strcpy(args[count], token);
        count++;
        token = strtok(NULL, " \t\n");
    }
    args[count] = NULL;
    return args;
}
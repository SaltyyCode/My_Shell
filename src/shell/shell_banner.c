#include "my_sh.h"

void print_shell_banner_compact(char **env)
{
    struct passwd *pw;
    char hostname[256];
    char cwd[1024];

    (void)env;
    
    gethostname(hostname, sizeof(hostname));
    pw = getpwuid(getuid());
    getcwd(cwd, sizeof(cwd));
    
    printf("\n");
    printf(BOLD CYAN "╭─ MY_SH ────────────────────────────────╮\n");
    printf(BOLD CYAN "│" RESET);
    printf(" 👤 " GREEN "%s" RESET "@" BLUE "%s" RESET, 
           pw ? pw->pw_name : "unknown", hostname);
    
    int padding = 35 - strlen(pw ? pw->pw_name : "unknown") - strlen(hostname);
    for (int i = 0; i < padding; i++)
        printf(" ");
    
    printf(BOLD CYAN "│\n");
    printf("│" RESET " 📁 %s", cwd);
    
    padding = 36 - strlen(cwd);
    for (int i = 0; i < padding; i++)
        printf(" ");
    
    printf(BOLD CYAN "│\n");
    printf("╰────────────────────────────────────────╯\n" RESET);
    printf("\n");
}

void print_shell_info(void)
{
    printf(BOLD "\nBuilt-in commands:\n" RESET);
    printf("  " GREEN "cd" RESET "        - Change directory\n");
    printf("  " GREEN "env" RESET "       - Display environment\n");
    printf("  " GREEN "setenv" RESET "    - Set environment variable\n");
    printf("  " GREEN "unsetenv" RESET "  - Unset environment variable\n");
    printf("  " GREEN "exit" RESET "      - Exit the shell\n");
    printf("  " GREEN "help" RESET "      - Show this help\n");
    printf("\n");
}
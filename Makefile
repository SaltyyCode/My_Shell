CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
LDFLAGS = 
NAME = my_sh


SRC = src/main.c \
	  src/shell/shell_loop.c \
	  src/shell/shell_banner.c \
	  src/builtins/builtin.c \
	  src/env/env.c \
	  src/env/setenv.c \
	  src/env/unsetenv.c \
	  src/cd/my_cd.c \
	  src/error/error.c \
	  src/parser/parser.c \
	  src/exit/exit.c \
	  src/arguments/args.c \
	  src/utils/current_dir.c \
	  src/commands/execute_command.c \
	  src/commands/find_command.c \

OBJ = $(SRC:.c=.o)


TEST_SRC = tests/test_parser.c \
           tests/test_builtins.c \
           tests/test_env.c \
           tests/test_cd.c \
           tests/test_runner.c

TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_NAME = run_tests


COV_FLAGS = -fprofile-arcs -ftest-coverage
COV_LDFLAGS = --coverage
COV_DIR = coverage


all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


tests: CFLAGS += $(COV_FLAGS)
tests: LDFLAGS += $(COV_LDFLAGS)
tests: clean_cov $(TEST_NAME)
	@echo "\n========== Running Tests =========="
	./$(TEST_NAME)
	@echo "===================================\n"


$(TEST_NAME): $(filter-out src/main.o, $(OBJ)) $(TEST_OBJ)
	$(CC) $(CFLAGS) $^ -o $(TEST_NAME) $(LDFLAGS)


tests/%.o: tests/%.c
	$(CC) $(CFLAGS) $(COV_FLAGS) -c $< -o $@


coverage: tests
	@echo "\n========== Generating Coverage Report =========="
	@mkdir -p $(COV_DIR)
	@echo "Running gcov..."
	@gcov $(SRC) -o . 2>/dev/null || true
	@echo "Running lcov..."
	@lcov --capture --directory . --output-file $(COV_DIR)/coverage.info 2>/dev/null || true
	@lcov --remove $(COV_DIR)/coverage.info '/usr/*' '*/tests/*' --output-file $(COV_DIR)/coverage.info 2>/dev/null || true
	@echo "Generating HTML report..."
	@genhtml $(COV_DIR)/coverage.info --output-directory $(COV_DIR)/html 2>/dev/null || true
	@echo "================================================"
	@echo "Coverage report generated!"
	@echo "Open: $(COV_DIR)/html/index.html"
	@echo "Quick command: firefox $(COV_DIR)/html/index.html &"
	@echo "================================================\n"


coverage-summary: tests
	@echo "\n========== Coverage Summary =========="
	@gcov $(SRC) -o . 2>/dev/null | grep -A 3 "File"
	@echo "======================================\n"


clean:
	@echo "Cleaning object files and coverage data..."
	@rm -f $(OBJ) $(TEST_OBJ)
	@rm -f *.gcda *.gcno *.gcov
	@rm -f src/*.gcda src/*.gcno src/*.gcov
	@rm -f src/shell/*.gcda src/shell/*.gcno src/shell/*.gcov
	@rm -f src/builtins/*.gcda src/builtins/*.gcno src/builtins/*.gcov
	@rm -f src/env/*.gcda src/env/*.gcno src/env/*.gcov
	@rm -f src/parser/*.gcda src/parser/*.gcno src/parser/*.gcov
	@rm -f src/cd/*.gcda src/cd/*.gcno src/cd/*.gcov
	@rm -f src/exit/*.gcda src/exit/*.gcno src/exit/*.gcov
	@rm -f src/arguments/*.gcda src/arguments/*.gcno src/arguments/*.gcov
	@rm -f src/error/*.gcda src/error/*.gcno src/error/*.gcov
	@rm -f src/utils/*.gcda src/utils/*.gcno src/utils/*.gcov
	@rm -f tests/*.gcda tests/*.gcno tests/*.gcov
	@echo "Clean done!"


clean_cov:
	@rm -f src/*.gcda src/*.gcno src/*.gcov
	@rm -f src/shell/*.gcda src/shell/*.gcno src/shell/*.gcov
	@rm -f src/builtins/*.gcda src/builtins/*.gcno src/builtins/*.gcov
	@rm -f src/env/*.gcda src/env/*.gcno src/env/*.gcov
	@rm -f src/parser/*.gcda src/parser/*.gcno src/parser/*.gcov
	@rm -f src/cd/*.gcda src/cd/*.gcno src/cd/*.gcov
	@rm -f src/exit/*.gcda src/exit/*.gcno src/exit/*.gcov
	@rm -f src/arguments/*.gcda src/arguments/*.gcno src/arguments/*.gcov
	@rm -f src/error/*.gcda src/error/*.gcno src/error/*.gcov
	@rm -f src/utils/*.gcda src/utils/*.gcno src/utils/*.gcov
	@rm -f tests/*.gcda tests/*.gcno tests/*.gcov
	@rm -f *.gcda *.gcno *.gcov
	@rm -rf $(COV_DIR)


fclean: clean
	@echo "Removing binaries and coverage reports..."
	@rm -f $(NAME) $(TEST_NAME)
	@rm -rf $(COV_DIR)
	@echo "Full clean done!"

re: fclean all


help:
	@echo "=========================================="
	@echo "My_SH Makefile - Available targets:"
	@echo "=========================================="
	@echo "  make              - Compile the shell"
	@echo "  make tests        - Run unit tests with coverage"
	@echo "  make coverage     - Generate HTML coverage report"
	@echo "  make coverage-summary - Show coverage in terminal"
	@echo "  make clean        - Remove object files"
	@echo "  make fclean       - Remove all generated files"
	@echo "  make re           - Recompile everything"
	@echo "  make help         - Show this help"
	@echo "=========================================="

.PHONY: all clean fclean re tests coverage coverage-summary clean_cov help
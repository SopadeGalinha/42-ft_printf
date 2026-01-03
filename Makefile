.SILENT:

NAME	= libftprintf.a
SRCS	= ft_printf.c parsing.c conversions_csp.c conversions_diux.c \
		conversions_hex.c conversions_box.c conversions_utils.c \
		print_utils.c utils.c flags_utils.c
OBJS	= $(SRCS:.c=.o)

TEST_DIR	= tests
MANDATORY_TEST	= $(TEST_DIR)/mandatory/ft_printf_mandatory_tests
BONUS_TEST	= $(TEST_DIR)/bonus/ft_printf_bonus_tests

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
AR	= ar
RM	= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)
	printf "Archive ready -> $(NAME)\n"

bonus: $(NAME)

$(MANDATORY_TEST): $(TEST_DIR)/mandatory/test_ft_printf_mandatory.c $(TEST_DIR)/mandatory/test_d.c $(TEST_DIR)/mandatory/test_c.c $(TEST_DIR)/mandatory/test_s.c $(TEST_DIR)/mandatory/test_u.c $(TEST_DIR)/mandatory/test_x.c $(TEST_DIR)/mandatory/test_o.c $(TEST_DIR)/mandatory/test_b.c $(TEST_DIR)/mandatory/test_i.c $(TEST_DIR)/mandatory/test_p.c $(TEST_DIR)/mandatory/test_mixed.c $(TEST_DIR)/mandatory/test_runner_utils.c $(TEST_DIR)/test_utils.c $(TEST_DIR)/test_utils.h $(NAME)
	$(CC) $(CFLAGS) -Wno-format -I. -I$(TEST_DIR) \
		$(TEST_DIR)/mandatory/test_ft_printf_mandatory.c $(TEST_DIR)/mandatory/test_d.c $(TEST_DIR)/mandatory/test_c.c $(TEST_DIR)/mandatory/test_s.c $(TEST_DIR)/mandatory/test_u.c $(TEST_DIR)/mandatory/test_x.c $(TEST_DIR)/mandatory/test_o.c $(TEST_DIR)/mandatory/test_b.c $(TEST_DIR)/mandatory/test_i.c $(TEST_DIR)/mandatory/test_p.c $(TEST_DIR)/mandatory/test_mixed.c $(TEST_DIR)/mandatory/test_runner_utils.c $(TEST_DIR)/test_utils.c \
		-L. -lftprintf -o $@

$(BONUS_TEST): $(TEST_DIR)/bonus/test_ft_printf_bonus.c $(TEST_DIR)/bonus/test_bonus_flags.c $(TEST_DIR)/bonus/test_bonus_mixed.c $(TEST_DIR)/bonus/test_bonus_comprehensive.c $(TEST_DIR)/bonus/test_rigorous.c $(TEST_DIR)/bonus/bonus_runner_utils.c $(TEST_DIR)/test_utils.c $(TEST_DIR)/test_utils.h $(NAME)
	$(CC) $(CFLAGS) -Wno-format -I. -I$(TEST_DIR) \
		$(TEST_DIR)/bonus/test_ft_printf_bonus.c $(TEST_DIR)/bonus/test_bonus_flags.c $(TEST_DIR)/bonus/test_bonus_mixed.c $(TEST_DIR)/bonus/test_bonus_comprehensive.c $(TEST_DIR)/bonus/test_rigorous.c $(TEST_DIR)/bonus/bonus_runner_utils.c $(TEST_DIR)/test_utils.c \
		-L. -lftprintf -o $@

test-mandatory: $(MANDATORY_TEST)
	@$(MANDATORY_TEST)

test-bonus: $(BONUS_TEST)
	@$(BONUS_TEST)

test: test-mandatory test-bonus
	@printf "\nAll test suites finished.\n"

help:
	@printf "\n\033[1m=== FT_PRINTF Makefile Help ===\033[0m\n\n"
	@printf "\033[1mCore Targets:\033[0m\n"
	@printf "  \033[36mall\033[0m              Build the library (default)\n"
	@printf "  \033[36mbonus\033[0m            Build with bonus flags support\n"
	@printf "  \033[36mre\033[0m               Rebuild from scratch (fclean + all)\n\n"
	@printf "\033[1mTesting:\033[0m\n"
	@printf "  \033[36mtest\033[0m             Run all tests (mandatory + bonus)\n"
	@printf "  \033[36mtest-mandatory\033[0m  Run only mandatory format tests\n"
	@printf "  \033[36mtest-bonus\033[0m      Run all bonus and edge case tests\n\n"
	@printf "\033[1mCleaning:\033[0m\n"
	@printf "  \033[36mclean\033[0m           Remove object files\n"
	@printf "  \033[36mclean-tests\033[0m    Remove compiled test binaries\n"
	@printf "  \033[36mfclean\033[0m          Full clean (objects, tests, and library)\n\n"
	@printf "\033[1mTest Coverage:\033[0m\n"
	@printf "  • Mandatory: 380 tests across 10 format specifiers\n"
	@printf "  • Bonus: 168 tests including edge cases, limits, and * flag\n"
	@printf "  • Total: 548 comprehensive tests\n\n"

clean:
	$(RM) $(OBJS)
	printf "Object files removed.\n"

clean-tests:
	$(RM) $(MANDATORY_TEST) $(BONUS_TEST)
	printf "Test binaries removed.\n"

fclean: clean clean-tests
	$(RM) $(NAME)
	printf "Library removed.\n"

re: fclean all

.PHONY: all bonus test test-mandatory test-bonus clean clean-tests fclean re help

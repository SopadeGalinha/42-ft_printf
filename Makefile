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

$(MANDATORY_TEST): $(TEST_DIR)/mandatory/test_ft_printf_mandatory.c $(TEST_DIR)/test_utils.c $(TEST_DIR)/test_utils.h $(NAME)
	$(CC) $(CFLAGS) -I. -I$(TEST_DIR) \
		$(TEST_DIR)/mandatory/test_ft_printf_mandatory.c $(TEST_DIR)/test_utils.c \
		-L. -lftprintf -o $@

$(BONUS_TEST): $(TEST_DIR)/bonus/test_ft_printf_bonus.c $(TEST_DIR)/test_utils.c $(TEST_DIR)/test_utils.h $(NAME)
	$(CC) $(CFLAGS) -I. -I$(TEST_DIR) \
		$(TEST_DIR)/bonus/test_ft_printf_bonus.c $(TEST_DIR)/test_utils.c \
		-L. -lftprintf -o $@

test-mandatory: $(MANDATORY_TEST)
	@$(MANDATORY_TEST)

test-bonus: $(BONUS_TEST)
	@$(BONUS_TEST)

test: test-mandatory test-bonus
	@printf "\nAll test suites finished.\n"

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

.PHONY: all bonus test test-mandatory test-bonus clean clean-tests fclean re

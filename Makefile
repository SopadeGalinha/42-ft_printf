.SILENT:

MANDATORY_DIR	= mandatory
BONUS_DIR	= bonus
TEST_DIR	= tests

MANDATORY_LIB	= $(MANDATORY_DIR)/libftprintf.a
BONUS_LIB	= $(BONUS_DIR)/libftprintf.a

MANDATORY_TEST	= $(TEST_DIR)/mandatory/ft_printf_mandatory_tests
BONUS_TEST	= $(TEST_DIR)/bonus/ft_printf_bonus_tests

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

all: test

$(MANDATORY_LIB):
	$(MAKE) -C $(MANDATORY_DIR) all

$(BONUS_LIB):
	$(MAKE) -C $(BONUS_DIR) bonus

$(MANDATORY_TEST): $(TEST_DIR)/mandatory/test_ft_printf_mandatory.c $(TEST_DIR)/test_utils.c $(TEST_DIR)/test_utils.h $(MANDATORY_LIB)
	$(CC) $(CFLAGS) -I$(TEST_DIR) -I$(MANDATORY_DIR) $(TEST_DIR)/mandatory/test_ft_printf_mandatory.c \
		$(TEST_DIR)/test_utils.c -L$(MANDATORY_DIR) -lftprintf -o $@

$(BONUS_TEST): $(TEST_DIR)/bonus/test_ft_printf_bonus.c $(TEST_DIR)/test_utils.c $(TEST_DIR)/test_utils.h $(BONUS_LIB)
	$(CC) $(CFLAGS) -I$(TEST_DIR) -I$(BONUS_DIR) $(TEST_DIR)/bonus/test_ft_printf_bonus.c \
		$(TEST_DIR)/test_utils.c -L$(BONUS_DIR) -lftprintf -o $@

test-mandatory: $(MANDATORY_TEST)
	@$(MANDATORY_TEST)

test-bonus: $(BONUS_TEST)
	@$(BONUS_TEST)

test: test-mandatory test-bonus
	@printf "\nAll test suites finished.\n"

clean-tests:
	@rm -f $(MANDATORY_TEST) $(BONUS_TEST)

fclean: clean-tests
	@$(MAKE) -C $(MANDATORY_DIR) fclean
	@$(MAKE) -C $(BONUS_DIR) fclean

re: fclean test

.PHONY: all test test-mandatory test-bonus clean-tests fclean re

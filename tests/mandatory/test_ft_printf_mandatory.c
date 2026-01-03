#include "../../ft_printf.h"
#include "../test_utils.h"

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

typedef struct s_test_case
{
	const char	*name;
	int		(*ft_fn)(void);
	int		(*std_fn)(void);
} t_test_case;

static int	sample_function(int x)
{
	return (x + 1);
}

#define DEFINE_TEST(NAME, ...) \
	static int NAME##_ft(void) { return ft_printf(__VA_ARGS__); } \
	static int NAME##_std(void) { return printf(__VA_ARGS__); }

static int	g_dummy = 123;
static int	g_other = -456;

DEFINE_TEST(test_plain_text, "Hello, world!")
static int test_empty_format_ft(void)
{
	const char *fmt = "";
	return ft_printf(fmt);
}

static int test_empty_format_std(void)
{
	const char *fmt = "";
	return printf("%s", fmt);
}

DEFINE_TEST(test_percent_only, "%%")
DEFINE_TEST(test_char_basic, "%c", 'A')
DEFINE_TEST(test_char_null, "Char:%cEnd", '\0')
DEFINE_TEST(test_string_basic, "string: %s", "libft")
DEFINE_TEST(test_string_empty, "empty: '%s'", "")
static int test_string_null_ft(void)
{
	char *p = NULL;
	return ft_printf("null string: %s", p);
}

static int test_string_null_std(void)
{
	char *p = NULL;
	return printf("null string: %s", p);
}
DEFINE_TEST(test_decimal_positive, "number: %d", 42)
DEFINE_TEST(test_decimal_negative, "number: %d", -42)
DEFINE_TEST(test_decimal_zero, "%d", 0)
DEFINE_TEST(test_decimal_intmin, "%d", INT_MIN)
DEFINE_TEST(test_int_multiple, "%d %i %d", 1, 0, -1)
DEFINE_TEST(test_unsigned_basic, "u:%u", 42u)
DEFINE_TEST(test_unsigned_zero, "u:%u", 0u)
DEFINE_TEST(test_unsigned_max, "u:%u", UINT_MAX)
DEFINE_TEST(test_hex_lower_basic, "x:%x", 0xabcdef)
DEFINE_TEST(test_hex_upper_basic, "X:%X", 0xABCDEF)
DEFINE_TEST(test_hex_zero, "x:%x", 0)
DEFINE_TEST(test_pointer_null, "p:%p", (void *)0)
DEFINE_TEST(test_pointer_global, "p:%p", (void *)&g_dummy)
DEFINE_TEST(test_pointer_function, "p:%p", (void *)&sample_function)
DEFINE_TEST(test_mix_string_char, "%s %c", "abc", 'Z')
DEFINE_TEST(test_mix_multi, "d:%d s:%s c:%c x:%x", -12, "abc", 'Z', 255)
DEFINE_TEST(test_percent_with_number, "%% %d", 123)
DEFINE_TEST(test_long_text_numbers, "n:%u hex:%x", 123456789u, 0x7fffffff)
DEFINE_TEST(test_multiple_percents, "%%%c%%", 'A')
DEFINE_TEST(test_hex_upper_max, "%X", UINT_MAX)
DEFINE_TEST(test_hex_lower_large, "%x", 0xdeadbeef)
DEFINE_TEST(test_pointer_stack, "stack %p", (void *)&g_other)
DEFINE_TEST(test_string_spaces, "  %s  ", " spaced ")
DEFINE_TEST(test_newline_char, "nl:%c", '\n')
DEFINE_TEST(test_tab_char, "tab:%c", '\t')
DEFINE_TEST(test_string_with_percent, "fmt %s %% %d", "value", 7)
DEFINE_TEST(test_mixed_signed_unsigned, "%i %u %d", -1, 3000000000u, -1)
DEFINE_TEST(test_pointer_pair, "%p %p", (void *)0, (void *)&g_dummy)
DEFINE_TEST(test_hex_multiple, "%x %X", 4095, 4095)
DEFINE_TEST(test_unsigned_large, "%u", 4000000000u)
DEFINE_TEST(test_decimal_mixed_signs, "%d %d %d", -100, 100, -200)
DEFINE_TEST(test_string_long, "Lorem ipsum %d %s %x", 73, "dolor", 0xdeadbeef)

static int	run_single_test(const t_test_case *tc, FILE *err)
{
	char	*ft_output;
	char	*std_output;
	int		ft_len;
	int		std_len;
	int		ft_ret;
	int		std_ret;
	int		ok;

	ft_output = NULL;
	std_output = NULL;
	ft_len = 0;
	std_len = 0;
	ft_ret = capture_output(tc->ft_fn, &ft_output, &ft_len);
	std_ret = capture_output(tc->std_fn, &std_output, &std_len);
	ok = (ft_ret == std_ret) && (ft_len == std_len) && ft_ret != -1 && std_ret != -1
		&& ft_output && std_output
		&& memcmp(ft_output, std_output, ft_len) == 0;
	printf("%-40s %s%s%s\n", tc->name, ok ? GREEN : RED, ok ? "OK" : "KO", RESET);
	if (!ok)
	{
		write_mismatch(err, tc->name, std_output, std_len, std_ret,
			ft_output, ft_len, ft_ret);
	}
	free(ft_output);
	free(std_output);
	return (ok);
}

int	main(void)
{
	size_t		index;
	size_t		passed;
	size_t		total;
	FILE		*err;
	const t_test_case tests[] = {
		{"plain text", test_plain_text_ft, test_plain_text_std},
		{"empty format", test_empty_format_ft, test_empty_format_std},
		{"percent only", test_percent_only_ft, test_percent_only_std},
		{"char basic", test_char_basic_ft, test_char_basic_std},
		{"char null", test_char_null_ft, test_char_null_std},
		{"string basic", test_string_basic_ft, test_string_basic_std},
		{"string empty", test_string_empty_ft, test_string_empty_std},
		{"string null", test_string_null_ft, test_string_null_std},
		{"decimal positive", test_decimal_positive_ft, test_decimal_positive_std},
		{"decimal negative", test_decimal_negative_ft, test_decimal_negative_std},
		{"decimal zero", test_decimal_zero_ft, test_decimal_zero_std},
		{"decimal INT_MIN", test_decimal_intmin_ft, test_decimal_intmin_std},
		{"int multiple", test_int_multiple_ft, test_int_multiple_std},
		{"unsigned basic", test_unsigned_basic_ft, test_unsigned_basic_std},
		{"unsigned zero", test_unsigned_zero_ft, test_unsigned_zero_std},
		{"unsigned max", test_unsigned_max_ft, test_unsigned_max_std},
		{"hex lower basic", test_hex_lower_basic_ft, test_hex_lower_basic_std},
		{"hex upper basic", test_hex_upper_basic_ft, test_hex_upper_basic_std},
		{"hex zero", test_hex_zero_ft, test_hex_zero_std},
		{"pointer null", test_pointer_null_ft, test_pointer_null_std},
		{"pointer global", test_pointer_global_ft, test_pointer_global_std},
		{"pointer function", test_pointer_function_ft, test_pointer_function_std},
		{"mix string char", test_mix_string_char_ft, test_mix_string_char_std},
		{"mix multiple", test_mix_multi_ft, test_mix_multi_std},
		{"percent with number", test_percent_with_number_ft, test_percent_with_number_std},
		{"long numbers", test_long_text_numbers_ft, test_long_text_numbers_std},
		{"multiple percents", test_multiple_percents_ft, test_multiple_percents_std},
		{"hex upper max", test_hex_upper_max_ft, test_hex_upper_max_std},
		{"hex lower large", test_hex_lower_large_ft, test_hex_lower_large_std},
		{"pointer stack", test_pointer_stack_ft, test_pointer_stack_std},
		{"string spaces", test_string_spaces_ft, test_string_spaces_std},
		{"newline char", test_newline_char_ft, test_newline_char_std},
		{"tab char", test_tab_char_ft, test_tab_char_std},
		{"string with percent", test_string_with_percent_ft, test_string_with_percent_std},
		{"mixed signed unsigned", test_mixed_signed_unsigned_ft, test_mixed_signed_unsigned_std},
		{"pointer pair", test_pointer_pair_ft, test_pointer_pair_std},
		{"hex multiple", test_hex_multiple_ft, test_hex_multiple_std},
		{"unsigned large", test_unsigned_large_ft, test_unsigned_large_std},
		{"decimal mixed signs", test_decimal_mixed_signs_ft, test_decimal_mixed_signs_std},
		{"string long", test_string_long_ft, test_string_long_std}
	};

	total = sizeof(tests) / sizeof(tests[0]);
	passed = 0;
	index = 0;
	err = open_error_file("tests/errors_mandatory.log");
	if (!err)
		fprintf(stderr, "Warning: could not open tests/errors_mandatory.log; errors will not be logged.\n");
	while (index < total)
	{
		passed += run_single_test(&tests[index], err ? err : stderr);
		index++;
	}
	if (err)
		fclose(err);
	printf("\nSummary: %s%zu/%zu passed%s\n", passed == total ? GREEN : RED, passed, total, RESET);
	return (passed == total ? 0 : 1);
}

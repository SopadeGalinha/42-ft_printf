#include "../../bonus/ft_printf.h"
#include "../test_utils.h"

#include <limits.h>
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

#define DEFINE_TEST(NAME, ...) \
	static int NAME##_ft(void) { return ft_printf(__VA_ARGS__); } \
	static int NAME##_std(void) { return printf(__VA_ARGS__); }

static long	g_bonus_dummy = 123456789L;

DEFINE_TEST(test_width_string_right, "%10s", "hi")
DEFINE_TEST(test_width_string_left, "%-10s", "hi")
DEFINE_TEST(test_string_precision, "%.3s", "truncate")
DEFINE_TEST(test_string_precision_zero, "%.0s", "hidden")
DEFINE_TEST(test_char_width, "%5c", 'A')
DEFINE_TEST(test_char_left_width, "%-5c", 'A')
DEFINE_TEST(test_int_zero_pad, "%05d", 42)
DEFINE_TEST(test_int_left_align, "%-5d", 42)
DEFINE_TEST(test_int_plus_positive, "%+d", 42)
DEFINE_TEST(test_int_plus_negative, "%+d", -42)
DEFINE_TEST(test_int_space_positive, "% d", 42)
DEFINE_TEST(test_int_space_negative, "% d", -42)
DEFINE_TEST(test_int_width_precision, "%8.4d", 42)
DEFINE_TEST(test_int_width_precision_zero, "%8.0d", 0)
DEFINE_TEST(test_int_zero_negative, "%05d", -7)
DEFINE_TEST(test_unsigned_zero_pad, "%08u", 30000u)
DEFINE_TEST(test_hex_hash_lower, "%#x", 255)
DEFINE_TEST(test_hex_hash_upper, "%#X", 255)
DEFINE_TEST(test_hex_hash_zero, "%#x", 0u)
DEFINE_TEST(test_hex_zero_pad, "%08x", 0xBEEF)
DEFINE_TEST(test_hex_left_hash, "%-#8x", 0xABCD)
DEFINE_TEST(test_hex_zero_hash, "%#08x", 0xABCD)
DEFINE_TEST(test_pointer_width, "%20p", (void *)&g_bonus_dummy)
DEFINE_TEST(test_pointer_null_width, "%10p", (void *)0)
static int test_percent_width_ft(void)
{
	return ft_printf("%5%");
}

static int test_percent_width_std(void)
{
	/* mimic width on literal percent using width + char to avoid format warning */
	return printf("%*c", 5, '%');
}

static int test_space_plus_combo_ft(void)
{
	return ft_printf("% +d", 7);
}

static int test_space_plus_combo_std(void)
{
	/* space is ignored when plus is present; use %+d to avoid warning */
	return printf("%+d", 7);
}
DEFINE_TEST(test_star_width_positive, "%*d", 6, 42)
DEFINE_TEST(test_star_width_negative, "%*d", -6, 42)
DEFINE_TEST(test_plus_zero_value, "%+i", 0)
DEFINE_TEST(test_space_zero_value, "% i", 0)

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
		{"width string right", test_width_string_right_ft, test_width_string_right_std},
		{"width string left", test_width_string_left_ft, test_width_string_left_std},
		{"string precision", test_string_precision_ft, test_string_precision_std},
		{"string precision zero", test_string_precision_zero_ft, test_string_precision_zero_std},
		{"char width", test_char_width_ft, test_char_width_std},
		{"char left width", test_char_left_width_ft, test_char_left_width_std},
		{"int zero pad", test_int_zero_pad_ft, test_int_zero_pad_std},
		{"int left align", test_int_left_align_ft, test_int_left_align_std},
		{"int plus positive", test_int_plus_positive_ft, test_int_plus_positive_std},
		{"int plus negative", test_int_plus_negative_ft, test_int_plus_negative_std},
		{"int space positive", test_int_space_positive_ft, test_int_space_positive_std},
		{"int space negative", test_int_space_negative_ft, test_int_space_negative_std},
		{"int width precision", test_int_width_precision_ft, test_int_width_precision_std},
		{"int width precision zero", test_int_width_precision_zero_ft, test_int_width_precision_zero_std},
		{"int zero negative", test_int_zero_negative_ft, test_int_zero_negative_std},
		{"unsigned zero pad", test_unsigned_zero_pad_ft, test_unsigned_zero_pad_std},
		{"hex hash lower", test_hex_hash_lower_ft, test_hex_hash_lower_std},
		{"hex hash upper", test_hex_hash_upper_ft, test_hex_hash_upper_std},
		{"hex hash zero", test_hex_hash_zero_ft, test_hex_hash_zero_std},
		{"hex zero pad", test_hex_zero_pad_ft, test_hex_zero_pad_std},
		{"hex left hash", test_hex_left_hash_ft, test_hex_left_hash_std},
		{"hex zero hash", test_hex_zero_hash_ft, test_hex_zero_hash_std},
		{"pointer width", test_pointer_width_ft, test_pointer_width_std},
		{"pointer null width", test_pointer_null_width_ft, test_pointer_null_width_std},
		{"percent width", test_percent_width_ft, test_percent_width_std},
		{"space plus combo", test_space_plus_combo_ft, test_space_plus_combo_std},
		{"star width positive", test_star_width_positive_ft, test_star_width_positive_std},
		{"star width negative", test_star_width_negative_ft, test_star_width_negative_std},
		{"plus zero value", test_plus_zero_value_ft, test_plus_zero_value_std},
		{"space zero value", test_space_zero_value_ft, test_space_zero_value_std}
	};

	total = sizeof(tests) / sizeof(tests[0]);
	passed = 0;
	index = 0;
	err = open_error_file("tests/errors_bonus.log");
	if (!err)
		fprintf(stderr, "Warning: could not open tests/errors_bonus.log; errors will not be logged.\n");
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

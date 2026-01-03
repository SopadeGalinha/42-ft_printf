#include "tests.h"
#include "../../ft_printf.h"
#include <stdio.h>
#include <limits.h>

// ========== BASIC TESTS ==========
static int	d_basic1_ft(void) { return ft_printf("%d", 0); }
static int	d_basic1_std(void) { return printf("%d", 0); }

static int	d_basic2_ft(void) { return ft_printf("%d", 1); }
static int	d_basic2_std(void) { return printf("%d", 1); }

static int	d_basic3_ft(void) { return ft_printf("%d", -1); }
static int	d_basic3_std(void) { return printf("%d", -1); }

static int	d_basic4_ft(void) { return ft_printf("%d", 42); }
static int	d_basic4_std(void) { return printf("%d", 42); }

static int	d_basic5_ft(void) { return ft_printf("%d", -42); }
static int	d_basic5_std(void) { return printf("%d", -42); }

// ========== POSITIVE NUMBERS ==========
static int	d_pos1_ft(void) { return ft_printf("%d", 9); }
static int	d_pos1_std(void) { return printf("%d", 9); }

static int	d_pos2_ft(void) { return ft_printf("%d", 99); }
static int	d_pos2_std(void) { return printf("%d", 99); }

static int	d_pos3_ft(void) { return ft_printf("%d", 123); }
static int	d_pos3_std(void) { return printf("%d", 123); }

static int	d_pos4_ft(void) { return ft_printf("%d", 1234567); }
static int	d_pos4_std(void) { return printf("%d", 1234567); }

static int	d_pos5_ft(void) { return ft_printf("%d", 999999); }
static int	d_pos5_std(void) { return printf("%d", 999999); }

// ========== NEGATIVE NUMBERS ==========
static int	d_neg1_ft(void) { return ft_printf("%d", -9); }
static int	d_neg1_std(void) { return printf("%d", -9); }

static int	d_neg2_ft(void) { return ft_printf("%d", -99); }
static int	d_neg2_std(void) { return printf("%d", -99); }

static int	d_neg3_ft(void) { return ft_printf("%d", -123); }
static int	d_neg3_std(void) { return printf("%d", -123); }

static int	d_neg4_ft(void) { return ft_printf("%d", -1234567); }
static int	d_neg4_std(void) { return printf("%d", -1234567); }

static int	d_neg5_ft(void) { return ft_printf("%d", -999999); }
static int	d_neg5_std(void) { return printf("%d", -999999); }

// ========== POWERS OF 10 ==========
static int	d_pow1_ft(void) { return ft_printf("%d", 10); }
static int	d_pow1_std(void) { return printf("%d", 10); }

static int	d_pow2_ft(void) { return ft_printf("%d", 100); }
static int	d_pow2_std(void) { return printf("%d", 100); }

static int	d_pow3_ft(void) { return ft_printf("%d", 1000); }
static int	d_pow3_std(void) { return printf("%d", 1000); }

static int	d_pow4_ft(void) { return ft_printf("%d", 10000); }
static int	d_pow4_std(void) { return printf("%d", 10000); }

static int	d_pow5_ft(void) { return ft_printf("%d", 100000); }
static int	d_pow5_std(void) { return printf("%d", 100000); }

// ========== BOUNDARY VALUES ==========
static int	d_bound1_ft(void) { return ft_printf("%d", INT_MAX); }
static int	d_bound1_std(void) { return printf("%d", INT_MAX); }

static int	d_bound2_ft(void) { return ft_printf("%d", INT_MIN); }
static int	d_bound2_std(void) { return printf("%d", INT_MIN); }

static int	d_bound3_ft(void) { return ft_printf("%d", 2147483647); }
static int	d_bound3_std(void) { return printf("%d", 2147483647); }

static int	d_bound4_ft(void) { return ft_printf("%d", (int)-2147483648); }
static int	d_bound4_std(void) { return printf("%d", (int)-2147483648); }

static int	d_bound5_ft(void) { return ft_printf("%d", 0); }
static int	d_bound5_std(void) { return printf("%d", 0); }

// ========== NEAR BOUNDARY ==========
static int	d_near1_ft(void) { return ft_printf("%d", INT_MAX - 1); }
static int	d_near1_std(void) { return printf("%d", INT_MAX - 1); }

static int	d_near2_ft(void) { return ft_printf("%d", INT_MIN + 1); }
static int	d_near2_std(void) { return printf("%d", INT_MIN + 1); }

static int	d_near3_ft(void) { return ft_printf("%d", INT_MAX - 100); }
static int	d_near3_std(void) { return printf("%d", INT_MAX - 100); }

static int	d_near4_ft(void) { return ft_printf("%d", INT_MIN + 100); }
static int	d_near4_std(void) { return printf("%d", INT_MIN + 100); }

static int	d_near5_ft(void) { return ft_printf("%d", 1); }
static int	d_near5_std(void) { return printf("%d", 1); }

// ========== MIXED WITH TEXT ==========
static int	d_text1_ft(void) { return ft_printf("Value: %d", 42); }
static int	d_text1_std(void) { return printf("Value: %d", 42); }

static int	d_text2_ft(void) { return ft_printf("Value: %d End", -42); }
static int	d_text2_std(void) { return printf("Value: %d End", -42); }

static int	d_text3_ft(void) { return ft_printf("Start %d Middle %d End", 100, -100); }
static int	d_text3_std(void) { return printf("Start %d Middle %d End", 100, -100); }

static int	d_text4_ft(void) { return ft_printf("num: %d!", 42); }
static int	d_text4_std(void) { return printf("num: %d!", 42); }

static int	d_text5_ft(void) { return ft_printf("  %d  ", 0); }
static int	d_text5_std(void) { return printf("  %d  ", 0); }

// ========== MULTIPLE %d %d ==========
static int	d_multi1_ft(void) { return ft_printf("%d %d %d", 1, -1, 0); }
static int	d_multi1_std(void) { return printf("%d %d %d", 1, -1, 0); }

static int	d_multi2_ft(void) { return ft_printf("%d %d %d %d", INT_MAX, INT_MIN, 0, 42); }
static int	d_multi2_std(void) { return printf("%d %d %d %d", INT_MAX, INT_MIN, 0, 42); }

static int	d_multi3_ft(void) { return ft_printf("%d %d %d %d %d %d %d %d %d %d", 1, 2, 3, 4, 5, -1, -2, -3, -4, -5); }
static int	d_multi3_std(void) { return printf("%d %d %d %d %d %d %d %d %d %d", 1, 2, 3, 4, 5, -1, -2, -3, -4, -5); }

static int	d_multi4_ft(void) { return ft_printf("%d%d%d", 111, 222, 333); }
static int	d_multi4_std(void) { return printf("%d%d%d", 111, 222, 333); }

static int	d_multi5_ft(void) { return ft_printf("%d %d %d %d", 42, 42, 42, 42); }
static int	d_multi5_std(void) { return printf("%d %d %d %d", 42, 42, 42, 42); }

// ========== MIXED WITH %c ==========
static int	d_char1_ft(void) { return ft_printf("%d %c %d", 42, 'A', -42); }
static int	d_char1_std(void) { return printf("%d %c %d", 42, 'A', -42); }

static int	d_char2_ft(void) { return ft_printf("%c %d %c", 'X', 123, 'Y'); }
static int	d_char2_std(void) { return printf("%c %d %c", 'X', 123, 'Y'); }

static int	d_char3_ft(void) { return ft_printf("%d%c%d", 1, 'M', 2); }
static int	d_char3_std(void) { return printf("%d%c%d", 1, 'M', 2); }

static int	d_char4_ft(void) { return ft_printf("%d %c %d %c %d %c", 1, 'a', 2, 'b', 3, 'c'); }
static int	d_char4_std(void) { return printf("%d %c %d %c %d %c", 1, 'a', 2, 'b', 3, 'c'); }

static int	d_char5_ft(void) { return ft_printf("%d", (int)'A'); }
static int	d_char5_std(void) { return printf("%d", (int)'A'); }

// ========== SPECIAL CASES ==========
static int	d_spec1_ft(void) { return ft_printf("Line1\n%d\nLine3", 999); }
static int	d_spec1_std(void) { return printf("Line1\n%d\nLine3", 999); }

static int	d_spec2_ft(void) { return ft_printf("Tab\t%d\tEnd", -55); }
static int	d_spec2_std(void) { return printf("Tab\t%d\tEnd", -55); }

static int	d_spec3_ft(void) { return ft_printf("100%% is %d", 100); }
static int	d_spec3_std(void) { return printf("100%% is %d", 100); }

static int	d_spec4_ft(void) { return ft_printf("The answer is %d", 42); }
static int	d_spec4_std(void) { return printf("The answer is %d", 42); }

static int	d_spec5_ft(void) { return ft_printf("%d %d %d %d %d", -1, 1, -2, 2, 0); }
static int	d_spec5_std(void) { return printf("%d %d %d %d %d", -1, 1, -2, 2, 0); }


void	run_d_tests(void)
{
	t_test_case	basic[] = {
		{d_basic1_ft, d_basic1_std},
		{d_basic2_ft, d_basic2_std},
		{d_basic3_ft, d_basic3_std},
		{d_basic4_ft, d_basic4_std},
		{d_basic5_ft, d_basic5_std},
	};

	t_test_case	positive[] = {
		{d_pos1_ft, d_pos1_std},
		{d_pos2_ft, d_pos2_std},
		{d_pos3_ft, d_pos3_std},
		{d_pos4_ft, d_pos4_std},
		{d_pos5_ft, d_pos5_std},
	};

	t_test_case	negative[] = {
		{d_neg1_ft, d_neg1_std},
		{d_neg2_ft, d_neg2_std},
		{d_neg3_ft, d_neg3_std},
		{d_neg4_ft, d_neg4_std},
		{d_neg5_ft, d_neg5_std},
	};

	t_test_case	powers[] = {
		{d_pow1_ft, d_pow1_std},
		{d_pow2_ft, d_pow2_std},
		{d_pow3_ft, d_pow3_std},
		{d_pow4_ft, d_pow4_std},
		{d_pow5_ft, d_pow5_std},
	};

	t_test_case	boundary[] = {
		{d_bound1_ft, d_bound1_std},
		{d_bound2_ft, d_bound2_std},
		{d_bound3_ft, d_bound3_std},
		{d_bound4_ft, d_bound4_std},
		{d_bound5_ft, d_bound5_std},
	};

	t_test_case	near_bound[] = {
		{d_near1_ft, d_near1_std},
		{d_near2_ft, d_near2_std},
		{d_near3_ft, d_near3_std},
		{d_near4_ft, d_near4_std},
		{d_near5_ft, d_near5_std},
	};

	t_test_case	with_text[] = {
		{d_text1_ft, d_text1_std},
		{d_text2_ft, d_text2_std},
		{d_text3_ft, d_text3_std},
		{d_text4_ft, d_text4_std},
		{d_text5_ft, d_text5_std},
	};

	t_test_case	multiple[] = {
		{d_multi1_ft, d_multi1_std},
		{d_multi2_ft, d_multi2_std},
		{d_multi3_ft, d_multi3_std},
		{d_multi4_ft, d_multi4_std},
		{d_multi5_ft, d_multi5_std},
	};

	t_test_case	with_char[] = {
		{d_char1_ft, d_char1_std},
		{d_char2_ft, d_char2_std},
		{d_char3_ft, d_char3_std},
		{d_char4_ft, d_char4_std},
		{d_char5_ft, d_char5_std},
	};

	t_test_case	special[] = {
		{d_spec1_ft, d_spec1_std},
		{d_spec2_ft, d_spec2_std},
		{d_spec3_ft, d_spec3_std},
		{d_spec4_ft, d_spec4_std},
		{d_spec5_ft, d_spec5_std},
	};

	t_test_group	groups[] = {
		{"Basic test", basic, 5},
		{"Positive numbers", positive, 5},
		{"Negative numbers", negative, 5},
		{"Powers of 10", powers, 5},
		{"Boundary Values", boundary, 5},
		{"Near Boundary", near_bound, 5},
		{"With Text", with_text, 5},
		{"Multiple %%d", multiple, 5},
		{"Mixed with %%c", with_char, 5},
		{"Special Cases", special, 5},
	};

	print_grouped_results("%%d", groups, 10);
}

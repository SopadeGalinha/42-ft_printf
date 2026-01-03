#include "tests.h"
#include "../../ft_printf.h"
#include <stdio.h>
#include <limits.h>

// ========== BASIC TESTS ==========
static int	i_basic1_ft(void) { return ft_printf("%i", 0); }
static int	i_basic1_std(void) { return printf("%i", 0); }

static int	i_basic2_ft(void) { return ft_printf("%i", 1); }
static int	i_basic2_std(void) { return printf("%i", 1); }

static int	i_basic3_ft(void) { return ft_printf("%i", -1); }
static int	i_basic3_std(void) { return printf("%i", -1); }

static int	i_basic4_ft(void) { return ft_printf("%i", 42); }
static int	i_basic4_std(void) { return printf("%i", 42); }

static int	i_basic5_ft(void) { return ft_printf("%i", -42); }
static int	i_basic5_std(void) { return printf("%i", -42); }

// ========== POSITIVE NUMBERS ==========
static int	i_pos1_ft(void) { return ft_printf("%i", 9); }
static int	i_pos1_std(void) { return printf("%i", 9); }

static int	i_pos2_ft(void) { return ft_printf("%i", 99); }
static int	i_pos2_std(void) { return printf("%i", 99); }

static int	i_pos3_ft(void) { return ft_printf("%i", 123); }
static int	i_pos3_std(void) { return printf("%i", 123); }

static int	i_pos4_ft(void) { return ft_printf("%i", 1234567); }
static int	i_pos4_std(void) { return printf("%i", 1234567); }

static int	i_pos5_ft(void) { return ft_printf("%i", 999999); }
static int	i_pos5_std(void) { return printf("%i", 999999); }

// ========== NEGATIVE NUMBERS ==========
static int	i_neg1_ft(void) { return ft_printf("%i", -9); }
static int	i_neg1_std(void) { return printf("%i", -9); }

static int	i_neg2_ft(void) { return ft_printf("%i", -99); }
static int	i_neg2_std(void) { return printf("%i", -99); }

static int	i_neg3_ft(void) { return ft_printf("%i", -123); }
static int	i_neg3_std(void) { return printf("%i", -123); }

static int	i_neg4_ft(void) { return ft_printf("%i", -1234567); }
static int	i_neg4_std(void) { return printf("%i", -1234567); }

static int	i_neg5_ft(void) { return ft_printf("%i", -999999); }
static int	i_neg5_std(void) { return printf("%i", -999999); }

// ========== BOUNDARY VALUES ==========
static int	i_bound1_ft(void) { return ft_printf("%i", INT_MAX); }
static int	i_bound1_std(void) { return printf("%i", INT_MAX); }

static int	i_bound2_ft(void) { return ft_printf("%i", INT_MIN); }
static int	i_bound2_std(void) { return printf("%i", INT_MIN); }

static int	i_bound3_ft(void) { return ft_printf("%i", INT_MAX - 1); }
static int	i_bound3_std(void) { return printf("%i", INT_MAX - 1); }

static int	i_bound4_ft(void) { return ft_printf("%i", INT_MIN + 1); }
static int	i_bound4_std(void) { return printf("%i", INT_MIN + 1); }

static int	i_bound5_ft(void) { return ft_printf("%i", -2147483647); }
static int	i_bound5_std(void) { return printf("%i", -2147483647); }

// ========== MULTIPLE VALUES ==========
static int	i_mult1_ft(void) { return ft_printf("%i %i", 1, 2); }
static int	i_mult1_std(void) { return printf("%i %i", 1, 2); }

static int	i_mult2_ft(void) { return ft_printf("%i %i %i", -1, 0, 1); }
static int	i_mult2_std(void) { return printf("%i %i %i", -1, 0, 1); }

static int	i_mult3_ft(void) { return ft_printf("Ints: %i, %i, %i", 10, -20, 30); }
static int	i_mult3_std(void) { return printf("Ints: %i, %i, %i", 10, -20, 30); }

static int	i_mult4_ft(void) { return ft_printf("%i%i%i", 1, 2, 3); }
static int	i_mult4_std(void) { return printf("%i%i%i", 1, 2, 3); }

static int	i_mult5_ft(void) { return ft_printf("%i\n%i", -555, 666); }
static int	i_mult5_std(void) { return printf("%i\n%i", -555, 666); }

void	run_i_tests(void)
{
	t_test_case	basic[] = {
		{i_basic1_ft, i_basic1_std},
		{i_basic2_ft, i_basic2_std},
		{i_basic3_ft, i_basic3_std},
		{i_basic4_ft, i_basic4_std},
		{i_basic5_ft, i_basic5_std},
	};
	t_test_case	pos[] = {
		{i_pos1_ft, i_pos1_std},
		{i_pos2_ft, i_pos2_std},
		{i_pos3_ft, i_pos3_std},
		{i_pos4_ft, i_pos4_std},
		{i_pos5_ft, i_pos5_std},
	};
	t_test_case	neg[] = {
		{i_neg1_ft, i_neg1_std},
		{i_neg2_ft, i_neg2_std},
		{i_neg3_ft, i_neg3_std},
		{i_neg4_ft, i_neg4_std},
		{i_neg5_ft, i_neg5_std},
	};
	t_test_case	bound[] = {
		{i_bound1_ft, i_bound1_std},
		{i_bound2_ft, i_bound2_std},
		{i_bound3_ft, i_bound3_std},
		{i_bound4_ft, i_bound4_std},
		{i_bound5_ft, i_bound5_std},
	};
	t_test_case	mult[] = {
		{i_mult1_ft, i_mult1_std},
		{i_mult2_ft, i_mult2_std},
		{i_mult3_ft, i_mult3_std},
		{i_mult4_ft, i_mult4_std},
		{i_mult5_ft, i_mult5_std},
	};
	t_test_group	groups[] = {
		{"Basic test", basic, 5},
		{"Positive numbers", pos, 5},
		{"Negative numbers", neg, 5},
		{"Boundary Values", bound, 5},
		{"Multiple Values", mult, 5},
	};

	print_grouped_results("%%i", groups, 5);
}

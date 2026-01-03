#include "tests.h"
#include "../../ft_printf.h"
#include <stdio.h>
#include <limits.h>

// ========== BASIC TESTS ==========
static int	o_basic1_ft(void) { return ft_printf("%o", 0); }
static int	o_basic1_std(void) { return printf("%o", 0); }

static int	o_basic2_ft(void) { return ft_printf("%o", 1); }
static int	o_basic2_std(void) { return printf("%o", 1); }

static int	o_basic3_ft(void) { return ft_printf("%o", 7); }
static int	o_basic3_std(void) { return printf("%o", 7); }

static int	o_basic4_ft(void) { return ft_printf("%o", 8); }
static int	o_basic4_std(void) { return printf("%o", 8); }

static int	o_basic5_ft(void) { return ft_printf("%o", 63); }
static int	o_basic5_std(void) { return printf("%o", 63); }

// ========== LARGE NUMBERS ==========
static int	o_large1_ft(void) { return ft_printf("%o", 255); }
static int	o_large1_std(void) { return printf("%o", 255); }

static int	o_large2_ft(void) { return ft_printf("%o", 512); }
static int	o_large2_std(void) { return printf("%o", 512); }

static int	o_large3_ft(void) { return ft_printf("%o", 4095); }
static int	o_large3_std(void) { return printf("%o", 4095); }

static int	o_large4_ft(void) { return ft_printf("%o", 65535); }
static int	o_large4_std(void) { return printf("%o", 65535); }

static int	o_large5_ft(void) { return ft_printf("%o", 4294967295U); }
static int	o_large5_std(void) { return printf("%o", 4294967295U); }

// ========== BOUNDARY VALUES ==========
static int	o_bound1_ft(void) { return ft_printf("%o", 10); }
static int	o_bound1_std(void) { return printf("%o", 10); }

static int	o_bound2_ft(void) { return ft_printf("%o", 100); }
static int	o_bound2_std(void) { return printf("%o", 100); }

static int	o_bound3_ft(void) { return ft_printf("%o", 1000); }
static int	o_bound3_std(void) { return printf("%o", 1000); }

static int	o_bound4_ft(void) { return ft_printf("%o", 10000); }
static int	o_bound4_std(void) { return printf("%o", 10000); }

static int	o_bound5_ft(void) { return ft_printf("%o", 100000); }
static int	o_bound5_std(void) { return printf("%o", 100000); }

// ========== MULTIPLE VALUES ==========
static int	o_mult1_ft(void) { return ft_printf("%o %o", 1, 2); }
static int	o_mult1_std(void) { return printf("%o %o", 1, 2); }

static int	o_mult2_ft(void) { return ft_printf("%o %o %o", 100, 200, 300); }
static int	o_mult2_std(void) { return printf("%o %o %o", 100, 200, 300); }

static int	o_mult3_ft(void) { return ft_printf("Octal: %o, %o, %o", 7, 8, 64); }
static int	o_mult3_std(void) { return printf("Octal: %o, %o, %o", 7, 8, 64); }

static int	o_mult4_ft(void) { return ft_printf("%o%o%o", 1, 7, 77); }
static int	o_mult4_std(void) { return printf("%o%o%o", 1, 7, 77); }

static int	o_mult5_ft(void) { return ft_printf("%o\n%o", 555, 666); }
static int	o_mult5_std(void) { return printf("%o\n%o", 555, 666); }

// ========== WITH TEXT ==========
static int	o_text1_ft(void) { return ft_printf("Octal: %o", 42); }
static int	o_text1_std(void) { return printf("Octal: %o", 42); }

static int	o_text2_ft(void) { return ft_printf("Value is %o here", 255); }
static int	o_text2_std(void) { return printf("Value is %o here", 255); }

static int	o_text3_ft(void) { return ft_printf("%o is octal", 8); }
static int	o_text3_std(void) { return printf("%o is octal", 8); }

static int	o_text4_ft(void) { return ft_printf("Count: %o\n", 777); }
static int	o_text4_std(void) { return printf("Count: %o\n", 777); }

static int	o_text5_ft(void) { return ft_printf("Got %o items", 0); }
static int	o_text5_std(void) { return printf("Got %o items", 0); }

void	run_o_tests(void)
{
	t_test_case	basic[] = {
		{o_basic1_ft, o_basic1_std},
		{o_basic2_ft, o_basic2_std},
		{o_basic3_ft, o_basic3_std},
		{o_basic4_ft, o_basic4_std},
		{o_basic5_ft, o_basic5_std},
	};
	t_test_case	large[] = {
		{o_large1_ft, o_large1_std},
		{o_large2_ft, o_large2_std},
		{o_large3_ft, o_large3_std},
		{o_large4_ft, o_large4_std},
		{o_large5_ft, o_large5_std},
	};
	t_test_case	bound[] = {
		{o_bound1_ft, o_bound1_std},
		{o_bound2_ft, o_bound2_std},
		{o_bound3_ft, o_bound3_std},
		{o_bound4_ft, o_bound4_std},
		{o_bound5_ft, o_bound5_std},
	};
	t_test_case	mult[] = {
		{o_mult1_ft, o_mult1_std},
		{o_mult2_ft, o_mult2_std},
		{o_mult3_ft, o_mult3_std},
		{o_mult4_ft, o_mult4_std},
		{o_mult5_ft, o_mult5_std},
	};
	t_test_case	text[] = {
		{o_text1_ft, o_text1_std},
		{o_text2_ft, o_text2_std},
		{o_text3_ft, o_text3_std},
		{o_text4_ft, o_text4_std},
		{o_text5_ft, o_text5_std},
	};
	t_test_group	groups[] = {
		{"Basic test", basic, 5},
		{"Large Numbers", large, 5},
		{"Boundary Values", bound, 5},
		{"Multiple Values", mult, 5},
		{"With Text", text, 5},
	};

	print_grouped_results("%%o (Extras)", groups, 5);
}

#include "tests.h"
#include "../../ft_printf.h"
#include <stdio.h>
#include <limits.h>

// ========== BASIC TESTS ==========
static int	u_basic1_ft(void) { return ft_printf("%u", 0); }
static int	u_basic1_std(void) { return printf("%u", 0); }

static int	u_basic2_ft(void) { return ft_printf("%u", 1); }
static int	u_basic2_std(void) { return printf("%u", 1); }

static int	u_basic3_ft(void) { return ft_printf("%u", 42); }
static int	u_basic3_std(void) { return printf("%u", 42); }

static int	u_basic4_ft(void) { return ft_printf("%u", 9999); }
static int	u_basic4_std(void) { return printf("%u", 9999); }

static int	u_basic5_ft(void) { return ft_printf("Value: %u", 100); }
static int	u_basic5_std(void) { return printf("Value: %u", 100); }

// ========== LARGE NUMBERS ==========
static int	u_large1_ft(void) { return ft_printf("%u", 999999); }
static int	u_large1_std(void) { return printf("%u", 999999); }

static int	u_large2_ft(void) { return ft_printf("%u", 1000000); }
static int	u_large2_std(void) { return printf("%u", 1000000); }

static int	u_large3_ft(void) { return ft_printf("%u", 2147483647); }
static int	u_large3_std(void) { return printf("%u", 2147483647); }

static int	u_large4_ft(void) { return ft_printf("%u", 4294967295U); }
static int	u_large4_std(void) { return printf("%u", 4294967295U); }

static int	u_large5_ft(void) { return ft_printf("%u", 2000000000U); }
static int	u_large5_std(void) { return printf("%u", 2000000000U); }

// ========== MULTIPLE VALUES ==========
static int	u_mult1_ft(void) { return ft_printf("%u %u", 1, 2); }
static int	u_mult1_std(void) { return printf("%u %u", 1, 2); }

static int	u_mult2_ft(void) { return ft_printf("%u %u %u", 100, 200, 300); }
static int	u_mult2_std(void) { return printf("%u %u %u", 100, 200, 300); }

static int	u_mult3_ft(void) { return ft_printf("Numbers: %u, %u, %u", 10, 20, 30); }
static int	u_mult3_std(void) { return printf("Numbers: %u, %u, %u", 10, 20, 30); }

static int	u_mult4_ft(void) { return ft_printf("%u%u%u", 1, 2, 3); }
static int	u_mult4_std(void) { return printf("%u%u%u", 1, 2, 3); }

static int	u_mult5_ft(void) { return ft_printf("%u\n%u", 555, 666); }
static int	u_mult5_std(void) { return printf("%u\n%u", 555, 666); }

// ========== BOUNDARY VALUES ==========
static int	u_bound1_ft(void) { return ft_printf("%u", 10); }
static int	u_bound1_std(void) { return printf("%u", 10); }

static int	u_bound2_ft(void) { return ft_printf("%u", 100); }
static int	u_bound2_std(void) { return printf("%u", 100); }

static int	u_bound3_ft(void) { return ft_printf("%u", 1000); }
static int	u_bound3_std(void) { return printf("%u", 1000); }

static int	u_bound4_ft(void) { return ft_printf("%u", 10000); }
static int	u_bound4_std(void) { return printf("%u", 10000); }

static int	u_bound5_ft(void) { return ft_printf("%u", 100000); }
static int	u_bound5_std(void) { return printf("%u", 100000); }

// ========== WITH TEXT ==========
static int	u_text1_ft(void) { return ft_printf("Start %u End", 42); }
static int	u_text1_std(void) { return printf("Start %u End", 42); }

static int	u_text2_ft(void) { return ft_printf("Value is %u here", 999); }
static int	u_text2_std(void) { return printf("Value is %u here", 999); }

static int	u_text3_ft(void) { return ft_printf("%u is the answer", 42); }
static int	u_text3_std(void) { return printf("%u is the answer", 42); }

static int	u_text4_ft(void) { return ft_printf("Count: %u\n", 12345); }
static int	u_text4_std(void) { return printf("Count: %u\n", 12345); }

static int	u_text5_ft(void) { return ft_printf("Got %u items", 0); }
static int	u_text5_std(void) { return printf("Got %u items", 0); }

void	run_u_tests(void)
{
	t_test_case	basic[] = {
		{u_basic1_ft, u_basic1_std},
		{u_basic2_ft, u_basic2_std},
		{u_basic3_ft, u_basic3_std},
		{u_basic4_ft, u_basic4_std},
		{u_basic5_ft, u_basic5_std},
	};
	t_test_case	large[] = {
		{u_large1_ft, u_large1_std},
		{u_large2_ft, u_large2_std},
		{u_large3_ft, u_large3_std},
		{u_large4_ft, u_large4_std},
		{u_large5_ft, u_large5_std},
	};
	t_test_case	mult[] = {
		{u_mult1_ft, u_mult1_std},
		{u_mult2_ft, u_mult2_std},
		{u_mult3_ft, u_mult3_std},
		{u_mult4_ft, u_mult4_std},
		{u_mult5_ft, u_mult5_std},
	};
	t_test_case	bound[] = {
		{u_bound1_ft, u_bound1_std},
		{u_bound2_ft, u_bound2_std},
		{u_bound3_ft, u_bound3_std},
		{u_bound4_ft, u_bound4_std},
		{u_bound5_ft, u_bound5_std},
	};
	t_test_case	text[] = {
		{u_text1_ft, u_text1_std},
		{u_text2_ft, u_text2_std},
		{u_text3_ft, u_text3_std},
		{u_text4_ft, u_text4_std},
		{u_text5_ft, u_text5_std},
	};
	t_test_group	groups[] = {
		{"Basic test", basic, 5},
		{"Large Numbers", large, 5},
		{"Multiple Values", mult, 5},
		{"Boundary Values", bound, 5},
		{"With Text", text, 5},
	};

	print_grouped_results("%%u", groups, 5);
}

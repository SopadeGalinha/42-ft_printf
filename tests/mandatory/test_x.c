#include "tests.h"
#include "../../ft_printf.h"
#include <stdio.h>
#include <limits.h>

// ========== BASIC TESTS ==========
static int	x_basic1_ft(void) { return ft_printf("%x", 0); }
static int	x_basic1_std(void) { return printf("%x", 0); }

static int	x_basic2_ft(void) { return ft_printf("%x", 1); }
static int	x_basic2_std(void) { return printf("%x", 1); }

static int	x_basic3_ft(void) { return ft_printf("%x", 255); }
static int	x_basic3_std(void) { return printf("%x", 255); }

static int	x_basic4_ft(void) { return ft_printf("%x", 256); }
static int	x_basic4_std(void) { return printf("%x", 256); }

static int	x_basic5_ft(void) { return ft_printf("%x", 4095); }
static int	x_basic5_std(void) { return printf("%x", 4095); }

// ========== UPPERCASE ==========
static int	x_upper1_ft(void) { return ft_printf("%X", 255); }
static int	x_upper1_std(void) { return printf("%X", 255); }

static int	x_upper2_ft(void) { return ft_printf("%X", 4095); }
static int	x_upper2_std(void) { return printf("%X", 4095); }

static int	x_upper3_ft(void) { return ft_printf("%X", 65535); }
static int	x_upper3_std(void) { return printf("%X", 65535); }

static int	x_upper4_ft(void) { return ft_printf("%x%X", 255, 255); }
static int	x_upper4_std(void) { return printf("%x%X", 255, 255); }

static int	x_upper5_ft(void) { return ft_printf("Lower: %x Upper: %X", 42, 42); }
static int	x_upper5_std(void) { return printf("Lower: %x Upper: %X", 42, 42); }

// ========== LARGE NUMBERS ==========
static int	x_large1_ft(void) { return ft_printf("%x", 65535); }
static int	x_large1_std(void) { return printf("%x", 65535); }

static int	x_large2_ft(void) { return ft_printf("%x", 1048575); }
static int	x_large2_std(void) { return printf("%x", 1048575); }

static int	x_large3_ft(void) { return ft_printf("%x", 16777215); }
static int	x_large3_std(void) { return printf("%x", 16777215); }

static int	x_large4_ft(void) { return ft_printf("%x", 268435455); }
static int	x_large4_std(void) { return printf("%x", 268435455); }

static int	x_large5_ft(void) { return ft_printf("%x", 4294967295U); }
static int	x_large5_std(void) { return printf("%x", 4294967295U); }

// ========== MULTIPLE VALUES ==========
static int	x_mult1_ft(void) { return ft_printf("%x %x", 1, 2); }
static int	x_mult1_std(void) { return printf("%x %x", 1, 2); }

static int	x_mult2_ft(void) { return ft_printf("%x %x %x", 255, 256, 4095); }
static int	x_mult2_std(void) { return printf("%x %x %x", 255, 256, 4095); }

static int	x_mult3_ft(void) { return ft_printf("Hex: %x, %x, %x", 10, 15, 255); }
static int	x_mult3_std(void) { return printf("Hex: %x, %x, %x", 10, 15, 255); }

static int	x_mult4_ft(void) { return ft_printf("%x%x%x", 1, 10, 100); }
static int	x_mult4_std(void) { return printf("%x%x%x", 1, 10, 100); }

static int	x_mult5_ft(void) { return ft_printf("%X %X %X", 255, 256, 4095); }
static int	x_mult5_std(void) { return printf("%X %X %X", 255, 256, 4095); }

// ========== EDGE CASES ==========
static int	x_edge1_ft(void) { return ft_printf("%x", 10); }
static int	x_edge1_std(void) { return printf("%x", 10); }

static int	x_edge2_ft(void) { return ft_printf("%x", 11); }
static int	x_edge2_std(void) { return printf("%x", 11); }

static int	x_edge3_ft(void) { return ft_printf("%x", 15); }
static int	x_edge3_std(void) { return printf("%x", 15); }

static int	x_edge4_ft(void) { return ft_printf("Value: %x", 170); }
static int	x_edge4_std(void) { return printf("Value: %x", 170); }

static int	x_edge5_ft(void) { return ft_printf("%X", 2748); }
static int	x_edge5_std(void) { return printf("%X", 2748); }

void	run_x_tests(void)
{
	t_test_case	basic[] = {
		{x_basic1_ft, x_basic1_std},
		{x_basic2_ft, x_basic2_std},
		{x_basic3_ft, x_basic3_std},
		{x_basic4_ft, x_basic4_std},
		{x_basic5_ft, x_basic5_std},
	};
	t_test_case	upper[] = {
		{x_upper1_ft, x_upper1_std},
		{x_upper2_ft, x_upper2_std},
		{x_upper3_ft, x_upper3_std},
		{x_upper4_ft, x_upper4_std},
		{x_upper5_ft, x_upper5_std},
	};
	t_test_case	large[] = {
		{x_large1_ft, x_large1_std},
		{x_large2_ft, x_large2_std},
		{x_large3_ft, x_large3_std},
		{x_large4_ft, x_large4_std},
		{x_large5_ft, x_large5_std},
	};
	t_test_case	mult[] = {
		{x_mult1_ft, x_mult1_std},
		{x_mult2_ft, x_mult2_std},
		{x_mult3_ft, x_mult3_std},
		{x_mult4_ft, x_mult4_std},
		{x_mult5_ft, x_mult5_std},
	};
	t_test_case	edge[] = {
		{x_edge1_ft, x_edge1_std},
		{x_edge2_ft, x_edge2_std},
		{x_edge3_ft, x_edge3_std},
		{x_edge4_ft, x_edge4_std},
		{x_edge5_ft, x_edge5_std},
	};
	t_test_group	groups[] = {
		{"Basic test", basic, 5},
		{"Uppercase", upper, 5},
		{"Large Numbers", large, 5},
		{"Multiple Values", mult, 5},
		{"Edge Cases", edge, 5},
	};

	print_grouped_results("%%x/%%X", groups, 5);
}

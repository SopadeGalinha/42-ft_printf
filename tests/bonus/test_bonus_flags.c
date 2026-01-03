#include "bonus_tests.h"
#include "../../ft_printf.h"
#include <stdio.h>
#include <limits.h>

// ========== WIDTH TESTS ==========
static int	bf_width1_ft(void) { return ft_printf("%5d", 42); }
static int	bf_width1_std(void) { return printf("%5d", 42); }

static int	bf_width2_ft(void) { return ft_printf("%10s", "test"); }
static int	bf_width2_std(void) { return printf("%10s", "test"); }

static int	bf_width3_ft(void) { return ft_printf("%8c", 'A'); }
static int	bf_width3_std(void) { return printf("%8c", 'A'); }

static int	bf_width4_ft(void) { return ft_printf("%6u", 100); }
static int	bf_width4_std(void) { return printf("%6u", 100); }

static int	bf_width5_ft(void) { return ft_printf("%8x", 255); }
static int	bf_width5_std(void) { return printf("%8x", 255); }

// ========== PRECISION TESTS ==========
static int	bf_prec1_ft(void) { return ft_printf("%.5s", "hello world"); }
static int	bf_prec1_std(void) { return printf("%.5s", "hello world"); }

static int	bf_prec2_ft(void) { return ft_printf("%.10s", "test"); }
static int	bf_prec2_std(void) { return printf("%.10s", "test"); }

static int	bf_prec3_ft(void) { return ft_printf("%.3s", "abc"); }
static int	bf_prec3_std(void) { return printf("%.3s", "abc"); }

static int	bf_prec4_ft(void) { return ft_printf("%.1s", "hello"); }
static int	bf_prec4_std(void) { return printf("%.1s", "hello"); }

static int	bf_prec5_ft(void) { return ft_printf("%.0s", "test"); }
static int	bf_prec5_std(void) { return printf("%.0s", "test"); }

// ========== LEFT ALIGN (-) ==========
static int	bf_left1_ft(void) { return ft_printf("%-5d", 42); }
static int	bf_left1_std(void) { return printf("%-5d", 42); }

static int	bf_left2_ft(void) { return ft_printf("%-10s", "test"); }
static int	bf_left2_std(void) { return printf("%-10s", "test"); }

static int	bf_left3_ft(void) { return ft_printf("%-8c", 'X'); }
static int	bf_left3_std(void) { return printf("%-8c", 'X'); }

static int	bf_left4_ft(void) { return ft_printf("%-6u", 99); }
static int	bf_left4_std(void) { return printf("%-6u", 99); }

static int	bf_left5_ft(void) { return ft_printf("%-8x", 256); }
static int	bf_left5_std(void) { return printf("%-8x", 256); }

// ========== ZERO PADDING (0) ==========
static int	bf_zero1_ft(void) { return ft_printf("%05d", 42); }
static int	bf_zero1_std(void) { return printf("%05d", 42); }

static int	bf_zero2_ft(void) { return ft_printf("%010u", 100); }
static int	bf_zero2_std(void) { return printf("%010u", 100); }

static int	bf_zero3_ft(void) { return ft_printf("%08x", 255); }
static int	bf_zero3_std(void) { return printf("%08x", 255); }

static int	bf_zero4_ft(void) { return ft_printf("%07d", -99); }
static int	bf_zero4_std(void) { return printf("%07d", -99); }

static int	bf_zero5_ft(void) { return ft_printf("%09d", 1234); }
static int	bf_zero5_std(void) { return printf("%09d", 1234); }

// ========== PLUS SIGN (+) ==========
static int	bf_plus1_ft(void) { return ft_printf("%+d", 42); }
static int	bf_plus1_std(void) { return printf("%+d", 42); }

static int	bf_plus2_ft(void) { return ft_printf("%+d", -42); }
static int	bf_plus2_std(void) { return printf("%+d", -42); }

static int	bf_plus3_ft(void) { return ft_printf("%+5d", 99); }
static int	bf_plus3_std(void) { return printf("%+5d", 99); }

static int	bf_plus4_ft(void) { return ft_printf("%+i", 0); }
static int	bf_plus4_std(void) { return printf("%+i", 0); }

static int	bf_plus5_ft(void) { return ft_printf("%+10d", -777); }
static int	bf_plus5_std(void) { return printf("%+10d", -777); }

void	run_bonus_flags_tests(void)
{
	t_test_case	width[] = {
		{bf_width1_ft, bf_width1_std},
		{bf_width2_ft, bf_width2_std},
		{bf_width3_ft, bf_width3_std},
		{bf_width4_ft, bf_width4_std},
		{bf_width5_ft, bf_width5_std},
	};
	t_test_case	prec[] = {
		{bf_prec1_ft, bf_prec1_std},
		{bf_prec2_ft, bf_prec2_std},
		{bf_prec3_ft, bf_prec3_std},
		{bf_prec4_ft, bf_prec4_std},
		{bf_prec5_ft, bf_prec5_std},
	};
	t_test_case	left[] = {
		{bf_left1_ft, bf_left1_std},
		{bf_left2_ft, bf_left2_std},
		{bf_left3_ft, bf_left3_std},
		{bf_left4_ft, bf_left4_std},
		{bf_left5_ft, bf_left5_std},
	};
	t_test_case	zero[] = {
		{bf_zero1_ft, bf_zero1_std},
		{bf_zero2_ft, bf_zero2_std},
		{bf_zero3_ft, bf_zero3_std},
		{bf_zero4_ft, bf_zero4_std},
		{bf_zero5_ft, bf_zero5_std},
	};
	t_test_case	plus[] = {
		{bf_plus1_ft, bf_plus1_std},
		{bf_plus2_ft, bf_plus2_std},
		{bf_plus3_ft, bf_plus3_std},
		{bf_plus4_ft, bf_plus4_std},
		{bf_plus5_ft, bf_plus5_std},
	};
	t_test_group	groups[] = {
		{"Width Tests", width, 5},
		{"Precision Tests", prec, 5},
		{"Left Align (-)", left, 5},
		{"Zero Padding (0)", zero, 5},
		{"Plus Sign (+)", plus, 5},
	};

	print_grouped_results("Core Bonus Flags", groups, 5);
}

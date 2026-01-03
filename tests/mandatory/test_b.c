#include "tests.h"
#include "../../ft_printf.h"
#include <stdio.h>
#include <limits.h>

// ========== BASIC TESTS ==========
static int	b_basic1_ft(void) { return ft_printf("%b", 0); }
static int	b_basic1_std(void) { return printf("%b", 0); }

static int	b_basic2_ft(void) { return ft_printf("%b", 1); }
static int	b_basic2_std(void) { return printf("%b", 1); }

static int	b_basic3_ft(void) { return ft_printf("%b", 2); }
static int	b_basic3_std(void) { return printf("%b", 2); }

static int	b_basic4_ft(void) { return ft_printf("%b", 3); }
static int	b_basic4_std(void) { return printf("%b", 3); }

static int	b_basic5_ft(void) { return ft_printf("%b", 7); }
static int	b_basic5_std(void) { return printf("%b", 7); }

// ========== BYTE VALUES ==========
static int	b_byte1_ft(void) { return ft_printf("%b", 8); }
static int	b_byte1_std(void) { return printf("%b", 8); }

static int	b_byte2_ft(void) { return ft_printf("%b", 15); }
static int	b_byte2_std(void) { return printf("%b", 15); }

static int	b_byte3_ft(void) { return ft_printf("%b", 16); }
static int	b_byte3_std(void) { return printf("%b", 16); }

static int	b_byte4_ft(void) { return ft_printf("%b", 127); }
static int	b_byte4_std(void) { return printf("%b", 127); }

static int	b_byte5_ft(void) { return ft_printf("%b", 255); }
static int	b_byte5_std(void) { return printf("%b", 255); }

// ========== LARGER VALUES ==========
static int	b_large1_ft(void) { return ft_printf("%b", 256); }
static int	b_large1_std(void) { return printf("%b", 256); }

static int	b_large2_ft(void) { return ft_printf("%b", 512); }
static int	b_large2_std(void) { return printf("%b", 512); }

static int	b_large3_ft(void) { return ft_printf("%b", 1023); }
static int	b_large3_std(void) { return printf("%b", 1023); }

static int	b_large4_ft(void) { return ft_printf("%b", 4095); }
static int	b_large4_std(void) { return printf("%b", 4095); }

static int	b_large5_ft(void) { return ft_printf("%b", 65535); }
static int	b_large5_std(void) { return printf("%b", 65535); }

// ========== MULTIPLE VALUES ==========
static int	b_mult1_ft(void) { return ft_printf("%b %b", 1, 2); }
static int	b_mult1_std(void) { return printf("%b %b", 1, 2); }

static int	b_mult2_ft(void) { return ft_printf("%b %b %b", 3, 5, 7); }
static int	b_mult2_std(void) { return printf("%b %b %b", 3, 5, 7); }

static int	b_mult3_ft(void) { return ft_printf("Binary: %b, %b", 8, 16); }
static int	b_mult3_std(void) { return printf("Binary: %b, %b", 8, 16); }

static int	b_mult4_ft(void) { return ft_printf("%b%b%b", 1, 1, 1); }
static int	b_mult4_std(void) { return printf("%b%b%b", 1, 1, 1); }

static int	b_mult5_ft(void) { return ft_printf("%b\n%b", 127, 255); }
static int	b_mult5_std(void) { return printf("%b\n%b", 127, 255); }

// ========== WITH TEXT ==========
static int	b_text1_ft(void) { return ft_printf("Binary: %b", 42); }
static int	b_text1_std(void) { return printf("Binary: %b", 42); }

static int	b_text2_ft(void) { return ft_printf("Value is %b here", 255); }
static int	b_text2_std(void) { return printf("Value is %b here", 255); }

static int	b_text3_ft(void) { return ft_printf("%b is binary", 8); }
static int	b_text3_std(void) { return printf("%b is binary", 8); }

static int	b_text4_ft(void) { return ft_printf("Count: %b\n", 777); }
static int	b_text4_std(void) { return printf("Count: %b\n", 777); }

static int	b_text5_ft(void) { return ft_printf("Got %b items", 0); }
static int	b_text5_std(void) { return printf("Got %b items", 0); }

void	run_b_tests(void)
{
	t_test_case	basic[] = {
		{b_basic1_ft, b_basic1_std},
		{b_basic2_ft, b_basic2_std},
		{b_basic3_ft, b_basic3_std},
		{b_basic4_ft, b_basic4_std},
		{b_basic5_ft, b_basic5_std},
	};
	t_test_case	byte[] = {
		{b_byte1_ft, b_byte1_std},
		{b_byte2_ft, b_byte2_std},
		{b_byte3_ft, b_byte3_std},
		{b_byte4_ft, b_byte4_std},
		{b_byte5_ft, b_byte5_std},
	};
	t_test_case	large[] = {
		{b_large1_ft, b_large1_std},
		{b_large2_ft, b_large2_std},
		{b_large3_ft, b_large3_std},
		{b_large4_ft, b_large4_std},
		{b_large5_ft, b_large5_std},
	};
	t_test_case	mult[] = {
		{b_mult1_ft, b_mult1_std},
		{b_mult2_ft, b_mult2_std},
		{b_mult3_ft, b_mult3_std},
		{b_mult4_ft, b_mult4_std},
		{b_mult5_ft, b_mult5_std},
	};
	t_test_case	text[] = {
		{b_text1_ft, b_text1_std},
		{b_text2_ft, b_text2_std},
		{b_text3_ft, b_text3_std},
		{b_text4_ft, b_text4_std},
		{b_text5_ft, b_text5_std},
	};
	t_test_group	groups[] = {
		{"Basic test", basic, 5},
		{"Byte Values", byte, 5},
		{"Larger Values", large, 5},
		{"Multiple Values", mult, 5},
		{"With Text", text, 5},
	};

	print_grouped_results("%%b (Extras)", groups, 5);
}

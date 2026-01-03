#include "tests.h"
#include "../../ft_printf.h"
#include <stdio.h>

// ========== BASIC TESTS ==========
static int	c_basic1_ft(void) { return ft_printf("%c", 'A'); }
static int	c_basic1_std(void) { return printf("%c", 'A'); }

static int	c_basic2_ft(void) { return ft_printf("%c", 'a'); }
static int	c_basic2_std(void) { return printf("%c", 'a'); }

static int	c_basic3_ft(void) { return ft_printf("%c", '0'); }
static int	c_basic3_std(void) { return printf("%c", '0'); }

static int	c_basic4_ft(void) { return ft_printf("%c", ' '); }
static int	c_basic4_std(void) { return printf("%c", ' '); }

static int	c_basic5_ft(void) { return ft_printf("%c", 'Z'); }
static int	c_basic5_std(void) { return printf("%c", 'Z'); }

// ========== LOWERCASE ==========
static int	c_lower1_ft(void) { return ft_printf("%c", 'z'); }
static int	c_lower1_std(void) { return printf("%c", 'z'); }

static int	c_lower2_ft(void) { return ft_printf("%c", 'b'); }
static int	c_lower2_std(void) { return printf("%c", 'b'); }

static int	c_lower3_ft(void) { return ft_printf("%c", 'm'); }
static int	c_lower3_std(void) { return printf("%c", 'm'); }

static int	c_lower4_ft(void) { return ft_printf("%c", 'x'); }
static int	c_lower4_std(void) { return printf("%c", 'x'); }

static int	c_lower5_ft(void) { return ft_printf("%c", 'q'); }
static int	c_lower5_std(void) { return printf("%c", 'q'); }

// ========== DIGITS ==========
static int	c_digit1_ft(void) { return ft_printf("%c", '0'); }
static int	c_digit1_std(void) { return printf("%c", '0'); }

static int	c_digit2_ft(void) { return ft_printf("%c", '5'); }
static int	c_digit2_std(void) { return printf("%c", '5'); }

static int	c_digit3_ft(void) { return ft_printf("%c", '9'); }
static int	c_digit3_std(void) { return printf("%c", '9'); }

static int	c_digit4_ft(void) { return ft_printf("%c", '1'); }
static int	c_digit4_std(void) { return printf("%c", '1'); }

static int	c_digit5_ft(void) { return ft_printf("%c", '3'); }
static int	c_digit5_std(void) { return printf("%c", '3'); }

// ========== SPECIAL CHARS ==========
static int	c_spec1_ft(void) { return ft_printf("%c", '\n'); }
static int	c_spec1_std(void) { return printf("%c", '\n'); }

static int	c_spec2_ft(void) { return ft_printf("%c", '\t'); }
static int	c_spec2_std(void) { return printf("%c", '\t'); }

static int	c_spec3_ft(void) { return ft_printf("%c", ' '); }
static int	c_spec3_std(void) { return printf("%c", ' '); }

static int	c_spec4_ft(void) { return ft_printf("%c", '!'); }
static int	c_spec4_std(void) { return printf("%c", '!'); }

static int	c_spec5_ft(void) { return ft_printf("%c", '@'); }
static int	c_spec5_std(void) { return printf("%c", '@'); }

// ========== WITH TEXT ==========
static int	c_text1_ft(void) { return ft_printf("Char: %c", 'X'); }
static int	c_text1_std(void) { return printf("Char: %c", 'X'); }

static int	c_text2_ft(void) { return ft_printf("Letter %c End", 'K'); }
static int	c_text2_std(void) { return printf("Letter %c End", 'K'); }

static int	c_text3_ft(void) { return ft_printf("  %c  ", 'M'); }
static int	c_text3_std(void) { return printf("  %c  ", 'M'); }

static int	c_text4_ft(void) { return ft_printf("%c!", 'Y'); }
static int	c_text4_std(void) { return printf("%c!", 'Y'); }

static int	c_text5_ft(void) { return ft_printf("<%c>", 'P'); }
static int	c_text5_std(void) { return printf("<%c>", 'P'); }

// ========== MULTIPLE %c ==========
static int	c_multi1_ft(void) { return ft_printf("%c%c%c", 'A', 'B', 'C'); }
static int	c_multi1_std(void) { return printf("%c%c%c", 'A', 'B', 'C'); }

static int	c_multi2_ft(void) { return ft_printf("%c %c %c", 'X', 'Y', 'Z'); }
static int	c_multi2_std(void) { return printf("%c %c %c", 'X', 'Y', 'Z'); }

static int	c_multi3_ft(void) { return ft_printf("%c-%c-%c-%c-%c", 'a', 'b', 'c', 'd', 'e'); }
static int	c_multi3_std(void) { return printf("%c-%c-%c-%c-%c", 'a', 'b', 'c', 'd', 'e'); }

static int	c_multi4_ft(void) { return ft_printf("%c %c %c %c", '1', '2', '3', '4'); }
static int	c_multi4_std(void) { return printf("%c %c %c %c", '1', '2', '3', '4'); }

static int	c_multi5_ft(void) { return ft_printf("%c %c", 'Q', 'W'); }
static int	c_multi5_std(void) { return printf("%c %c", 'Q', 'W'); }

// ========== EDGE CASES ==========
static int	c_edge1_ft(void) { return ft_printf("%c", '\0'); }
static int	c_edge1_std(void) { return printf("%c", '\0'); }

static int	c_edge2_ft(void) { return ft_printf("%c", 127); }
static int	c_edge2_std(void) { return printf("%c", 127); }

static int	c_edge3_ft(void) { return ft_printf("%c", 1); }
static int	c_edge3_std(void) { return printf("%c", 1); }

static int	c_edge4_ft(void) { return ft_printf("%c", (char)255); }
static int	c_edge4_std(void) { return printf("%c", (char)255); }

static int	c_edge5_ft(void) { return ft_printf("%c", '~'); }
static int	c_edge5_std(void) { return printf("%c", '~'); }

void	run_c_tests(void)
{
	t_test_case	basic[] = {
		{c_basic1_ft, c_basic1_std},
		{c_basic2_ft, c_basic2_std},
		{c_basic3_ft, c_basic3_std},
		{c_basic4_ft, c_basic4_std},
		{c_basic5_ft, c_basic5_std},
	};

	t_test_case	lowercase[] = {
		{c_lower1_ft, c_lower1_std},
		{c_lower2_ft, c_lower2_std},
		{c_lower3_ft, c_lower3_std},
		{c_lower4_ft, c_lower4_std},
		{c_lower5_ft, c_lower5_std},
	};

	t_test_case	digits[] = {
		{c_digit1_ft, c_digit1_std},
		{c_digit2_ft, c_digit2_std},
		{c_digit3_ft, c_digit3_std},
		{c_digit4_ft, c_digit4_std},
		{c_digit5_ft, c_digit5_std},
	};

	t_test_case	special[] = {
		{c_spec1_ft, c_spec1_std},
		{c_spec2_ft, c_spec2_std},
		{c_spec3_ft, c_spec3_std},
		{c_spec4_ft, c_spec4_std},
		{c_spec5_ft, c_spec5_std},
	};

	t_test_case	with_text[] = {
		{c_text1_ft, c_text1_std},
		{c_text2_ft, c_text2_std},
		{c_text3_ft, c_text3_std},
		{c_text4_ft, c_text4_std},
		{c_text5_ft, c_text5_std},
	};

	t_test_case	multiple[] = {
		{c_multi1_ft, c_multi1_std},
		{c_multi2_ft, c_multi2_std},
		{c_multi3_ft, c_multi3_std},
		{c_multi4_ft, c_multi4_std},
		{c_multi5_ft, c_multi5_std},
	};

	t_test_case	edge_cases[] = {
		{c_edge1_ft, c_edge1_std},
		{c_edge2_ft, c_edge2_std},
		{c_edge3_ft, c_edge3_std},
		{c_edge4_ft, c_edge4_std},
		{c_edge5_ft, c_edge5_std},
	};

	t_test_group	groups[] = {
		{"Basic test", basic, 5},
		{"Lowercase", lowercase, 5},
		{"Digits", digits, 5},
		{"Special Chars", special, 5},
		{"With Text", with_text, 5},
		{"Multiple %%c", multiple, 5},
		{"Edge Cases", edge_cases, 5},
	};

	print_grouped_results("%%c", groups, 7);
}

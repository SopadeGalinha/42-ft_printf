#include "tests.h"
#include "../../ft_printf.h"
#include <stdio.h>
#include <limits.h>

// ========== BASIC TESTS ==========
static int	s_basic1_ft(void) { return ft_printf("%s", "Hello"); }
static int	s_basic1_std(void) { return printf("%s", "Hello"); }

static int	s_basic2_ft(void) { return ft_printf("%s", ""); }
static int	s_basic2_std(void) { return printf("%s", ""); }

static int	s_basic3_ft(void) { return ft_printf("%s", "World"); }
static int	s_basic3_std(void) { return printf("%s", "World"); }

static int	s_basic4_ft(void) { return ft_printf("String: %s", "test"); }
static int	s_basic4_std(void) { return printf("String: %s", "test"); }

static int	s_basic5_ft(void) { return ft_printf("%s%s", "Hello", "World"); }
static int	s_basic5_std(void) { return printf("%s%s", "Hello", "World"); }

// ========== SPECIAL CHARACTERS ==========
static int	s_spec1_ft(void) { return ft_printf("%s", "Hello\nWorld"); }
static int	s_spec1_std(void) { return printf("%s", "Hello\nWorld"); }

static int	s_spec2_ft(void) { return ft_printf("%s", "Tab\there"); }
static int	s_spec2_std(void) { return printf("%s", "Tab\there"); }

static int	s_spec3_ft(void) { return ft_printf("%s", "Quote\"Test"); }
static int	s_spec3_std(void) { return printf("%s", "Quote\"Test"); }

static int	s_spec4_ft(void) { return ft_printf("%s", "Single'Quote"); }
static int	s_spec4_std(void) { return printf("%s", "Single'Quote"); }

static int	s_spec5_ft(void) { return ft_printf("%s", "Multiple\t\n\tTabs"); }
static int	s_spec5_std(void) { return printf("%s", "Multiple\t\n\tTabs"); }

// ========== NUMBERS IN STRINGS ==========
static int	s_num1_ft(void) { return ft_printf("%s", "12345"); }
static int	s_num1_std(void) { return printf("%s", "12345"); }

static int	s_num2_ft(void) { return ft_printf("%s", "-999"); }
static int	s_num2_std(void) { return printf("%s", "-999"); }

static int	s_num3_ft(void) { return ft_printf("%s", "0"); }
static int	s_num3_std(void) { return printf("%s", "0"); }

static int	s_num4_ft(void) { return ft_printf("Number: %s End", "42"); }
static int	s_num4_std(void) { return printf("Number: %s End", "42"); }

static int	s_num5_ft(void) { return ft_printf("%s %s", "First", "Second"); }
static int	s_num5_std(void) { return printf("%s %s", "First", "Second"); }

// ========== MIXED STRINGS ==========
static int	s_mix1_ft(void) { return ft_printf("Text %s End", "Middle"); }
static int	s_mix1_std(void) { return printf("Text %s End", "Middle"); }

static int	s_mix2_ft(void) { return ft_printf("Start %s %s %s", "A", "B", "C"); }
static int	s_mix2_std(void) { return printf("Start %s %s %s", "A", "B", "C"); }

static int	s_mix3_ft(void) { return ft_printf("%s\n%s", "Line1", "Line2"); }
static int	s_mix3_std(void) { return printf("%s\n%s", "Line1", "Line2"); }

static int	s_mix4_ft(void) { return ft_printf("Before%sAfter", "Middle"); }
static int	s_mix4_std(void) { return printf("Before%sAfter", "Middle"); }

static int	s_mix5_ft(void) { return ft_printf("%s%s%s", "A", "B", "C"); }
static int	s_mix5_std(void) { return printf("%s%s%s", "A", "B", "C"); }

// ========== EDGE CASES ==========
static int	s_edge1_ft(void) { return ft_printf("%s", "!@#$%^&*()"); }
static int	s_edge1_std(void) { return printf("%s", "!@#$%^&*()"); }

static int	s_edge2_ft(void) { return ft_printf("%s", "   spaces   "); }
static int	s_edge2_std(void) { return printf("%s", "   spaces   "); }

static int	s_edge3_ft(void) { return ft_printf("%s", "UPPERCASE"); }
static int	s_edge3_std(void) { return printf("%s", "UPPERCASE"); }

static int	s_edge4_ft(void) { return ft_printf("%s", "lowercase"); }
static int	s_edge4_std(void) { return printf("%s", "lowercase"); }

static int	s_edge5_ft(void) { return ft_printf("%s%s%s%s%s", "a", "b", "c", "d", "e"); }
static int	s_edge5_std(void) { return printf("%s%s%s%s%s", "a", "b", "c", "d", "e"); }

void	run_s_tests(void)
{
	t_test_case	basic[] = {
		{s_basic1_ft, s_basic1_std},
		{s_basic2_ft, s_basic2_std},
		{s_basic3_ft, s_basic3_std},
		{s_basic4_ft, s_basic4_std},
		{s_basic5_ft, s_basic5_std},
	};
	t_test_case	special[] = {
		{s_spec1_ft, s_spec1_std},
		{s_spec2_ft, s_spec2_std},
		{s_spec3_ft, s_spec3_std},
		{s_spec4_ft, s_spec4_std},
		{s_spec5_ft, s_spec5_std},
	};
	t_test_case	numbers[] = {
		{s_num1_ft, s_num1_std},
		{s_num2_ft, s_num2_std},
		{s_num3_ft, s_num3_std},
		{s_num4_ft, s_num4_std},
		{s_num5_ft, s_num5_std},
	};
	t_test_case	mixed[] = {
		{s_mix1_ft, s_mix1_std},
		{s_mix2_ft, s_mix2_std},
		{s_mix3_ft, s_mix3_std},
		{s_mix4_ft, s_mix4_std},
		{s_mix5_ft, s_mix5_std},
	};
	t_test_case	edge[] = {
		{s_edge1_ft, s_edge1_std},
		{s_edge2_ft, s_edge2_std},
		{s_edge3_ft, s_edge3_std},
		{s_edge4_ft, s_edge4_std},
		{s_edge5_ft, s_edge5_std},
	};
	t_test_group	groups[] = {
		{"Basic test", basic, 5},
		{"Special Characters", special, 5},
		{"Numbers in Strings", numbers, 5},
		{"Mixed Strings", mixed, 5},
		{"Edge Cases", edge, 5},
	};

	print_grouped_results("%%s", groups, 5);
}

#include "bonus_tests.h"
#include "../../ft_printf.h"
#include <stdio.h>
#include <limits.h>

// ========== STAR WIDTH AND PRECISION (*) ==========
static int	rig_star1_ft(void) { return ft_printf("%*d", 5, 42); }
static int	rig_star1_std(void) { return printf("%*d", 5, 42); }

static int	rig_star2_ft(void) { return ft_printf("%*d", -5, 42); }
static int	rig_star2_std(void) { return printf("%*d", -5, 42); }

static int	rig_star3_ft(void) { return ft_printf("%.*s", 5, "hello world"); }
static int	rig_star3_std(void) { return printf("%.*s", 5, "hello world"); }

static int	rig_star4_ft(void) { return ft_printf("%*.*s", 10, 5, "hello"); }
static int	rig_star4_std(void) { return printf("%*.*s", 10, 5, "hello"); }

static int	rig_star5_ft(void) { return ft_printf("%*d", 0, 42); }
static int	rig_star5_std(void) { return printf("%*d", 0, 42); }

static int	rig_star6_ft(void) { return ft_printf("%.*d", 3, 5); }
static int	rig_star6_std(void) { return printf("%.*d", 3, 5); }

static int	rig_star7_ft(void) { return ft_printf("%-*d", 8, 99); }
static int	rig_star7_std(void) { return printf("%-*d", 8, 99); }

static int	rig_star8_ft(void) { return ft_printf("%+*d", 6, 42); }
static int	rig_star8_std(void) { return printf("%+*d", 6, 42); }

static int	rig_star9_ft(void) { return ft_printf("%0*d", 8, -42); }
static int	rig_star9_std(void) { return printf("%0*d", 8, -42); }

static int	rig_star10_ft(void) { return ft_printf("%*.*d", 10, 5, 123); }
static int	rig_star10_std(void) { return printf("%*.*d", 10, 5, 123); }

// ========== PRECISION WITH INTEGERS (ZERO PAD BEHAVIOR) ==========
static int	rig_prec_int1_ft(void) { return ft_printf("%.5d", 42); }
static int	rig_prec_int1_std(void) { return printf("%.5d", 42); }

static int	rig_prec_int2_ft(void) { return ft_printf("%.10d", -42); }
static int	rig_prec_int2_std(void) { return printf("%.10d", -42); }

static int	rig_prec_int3_ft(void) { return ft_printf("%10.5d", 42); }
static int	rig_prec_int3_std(void) { return printf("%10.5d", 42); }

static int	rig_prec_int4_ft(void) { return ft_printf("%.0d", 0); }
static int	rig_prec_int4_std(void) { return printf("%.0d", 0); }

static int	rig_prec_int5_ft(void) { return ft_printf("%+.5d", 42); }
static int	rig_prec_int5_std(void) { return printf("%+.5d", 42); }

// ========== MULTIPLE %% AND EDGE CASES ==========
static int	rig_percent1_ft(void) { return ft_printf("%%"); }
static int	rig_percent1_std(void) { return printf("%%"); }

static int	rig_percent2_ft(void) { return ft_printf("100%%"); }
static int	rig_percent2_std(void) { return printf("100%%"); }

static int	rig_percent3_ft(void) { return ft_printf("%%%%"); }
static int	rig_percent3_std(void) { return printf("%%%%"); }

static int	rig_percent4_ft(void) { return ft_printf("%%%d%%", 50); }
static int	rig_percent4_std(void) { return printf("%%%d%%", 50); }

static int	rig_percent5_ft(void) { return ft_printf("%d%%", 100); }
static int	rig_percent5_std(void) { return printf("%d%%", 100); }

// ========== RETURN VALUE TESTS (EXACT BYTE COUNT) ==========
static int	rig_ret1_ft(void) { return ft_printf(""); }
static int	rig_ret1_std(void) { return printf(""); }

static int	rig_ret2_ft(void) { return ft_printf("a"); }
static int	rig_ret2_std(void) { return printf("a"); }

static int	rig_ret3_ft(void) { return ft_printf("hello"); }
static int	rig_ret3_std(void) { return printf("hello"); }

static int	rig_ret4_ft(void) { return ft_printf("%d", 0); }
static int	rig_ret4_std(void) { return printf("%d", 0); }

static int	rig_ret5_ft(void) { return ft_printf("%10d", 5); }
static int	rig_ret5_std(void) { return printf("%10d", 5); }

// ========== INT_MAX AND INT_MIN EDGE CASES ==========
static int	rig_intmax1_ft(void) { return ft_printf("%d", INT_MAX); }
static int	rig_intmax1_std(void) { return printf("%d", INT_MAX); }

static int	rig_intmax2_ft(void) { return ft_printf("%d", INT_MIN); }
static int	rig_intmax2_std(void) { return printf("%d", INT_MIN); }

static int	rig_intmax3_ft(void) { return ft_printf("%+d", INT_MAX); }
static int	rig_intmax3_std(void) { return printf("%+d", INT_MAX); }

static int	rig_intmax4_ft(void) { return ft_printf("% d", INT_MIN); }
static int	rig_intmax4_std(void) { return printf("% d", INT_MIN); }

static int	rig_intmax5_ft(void) { return ft_printf("%20d", INT_MAX); }
static int	rig_intmax5_std(void) { return printf("%20d", INT_MAX); }

// ========== UNSIGNED EDGE CASES ==========
static int	rig_umax1_ft(void) { return ft_printf("%u", 4294967295U); }
static int	rig_umax1_std(void) { return printf("%u", 4294967295U); }

static int	rig_umax2_ft(void) { return ft_printf("%x", 4294967295U); }
static int	rig_umax2_std(void) { return printf("%x", 4294967295U); }

static int	rig_umax3_ft(void) { return ft_printf("%o", 4294967295U); }
static int	rig_umax3_std(void) { return printf("%o", 4294967295U); }

static int	rig_umax4_ft(void) { return ft_printf("%#x", 4294967295U); }
static int	rig_umax4_std(void) { return printf("%#x", 4294967295U); }

static int	rig_umax5_ft(void) { return ft_printf("%#o", 4294967295U); }
static int	rig_umax5_std(void) { return printf("%#o", 4294967295U); }

// ========== CONFLICTING FLAGS (PLUS OVERRIDES SPACE) ==========
static int	rig_conflict1_ft(void) { return ft_printf("% +d", 42); }
static int	rig_conflict1_std(void) { return printf("% +d", 42); }

static int	rig_conflict2_ft(void) { return ft_printf("%+ d", 42); }
static int	rig_conflict2_std(void) { return printf("%+ d", 42); }

static int	rig_conflict3_ft(void) { return ft_printf("% +d", -42); }
static int	rig_conflict3_std(void) { return printf("% +d", -42); }

static int	rig_conflict4_ft(void) { return ft_printf("%0-d", 42); }
static int	rig_conflict4_std(void) { return printf("%0-d", 42); }

static int	rig_conflict5_ft(void) { return ft_printf("%-0d", -42); }
static int	rig_conflict5_std(void) { return printf("%-0d", -42); }

// ========== ZERO VALUE WITH FLAGS ==========
static int	rig_zero_flag1_ft(void) { return ft_printf("%+d", 0); }
static int	rig_zero_flag1_std(void) { return printf("%+d", 0); }

static int	rig_zero_flag2_ft(void) { return ft_printf("% d", 0); }
static int	rig_zero_flag2_std(void) { return printf("% d", 0); }

static int	rig_zero_flag3_ft(void) { return ft_printf("%#x", 0); }
static int	rig_zero_flag3_std(void) { return printf("%#x", 0); }

static int	rig_zero_flag4_ft(void) { return ft_printf("%#o", 0); }
static int	rig_zero_flag4_std(void) { return printf("%#o", 0); }

static int	rig_zero_flag5_ft(void) { return ft_printf("%.0d", 0); }
static int	rig_zero_flag5_std(void) { return printf("%.0d", 0); }

// ========== NEGATIVE WIDTH (IMPLICIT LEFT ALIGN) ==========
static int	rig_negw1_ft(void) { return ft_printf("%*d", -10, 42); }
static int	rig_negw1_std(void) { return printf("%*d", -10, 42); }

static int	rig_negw2_ft(void) { return ft_printf("%*s", -15, "test"); }
static int	rig_negw2_std(void) { return printf("%*s", -15, "test"); }

static int	rig_negw3_ft(void) { return ft_printf("%*c", -5, 'A'); }
static int	rig_negw3_std(void) { return printf("%*c", -5, 'A'); }

static int	rig_negw4_ft(void) { return ft_printf("%*u", -12, 999); }
static int	rig_negw4_std(void) { return printf("%*u", -12, 999); }

static int	rig_negw5_ft(void) { return ft_printf("%*x", -10, 255); }
static int	rig_negw5_std(void) { return printf("%*x", -10, 255); }

// ========== NEGATIVE PRECISION (SHOULD IGNORE) ==========
static int	rig_negp1_ft(void) { return ft_printf("%.*s", -1, "ignored"); }
static int	rig_negp1_std(void) { return printf("%.*s", -1, "ignored"); }

static int	rig_negp2_ft(void) { return ft_printf("%.*d", -5, 42); }
static int	rig_negp2_std(void) { return printf("%.*d", -5, 42); }

// ========== VERY SPECIFIC COMBINATIONS ==========
static int	rig_combo1_ft(void) { return ft_printf("%+08d", 42); }
static int	rig_combo1_std(void) { return printf("%+08d", 42); }

static int	rig_combo2_ft(void) { return ft_printf("%+08d", -42); }
static int	rig_combo2_std(void) { return printf("%+08d", -42); }

static int	rig_combo3_ft(void) { return ft_printf("% 08d", 42); }
static int	rig_combo3_std(void) { return printf("% 08d", 42); }

static int	rig_combo4_ft(void) { return ft_printf("% 08d", -42); }
static int	rig_combo4_std(void) { return printf("% 08d", -42); }

static int	rig_combo5_ft(void) { return ft_printf("%#010x", 255); }
static int	rig_combo5_std(void) { return printf("%#010x", 255); }

// ========== CHAR AND STRING EDGE CASES ==========
static int	rig_char1_ft(void) { return ft_printf("%c", 0); }
static int	rig_char1_std(void) { return printf("%c", 0); }

static int	rig_char2_ft(void) { return ft_printf("%c", 255); }
static int	rig_char2_std(void) { return printf("%c", 255); }

static int	rig_char3_ft(void) { return ft_printf("%5c", 'A'); }
static int	rig_char3_std(void) { return printf("%5c", 'A'); }

static int	rig_char4_ft(void) { return ft_printf("%-5c", 'Z'); }
static int	rig_char4_std(void) { return printf("%-5c", 'Z'); }

static int	rig_char5_ft(void) { return ft_printf("%*c", 8, 'X'); }
static int	rig_char5_std(void) { return printf("%*c", 8, 'X'); }

// ========== LONG STRINGS AND PRECISION ==========
static int	rig_long1_ft(void) { return ft_printf("%.10s", "this is a very long string"); }
static int	rig_long1_std(void) { return printf("%.10s", "this is a very long string"); }

static int	rig_long2_ft(void) { return ft_printf("%20.10s", "truncated string here"); }
static int	rig_long2_std(void) { return printf("%20.10s", "truncated string here"); }

static int	rig_long3_ft(void) { return ft_printf("%-20.10s", "left aligned"); }
static int	rig_long3_std(void) { return printf("%-20.10s", "left aligned"); }

// ========== MIXED MULTIPLE FORMAT SPECIFIERS ==========
static int	rig_multi1_ft(void) { return ft_printf("%d %d %d %d %d", 1, 2, 3, 4, 5); }
static int	rig_multi1_std(void) { return printf("%d %d %d %d %d", 1, 2, 3, 4, 5); }

static int	rig_multi2_ft(void) { return ft_printf("%d%s%c%u%x", 1, "two", '3', 4, 5); }
static int	rig_multi2_std(void) { return printf("%d%s%c%u%x", 1, "two", '3', 4, 5); }

static int	rig_multi3_ft(void) { return ft_printf("%05d %10s %-8u", 42, "test", 99); }
static int	rig_multi3_std(void) { return printf("%05d %10s %-8u", 42, "test", 99); }

void	run_rigorous_tests(void)
{
	t_test_case	star[] = {
		{rig_star1_ft, rig_star1_std},
		{rig_star2_ft, rig_star2_std},
		{rig_star3_ft, rig_star3_std},
		{rig_star4_ft, rig_star4_std},
		{rig_star5_ft, rig_star5_std},
		{rig_star6_ft, rig_star6_std},
		{rig_star7_ft, rig_star7_std},
		{rig_star8_ft, rig_star8_std},
		{rig_star9_ft, rig_star9_std},
		{rig_star10_ft, rig_star10_std},
	};
	t_test_case	prec_int[] = {
		{rig_prec_int1_ft, rig_prec_int1_std},
		{rig_prec_int2_ft, rig_prec_int2_std},
		{rig_prec_int3_ft, rig_prec_int3_std},
		{rig_prec_int4_ft, rig_prec_int4_std},
		{rig_prec_int5_ft, rig_prec_int5_std},
	};
	t_test_case	percent[] = {
		{rig_percent1_ft, rig_percent1_std},
		{rig_percent2_ft, rig_percent2_std},
		{rig_percent3_ft, rig_percent3_std},
		{rig_percent4_ft, rig_percent4_std},
		{rig_percent5_ft, rig_percent5_std},
	};
	t_test_case	ret[] = {
		{rig_ret1_ft, rig_ret1_std},
		{rig_ret2_ft, rig_ret2_std},
		{rig_ret3_ft, rig_ret3_std},
		{rig_ret4_ft, rig_ret4_std},
		{rig_ret5_ft, rig_ret5_std},
	};
	t_test_case	intmax[] = {
		{rig_intmax1_ft, rig_intmax1_std},
		{rig_intmax2_ft, rig_intmax2_std},
		{rig_intmax3_ft, rig_intmax3_std},
		{rig_intmax4_ft, rig_intmax4_std},
		{rig_intmax5_ft, rig_intmax5_std},
	};
	t_test_case	umax[] = {
		{rig_umax1_ft, rig_umax1_std},
		{rig_umax2_ft, rig_umax2_std},
		{rig_umax3_ft, rig_umax3_std},
		{rig_umax4_ft, rig_umax4_std},
		{rig_umax5_ft, rig_umax5_std},
	};
	t_test_case	conflict[] = {
		{rig_conflict1_ft, rig_conflict1_std},
		{rig_conflict2_ft, rig_conflict2_std},
		{rig_conflict3_ft, rig_conflict3_std},
		{rig_conflict4_ft, rig_conflict4_std},
		{rig_conflict5_ft, rig_conflict5_std},
	};
	t_test_case	zero_flag[] = {
		{rig_zero_flag1_ft, rig_zero_flag1_std},
		{rig_zero_flag2_ft, rig_zero_flag2_std},
		{rig_zero_flag3_ft, rig_zero_flag3_std},
		{rig_zero_flag4_ft, rig_zero_flag4_std},
		{rig_zero_flag5_ft, rig_zero_flag5_std},
	};
	t_test_case	negw[] = {
		{rig_negw1_ft, rig_negw1_std},
		{rig_negw2_ft, rig_negw2_std},
		{rig_negw3_ft, rig_negw3_std},
		{rig_negw4_ft, rig_negw4_std},
		{rig_negw5_ft, rig_negw5_std},
	};
	t_test_case	negp[] = {
		{rig_negp1_ft, rig_negp1_std},
		{rig_negp2_ft, rig_negp2_std},
	};
	t_test_case	combo[] = {
		{rig_combo1_ft, rig_combo1_std},
		{rig_combo2_ft, rig_combo2_std},
		{rig_combo3_ft, rig_combo3_std},
		{rig_combo4_ft, rig_combo4_std},
		{rig_combo5_ft, rig_combo5_std},
	};
	t_test_case	chars[] = {
		{rig_char1_ft, rig_char1_std},
		{rig_char2_ft, rig_char2_std},
		{rig_char3_ft, rig_char3_std},
		{rig_char4_ft, rig_char4_std},
		{rig_char5_ft, rig_char5_std},
	};
	t_test_case	longstr[] = {
		{rig_long1_ft, rig_long1_std},
		{rig_long2_ft, rig_long2_std},
		{rig_long3_ft, rig_long3_std},
	};
	t_test_case	multi[] = {
		{rig_multi1_ft, rig_multi1_std},
		{rig_multi2_ft, rig_multi2_std},
		{rig_multi3_ft, rig_multi3_std},
	};
	t_test_group	groups[] = {
		{"Star Width/Precision (*)", star, 10},
		{"Precision with Integers", prec_int, 5},
		{"Percent Signs (%)", percent, 5},
		{"Return Value Accuracy", ret, 5},
		{"INT_MAX/INT_MIN", intmax, 5},
		{"UINT_MAX Edge Cases", umax, 5},
		{"Conflicting Flags", conflict, 5},
		{"Zero Value with Flags", zero_flag, 5},
		{"Negative Width", negw, 5},
		{"Negative Precision", negp, 2},
		{"Specific Combinations", combo, 5},
		{"Char Edge Cases", chars, 5},
		{"Long Strings & Precision", longstr, 3},
		{"Multiple Specifiers", multi, 3},
	};

	print_grouped_results("Edge Cases & Limits", groups, 14);
}

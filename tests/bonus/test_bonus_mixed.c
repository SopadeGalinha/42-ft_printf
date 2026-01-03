#include "bonus_tests.h"
#include "../../ft_printf.h"
#include <stdio.h>
#include <limits.h>

// ========== HASH FLAG (#) ==========
static int	bm_hash1_ft(void) { return ft_printf("%#x", 255); }
static int	bm_hash1_std(void) { return printf("%#x", 255); }

static int	bm_hash2_ft(void) { return ft_printf("%#X", 255); }
static int	bm_hash2_std(void) { return printf("%#X", 255); }

static int	bm_hash3_ft(void) { return ft_printf("%#o", 64); }
static int	bm_hash3_std(void) { return printf("%#o", 64); }

static int	bm_hash4_ft(void) { return ft_printf("%#x", 0); }
static int	bm_hash4_std(void) { return printf("%#x", 0); }

static int	bm_hash5_ft(void) { return ft_printf("%#o", 0); }
static int	bm_hash5_std(void) { return printf("%#o", 0); }

// ========== SPACE FLAG (space) ==========
static int	bm_space1_ft(void) { return ft_printf("% d", 42); }
static int	bm_space1_std(void) { return printf("% d", 42); }

static int	bm_space2_ft(void) { return ft_printf("% d", -42); }
static int	bm_space2_std(void) { return printf("% d", -42); }

static int	bm_space3_ft(void) { return ft_printf("% 5d", 99); }
static int	bm_space3_std(void) { return printf("% 5d", 99); }

static int	bm_space4_ft(void) { return ft_printf("% i", 0); }
static int	bm_space4_std(void) { return printf("% i", 0); }

static int	bm_space5_ft(void) { return ft_printf("% 10d", -777); }
static int	bm_space5_std(void) { return printf("% 10d", -777); }

// ========== COMBINED FLAGS (WIDTH + PRECISION) ==========
static int	bm_comb1_ft(void) { return ft_printf("%10.5s", "hello world"); }
static int	bm_comb1_std(void) { return printf("%10.5s", "hello world"); }

static int	bm_comb2_ft(void) { return ft_printf("%-10.3s", "testing"); }
static int	bm_comb2_std(void) { return printf("%-10.3s", "testing"); }

static int	bm_comb3_ft(void) { return ft_printf("%8.5d", 12345); }
static int	bm_comb3_std(void) { return printf("%8.5d", 12345); }

static int	bm_comb4_ft(void) { return ft_printf("%+8d", 42); }
static int	bm_comb4_std(void) { return printf("%+8d", 42); }

static int	bm_comb5_ft(void) { return ft_printf("%010d", 999); }
static int	bm_comb5_std(void) { return printf("%010d", 999); }

// ========== MIXED TYPES WITH FLAGS ==========
static int	bm_mix1_ft(void) { return ft_printf("%5d %10s", 42, "test"); }
static int	bm_mix1_std(void) { return printf("%5d %10s", 42, "test"); }

static int	bm_mix2_ft(void) { return ft_printf("%-8c %+5d", 'A', 99); }
static int	bm_mix2_std(void) { return printf("%-8c %+5d", 'A', 99); }

static int	bm_mix3_ft(void) { return ft_printf("%#x %08u", 255, 100); }
static int	bm_mix3_std(void) { return printf("%#x %08u", 255, 100); }

static int	bm_mix4_ft(void) { return ft_printf("%.5s %05d %#o", "hello", 42, 64); }
static int	bm_mix4_std(void) { return printf("%.5s %05d %#o", "hello", 42, 64); }

static int	bm_mix5_ft(void) { return ft_printf("%+d % d %-5d", 1, 2, 3); }
static int	bm_mix5_std(void) { return printf("%+d % d %-5d", 1, 2, 3); }

// ========== EDGE CASES WITH FLAGS ==========
static int	bm_edge1_ft(void) { return ft_printf("%05d", -42); }
static int	bm_edge1_std(void) { return printf("%05d", -42); }

static int	bm_edge2_ft(void) { return ft_printf("%-5d", -99); }
static int	bm_edge2_std(void) { return printf("%-5d", -99); }

static int	bm_edge3_ft(void) { return ft_printf("%+05d", 123); }
static int	bm_edge3_std(void) { return printf("%+05d", 123); }

static int	bm_edge4_ft(void) { return ft_printf("%.10s", "test"); }
static int	bm_edge4_std(void) { return printf("%.10s", "test"); }

static int	bm_edge5_ft(void) { return ft_printf("%0-5d", 42); }
static int	bm_edge5_std(void) { return printf("%0-5d", 42); }

// ========== ALL SPECIFIERS WITH FLAGS ==========
static int	bm_all1_ft(void) { return ft_printf("%5d %05u %#x %s", 42, 100, 255, "test"); }
static int	bm_all1_std(void) { return printf("%5d %05u %#x %s", 42, 100, 255, "test"); }

static int	bm_all2_ft(void) { return ft_printf("%-8c %+10i %.5s %#o", 'A', -50, "hello", 64); }
static int	bm_all2_std(void) { return printf("%-8c %+10i %.5s %#o", 'A', -50, "hello", 64); }

static int	bm_all3_ft(void) { int x = 7; return ft_printf("%p %5d %08x %+i", (void *)&x, 7, 7, 7); }
static int	bm_all3_std(void) { int x = 7; return printf("%p %5d %08x %+i", (void *)&x, 7, 7, 7); }

static int	bm_all4_ft(void) { return ft_printf("[%5d][%-10s][%#x][%05u]", 99, "flag", 128, 256); }
static int	bm_all4_std(void) { return printf("[%5d][%-10s][%#x][%05u]", 99, "flag", 128, 256); }

static int	bm_all5_ft(void) { return ft_printf("%+d % d %#o %X %.3s", 10, 20, 30, 40, "precision"); }
static int	bm_all5_std(void) { return printf("%+d % d %#o %X %.3s", 10, 20, 30, 40, "precision"); }

void	run_bonus_mixed_tests(void)
{
	t_test_case	hash[] = {
		{bm_hash1_ft, bm_hash1_std},
		{bm_hash2_ft, bm_hash2_std},
		{bm_hash3_ft, bm_hash3_std},
		{bm_hash4_ft, bm_hash4_std},
		{bm_hash5_ft, bm_hash5_std},
	};
	t_test_case	space[] = {
		{bm_space1_ft, bm_space1_std},
		{bm_space2_ft, bm_space2_std},
		{bm_space3_ft, bm_space3_std},
		{bm_space4_ft, bm_space4_std},
		{bm_space5_ft, bm_space5_std},
	};
	t_test_case	comb[] = {
		{bm_comb1_ft, bm_comb1_std},
		{bm_comb2_ft, bm_comb2_std},
		{bm_comb3_ft, bm_comb3_std},
		{bm_comb4_ft, bm_comb4_std},
		{bm_comb5_ft, bm_comb5_std},
	};
	t_test_case	mix[] = {
		{bm_mix1_ft, bm_mix1_std},
		{bm_mix2_ft, bm_mix2_std},
		{bm_mix3_ft, bm_mix3_std},
		{bm_mix4_ft, bm_mix4_std},
		{bm_mix5_ft, bm_mix5_std},
	};
	t_test_case	edge[] = {
		{bm_edge1_ft, bm_edge1_std},
		{bm_edge2_ft, bm_edge2_std},
		{bm_edge3_ft, bm_edge3_std},
		{bm_edge4_ft, bm_edge4_std},
		{bm_edge5_ft, bm_edge5_std},
	};
	t_test_case	all[] = {
		{bm_all1_ft, bm_all1_std},
		{bm_all2_ft, bm_all2_std},
		{bm_all3_ft, bm_all3_std},
		{bm_all4_ft, bm_all4_std},
		{bm_all5_ft, bm_all5_std},
	};
	t_test_group	groups[] = {
		{"Hash Flag (#)", hash, 5},
		{"Space Flag (space)", space, 5},
		{"Width + Precision", comb, 5},
		{"Mixed Types with Flags", mix, 5},
		{"Edge Cases with Flags", edge, 5},
		{"All Specifiers + Flags", all, 5},
	};

	print_grouped_results("Mixed Flag Combinations", groups, 6);
}

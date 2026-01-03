#include "bonus_tests.h"
#include "../../ft_printf.h"
#include <stdio.h>
#include <limits.h>

// ========== ZERO PAD WITH DIFFERENT WIDTHS ==========
static int	bx_zero_w1_ft(void) { return ft_printf("%010d", 42); }
static int	bx_zero_w1_std(void) { return printf("%010d", 42); }

static int	bx_zero_w2_ft(void) { return ft_printf("%015d", 100); }
static int	bx_zero_w2_std(void) { return printf("%015d", 100); }

static int	bx_zero_w3_ft(void) { return ft_printf("%020d", -999); }
static int	bx_zero_w3_std(void) { return printf("%020d", -999); }

static int	bx_zero_w4_ft(void) { return ft_printf("%08u", 12345); }
static int	bx_zero_w4_std(void) { return printf("%08u", 12345); }

static int	bx_zero_w5_ft(void) { return ft_printf("%012x", 0xDEADBEEF); }
static int	bx_zero_w5_std(void) { return printf("%012x", 0xDEADBEEF); }

static int	bx_zero_w6_ft(void) { return ft_printf("%010o", 512); }
static int	bx_zero_w6_std(void) { return printf("%010o", 512); }

static int	bx_zero_w7_ft(void) { return ft_printf("%015i", -42); }
static int	bx_zero_w7_std(void) { return printf("%015i", -42); }

static int	bx_zero_w8_ft(void) { return ft_printf("%09X", 255); }
static int	bx_zero_w8_std(void) { return printf("%09X", 255); }

static int	bx_zero_w9_ft(void) { return ft_printf("%020u", 1234567); }
static int	bx_zero_w9_std(void) { return printf("%020u", 1234567); }

static int	bx_zero_w10_ft(void) { return ft_printf("%014d", 888); }
static int	bx_zero_w10_std(void) { return printf("%014d", 888); }

// ========== LEFT ALIGN WITH VARIOUS WIDTHS ==========
static int	bx_left_w1_ft(void) { return ft_printf("%-10d", 42); }
static int	bx_left_w1_std(void) { return printf("%-10d", 42); }

static int	bx_left_w2_ft(void) { return ft_printf("%-15d", -100); }
static int	bx_left_w2_std(void) { return printf("%-15d", -100); }

static int	bx_left_w3_ft(void) { return ft_printf("%-20s", "aligned"); }
static int	bx_left_w3_std(void) { return printf("%-20s", "aligned"); }

static int	bx_left_w4_ft(void) { return ft_printf("%-12u", 65535); }
static int	bx_left_w4_std(void) { return printf("%-12u", 65535); }

static int	bx_left_w5_ft(void) { return ft_printf("%-14x", 0xCAFEBABE); }
static int	bx_left_w5_std(void) { return printf("%-14x", 0xCAFEBABE); }

static int	bx_left_w6_ft(void) { return ft_printf("%-18o", 777); }
static int	bx_left_w6_std(void) { return printf("%-18o", 777); }

static int	bx_left_w7_ft(void) { return ft_printf("%-16i", -1234); }
static int	bx_left_w7_std(void) { return printf("%-16i", -1234); }

static int	bx_left_w8_ft(void) { return ft_printf("%-11X", 100); }
static int	bx_left_w8_std(void) { return printf("%-11X", 100); }

static int	bx_left_w9_ft(void) { return ft_printf("%-10c", 'M'); }
static int	bx_left_w9_std(void) { return printf("%-10c", 'M'); }

static int	bx_left_w10_ft(void) { return ft_printf("%-25s", "left align string"); }
static int	bx_left_w10_std(void) { return printf("%-25s", "left align string"); }

// ========== PLUS SIGN WITH WIDTHS ==========
static int	bx_plus_w1_ft(void) { return ft_printf("%+d", 42); }
static int	bx_plus_w1_std(void) { return printf("%+d", 42); }

static int	bx_plus_w2_ft(void) { return ft_printf("%+10d", 42); }
static int	bx_plus_w2_std(void) { return printf("%+10d", 42); }

static int	bx_plus_w3_ft(void) { return ft_printf("%+d", -42); }
static int	bx_plus_w3_std(void) { return printf("%+d", -42); }

static int	bx_plus_w4_ft(void) { return ft_printf("%+15i", -999); }
static int	bx_plus_w4_std(void) { return printf("%+15i", -999); }

static int	bx_plus_w5_ft(void) { return ft_printf("%+i", 0); }
static int	bx_plus_w5_std(void) { return printf("%+i", 0); }

static int	bx_plus_w6_ft(void) { return ft_printf("%+20d", 123456); }
static int	bx_plus_w6_std(void) { return printf("%+20d", 123456); }

static int	bx_plus_w7_ft(void) { return ft_printf("%+8d", 5); }
static int	bx_plus_w7_std(void) { return printf("%+8d", 5); }

static int	bx_plus_w8_ft(void) { return ft_printf("%+12i", -12345); }
static int	bx_plus_w8_std(void) { return printf("%+12i", -12345); }

static int	bx_plus_w9_ft(void) { return ft_printf("%+5d", 1); }
static int	bx_plus_w9_std(void) { return printf("%+5d", 1); }

static int	bx_plus_w10_ft(void) { return ft_printf("%+18d", 9999); }
static int	bx_plus_w10_std(void) { return printf("%+18d", 9999); }

// ========== SPACE FLAG WITH WIDTHS ==========
static int	bx_space_w1_ft(void) { return ft_printf("% d", 42); }
static int	bx_space_w1_std(void) { return printf("% d", 42); }

static int	bx_space_w2_ft(void) { return ft_printf("% 10d", 100); }
static int	bx_space_w2_std(void) { return printf("% 10d", 100); }

static int	bx_space_w3_ft(void) { return ft_printf("% d", -42); }
static int	bx_space_w3_std(void) { return printf("% d", -42); }

static int	bx_space_w4_ft(void) { return ft_printf("% 15i", 777); }
static int	bx_space_w4_std(void) { return printf("% 15i", 777); }

static int	bx_space_w5_ft(void) { return ft_printf("% i", 0); }
static int	bx_space_w5_std(void) { return printf("% i", 0); }

static int	bx_space_w6_ft(void) { return ft_printf("% 20d", 1234567); }
static int	bx_space_w6_std(void) { return printf("% 20d", 1234567); }

static int	bx_space_w7_ft(void) { return ft_printf("% 8d", 9); }
static int	bx_space_w7_std(void) { return printf("% 8d", 9); }

static int	bx_space_w8_ft(void) { return ft_printf("% 12i", -54321); }
static int	bx_space_w8_std(void) { return printf("% 12i", -54321); }

static int	bx_space_w9_ft(void) { return ft_printf("% 5d", 55); }
static int	bx_space_w9_std(void) { return printf("% 5d", 55); }

static int	bx_space_w10_ft(void) { return ft_printf("% 18d", 88888); }
static int	bx_space_w10_std(void) { return printf("% 18d", 88888); }

// ========== HASH FLAG WITH WIDTHS ==========
static int	bx_hash_w1_ft(void) { return ft_printf("%#x", 255); }
static int	bx_hash_w1_std(void) { return printf("%#x", 255); }

static int	bx_hash_w2_ft(void) { return ft_printf("%#12x", 0xBEEF); }
static int	bx_hash_w2_std(void) { return printf("%#12x", 0xBEEF); }

static int	bx_hash_w3_ft(void) { return ft_printf("%#X", 0xDEAD); }
static int	bx_hash_w3_std(void) { return printf("%#X", 0xDEAD); }

static int	bx_hash_w4_ft(void) { return ft_printf("%#15X", 0xCAFE); }
static int	bx_hash_w4_std(void) { return printf("%#15X", 0xCAFE); }

static int	bx_hash_w5_ft(void) { return ft_printf("%#o", 512); }
static int	bx_hash_w5_std(void) { return printf("%#o", 512); }

static int	bx_hash_w6_ft(void) { return ft_printf("%#18o", 4096); }
static int	bx_hash_w6_std(void) { return printf("%#18o", 4096); }

static int	bx_hash_w7_ft(void) { return ft_printf("%#x", 0); }
static int	bx_hash_w7_std(void) { return printf("%#x", 0); }

static int	bx_hash_w8_ft(void) { return ft_printf("%#10o", 0); }
static int	bx_hash_w8_std(void) { return printf("%#10o", 0); }

static int	bx_hash_w9_ft(void) { return ft_printf("%#08x", 100); }
static int	bx_hash_w9_std(void) { return printf("%#08x", 100); }

static int	bx_hash_w10_ft(void) { return ft_printf("%#016X", 65535); }
static int	bx_hash_w10_std(void) { return printf("%#016X", 65535); }

// ========== COMBINED: ZERO + PLUS ==========
static int	bx_z_plus1_ft(void) { return ft_printf("%0+d", 42); }
static int	bx_z_plus1_std(void) { return printf("%0+d", 42); }

static int	bx_z_plus2_ft(void) { return ft_printf("%0+10d", 42); }
static int	bx_z_plus2_std(void) { return printf("%0+10d", 42); }

static int	bx_z_plus3_ft(void) { return ft_printf("%+010d", -99); }
static int	bx_z_plus3_std(void) { return printf("%+010d", -99); }

static int	bx_z_plus4_ft(void) { return ft_printf("%0+15i", 777); }
static int	bx_z_plus4_std(void) { return printf("%0+15i", 777); }

static int	bx_z_plus5_ft(void) { return ft_printf("%+08i", 0); }
static int	bx_z_plus5_std(void) { return printf("%+08i", 0); }

// ========== COMBINED: ZERO + SPACE ==========
static int	bx_z_space1_ft(void) { return ft_printf("%0 d", 42); }
static int	bx_z_space1_std(void) { return printf("%0 d", 42); }

static int	bx_z_space2_ft(void) { return ft_printf("%0 10d", 100); }
static int	bx_z_space2_std(void) { return printf("%0 10d", 100); }

static int	bx_z_space3_ft(void) { return ft_printf("% 010d", -50); }
static int	bx_z_space3_std(void) { return printf("% 010d", -50); }

static int	bx_z_space4_ft(void) { return ft_printf("% 015i", 888); }
static int	bx_z_space4_std(void) { return printf("% 015i", 888); }

static int	bx_z_space5_ft(void) { return ft_printf("% 08d", 0); }
static int	bx_z_space5_std(void) { return printf("% 08d", 0); }

// ========== COMBINED: LEFT + PLUS ==========
static int	bx_l_plus1_ft(void) { return ft_printf("%-+d", 42); }
static int	bx_l_plus1_std(void) { return printf("%-+d", 42); }

static int	bx_l_plus2_ft(void) { return ft_printf("%-+10d", -99); }
static int	bx_l_plus2_std(void) { return printf("%-+10d", -99); }

static int	bx_l_plus3_ft(void) { return ft_printf("%+-15d", 555); }
static int	bx_l_plus3_std(void) { return printf("%+-15d", 555); }

static int	bx_l_plus4_ft(void) { return ft_printf("%-+8i", -7); }
static int	bx_l_plus4_std(void) { return printf("%-+8i", -7); }

static int	bx_l_plus5_ft(void) { return ft_printf("%+-20d", 0); }
static int	bx_l_plus5_std(void) { return printf("%+-20d", 0); }

// ========== COMBINED: LEFT + SPACE ==========
static int	bx_l_space1_ft(void) { return ft_printf("%- d", 42); }
static int	bx_l_space1_std(void) { return printf("%- d", 42); }

static int	bx_l_space2_ft(void) { return ft_printf("%- 10d", 100); }
static int	bx_l_space2_std(void) { return printf("%- 10d", 100); }

static int	bx_l_space3_ft(void) { return ft_printf("% -12d", -333); }
static int	bx_l_space3_std(void) { return printf("% -12d", -333); }

static int	bx_l_space4_ft(void) { return ft_printf("%-  8i", 444); }
static int	bx_l_space4_std(void) { return printf("%-  8i", 444); }

static int	bx_l_space5_ft(void) { return ft_printf("% -15d", 0); }
static int	bx_l_space5_std(void) { return printf("% -15d", 0); }

// ========== COMBINED: LEFT + HASH ==========
static int	bx_l_hash1_ft(void) { return ft_printf("%-#x", 255); }
static int	bx_l_hash1_std(void) { return printf("%-#x", 255); }

static int	bx_l_hash2_ft(void) { return ft_printf("%-#12x", 0xBEEF); }
static int	bx_l_hash2_std(void) { return printf("%-#12x", 0xBEEF); }

static int	bx_l_hash3_ft(void) { return ft_printf("%#-15X", 0xCAFE); }
static int	bx_l_hash3_std(void) { return printf("%#-15X", 0xCAFE); }

static int	bx_l_hash4_ft(void) { return ft_printf("%-#10o", 512); }
static int	bx_l_hash4_std(void) { return printf("%-#10o", 512); }

static int	bx_l_hash5_ft(void) { return ft_printf("%#-18o", 4096); }
static int	bx_l_hash5_std(void) { return printf("%#-18o", 4096); }

// ========== PRECISION WITH FLAGS ==========
static int	bx_prec1_ft(void) { return ft_printf("%.10s", "precision test"); }
static int	bx_prec1_std(void) { return printf("%.10s", "precision test"); }

static int	bx_prec2_ft(void) { return ft_printf("%10.5s", "strings"); }
static int	bx_prec2_std(void) { return printf("%10.5s", "strings"); }

static int	bx_prec3_ft(void) { return ft_printf("%-10.3s", "testing"); }
static int	bx_prec3_std(void) { return printf("%-10.3s", "testing"); }

static int	bx_prec4_ft(void) { return ft_printf("%8.2d", 42); }
static int	bx_prec4_std(void) { return printf("%8.2d", 42); }

static int	bx_prec5_ft(void) { return ft_printf("%+8.3d", 123); }
static int	bx_prec5_std(void) { return printf("%+8.3d", 123); }

// ========== TRIPLE COMBINATIONS ==========
static int	bx_triple1_ft(void) { return ft_printf("%0+10d", 42); }
static int	bx_triple1_std(void) { return printf("%0+10d", 42); }

static int	bx_triple2_ft(void) { return ft_printf("%-+ 10d", -42); }
static int	bx_triple2_std(void) { return printf("%-+ 10d", -42); }

static int	bx_triple3_ft(void) { return ft_printf("%#-10x", 255); }
static int	bx_triple3_std(void) { return printf("%#-10x", 255); }

static int	bx_triple4_ft(void) { return ft_printf("% 010d", 99); }
static int	bx_triple4_std(void) { return printf("% 010d", 99); }

static int	bx_triple5_ft(void) { return ft_printf("%+-10d", -100); }
static int	bx_triple5_std(void) { return printf("%+-10d", -100); }

void	run_bonus_comprehensive_tests(void)
{
	t_test_case	zero_w[] = {
		{bx_zero_w1_ft, bx_zero_w1_std},
		{bx_zero_w2_ft, bx_zero_w2_std},
		{bx_zero_w3_ft, bx_zero_w3_std},
		{bx_zero_w4_ft, bx_zero_w4_std},
		{bx_zero_w5_ft, bx_zero_w5_std},
		{bx_zero_w6_ft, bx_zero_w6_std},
		{bx_zero_w7_ft, bx_zero_w7_std},
		{bx_zero_w8_ft, bx_zero_w8_std},
		{bx_zero_w9_ft, bx_zero_w9_std},
		{bx_zero_w10_ft, bx_zero_w10_std},
	};
	t_test_case	left_w[] = {
		{bx_left_w1_ft, bx_left_w1_std},
		{bx_left_w2_ft, bx_left_w2_std},
		{bx_left_w3_ft, bx_left_w3_std},
		{bx_left_w4_ft, bx_left_w4_std},
		{bx_left_w5_ft, bx_left_w5_std},
		{bx_left_w6_ft, bx_left_w6_std},
		{bx_left_w7_ft, bx_left_w7_std},
		{bx_left_w8_ft, bx_left_w8_std},
		{bx_left_w9_ft, bx_left_w9_std},
		{bx_left_w10_ft, bx_left_w10_std},
	};
	t_test_case	plus_w[] = {
		{bx_plus_w1_ft, bx_plus_w1_std},
		{bx_plus_w2_ft, bx_plus_w2_std},
		{bx_plus_w3_ft, bx_plus_w3_std},
		{bx_plus_w4_ft, bx_plus_w4_std},
		{bx_plus_w5_ft, bx_plus_w5_std},
		{bx_plus_w6_ft, bx_plus_w6_std},
		{bx_plus_w7_ft, bx_plus_w7_std},
		{bx_plus_w8_ft, bx_plus_w8_std},
		{bx_plus_w9_ft, bx_plus_w9_std},
		{bx_plus_w10_ft, bx_plus_w10_std},
	};
	t_test_case	space_w[] = {
		{bx_space_w1_ft, bx_space_w1_std},
		{bx_space_w2_ft, bx_space_w2_std},
		{bx_space_w3_ft, bx_space_w3_std},
		{bx_space_w4_ft, bx_space_w4_std},
		{bx_space_w5_ft, bx_space_w5_std},
		{bx_space_w6_ft, bx_space_w6_std},
		{bx_space_w7_ft, bx_space_w7_std},
		{bx_space_w8_ft, bx_space_w8_std},
		{bx_space_w9_ft, bx_space_w9_std},
		{bx_space_w10_ft, bx_space_w10_std},
	};
	t_test_case	hash_w[] = {
		{bx_hash_w1_ft, bx_hash_w1_std},
		{bx_hash_w2_ft, bx_hash_w2_std},
		{bx_hash_w3_ft, bx_hash_w3_std},
		{bx_hash_w4_ft, bx_hash_w4_std},
		{bx_hash_w5_ft, bx_hash_w5_std},
		{bx_hash_w6_ft, bx_hash_w6_std},
		{bx_hash_w7_ft, bx_hash_w7_std},
		{bx_hash_w8_ft, bx_hash_w8_std},
		{bx_hash_w9_ft, bx_hash_w9_std},
		{bx_hash_w10_ft, bx_hash_w10_std},
	};
	t_test_case	z_plus[] = {
		{bx_z_plus1_ft, bx_z_plus1_std},
		{bx_z_plus2_ft, bx_z_plus2_std},
		{bx_z_plus3_ft, bx_z_plus3_std},
		{bx_z_plus4_ft, bx_z_plus4_std},
		{bx_z_plus5_ft, bx_z_plus5_std},
	};
	t_test_case	z_space[] = {
		{bx_z_space1_ft, bx_z_space1_std},
		{bx_z_space2_ft, bx_z_space2_std},
		{bx_z_space3_ft, bx_z_space3_std},
		{bx_z_space4_ft, bx_z_space4_std},
		{bx_z_space5_ft, bx_z_space5_std},
	};
	t_test_case	l_plus[] = {
		{bx_l_plus1_ft, bx_l_plus1_std},
		{bx_l_plus2_ft, bx_l_plus2_std},
		{bx_l_plus3_ft, bx_l_plus3_std},
		{bx_l_plus4_ft, bx_l_plus4_std},
		{bx_l_plus5_ft, bx_l_plus5_std},
	};
	t_test_case	l_space[] = {
		{bx_l_space1_ft, bx_l_space1_std},
		{bx_l_space2_ft, bx_l_space2_std},
		{bx_l_space3_ft, bx_l_space3_std},
		{bx_l_space4_ft, bx_l_space4_std},
		{bx_l_space5_ft, bx_l_space5_std},
	};
	t_test_case	l_hash[] = {
		{bx_l_hash1_ft, bx_l_hash1_std},
		{bx_l_hash2_ft, bx_l_hash2_std},
		{bx_l_hash3_ft, bx_l_hash3_std},
		{bx_l_hash4_ft, bx_l_hash4_std},
		{bx_l_hash5_ft, bx_l_hash5_std},
	};
	t_test_case	prec[] = {
		{bx_prec1_ft, bx_prec1_std},
		{bx_prec2_ft, bx_prec2_std},
		{bx_prec3_ft, bx_prec3_std},
		{bx_prec4_ft, bx_prec4_std},
		{bx_prec5_ft, bx_prec5_std},
	};
	t_test_case	triple[] = {
		{bx_triple1_ft, bx_triple1_std},
		{bx_triple2_ft, bx_triple2_std},
		{bx_triple3_ft, bx_triple3_std},
		{bx_triple4_ft, bx_triple4_std},
		{bx_triple5_ft, bx_triple5_std},
	};
	t_test_group	groups[] = {
		{"Zero Padding + Widths", zero_w, 10},
		{"Left Align + Widths", left_w, 10},
		{"Plus Sign + Widths", plus_w, 10},
		{"Space Flag + Widths", space_w, 10},
		{"Hash Flag + Widths", hash_w, 10},
		{"Zero + Plus", z_plus, 5},
		{"Zero + Space", z_space, 5},
		{"Left + Plus", l_plus, 5},
		{"Left + Space", l_space, 5},
		{"Left + Hash", l_hash, 5},
		{"Precision with Flags", prec, 5},
		{"Triple Combinations", triple, 5},
	};

	print_grouped_results("Advanced Flag Scenarios", groups, 12);
}

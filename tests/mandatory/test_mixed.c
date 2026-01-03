#include "tests.h"
#include "../../ft_printf.h"
#include <stdio.h>
#include <limits.h>

// ========== BASIC MIX (2 FLAGS) ==========
static int	m_mix1_ft(void) { return ft_printf("%d %c", 42, 'A'); }
static int	m_mix1_std(void) { return printf("%d %c", 42, 'A'); }

static int	m_mix2_ft(void) { return ft_printf("%s %d", "num", 100); }
static int	m_mix2_std(void) { return printf("%s %d", "num", 100); }

static int	m_mix3_ft(void) { return ft_printf("%c %s", 'H', "ello"); }
static int	m_mix3_std(void) { return printf("%c %s", 'H', "ello"); }

static int	m_mix4_ft(void) { return ft_printf("%u %x", 255, 255); }
static int	m_mix4_std(void) { return printf("%u %x", 255, 255); }

static int	m_mix5_ft(void) { return ft_printf("%x %o", 100, 100); }
static int	m_mix5_std(void) { return printf("%x %o", 100, 100); }

// ========== TRIPLE MIX (3 FLAGS) ==========
static int	m_trip1_ft(void) { return ft_printf("%d %c %s", 42, 'X', "test"); }
static int	m_trip1_std(void) { return printf("%d %c %s", 42, 'X', "test"); }

static int	m_trip2_ft(void) { return ft_printf("%s %u %x", "val", 50, 50); }
static int	m_trip2_std(void) { return printf("%s %u %x", "val", 50, 50); }

static int	m_trip3_ft(void) { return ft_printf("%c %d %o", 'Z', 77, 77); }
static int	m_trip3_std(void) { return printf("%c %d %o", 'Z', 77, 77); }

static int	m_trip4_ft(void) { return ft_printf("%i %x %u", -123, 123, 123); }
static int	m_trip4_std(void) { return printf("%i %x %u", -123, 123, 123); }

static int	m_trip5_ft(void) { return ft_printf("%s %c %d", "ABC", '1', 1); }
static int	m_trip5_std(void) { return printf("%s %c %d", "ABC", '1', 1); }

// ========== QUAD MIX (4 FLAGS) ==========
static int	m_quad1_ft(void) { return ft_printf("%d %s %c %u", 42, "test", 'X', 99); }
static int	m_quad1_std(void) { return printf("%d %s %c %u", 42, "test", 'X', 99); }

static int	m_quad2_ft(void) { return ft_printf("%c %x %o %d", 'A', 255, 255, -99); }
static int	m_quad2_std(void) { return printf("%c %x %o %d", 'A', 255, 255, -99); }

static int	m_quad3_ft(void) { return ft_printf("%i %u %x %s", -50, 50, 50, "hex"); }
static int	m_quad3_std(void) { return printf("%i %u %x %s", -50, 50, 50, "hex"); }

static int	m_quad4_ft(void) { return ft_printf("%s %d %c %o", "data", 8, '8', 8); }
static int	m_quad4_std(void) { return printf("%s %d %c %o", "data", 8, '8', 8); }

static int	m_quad5_ft(void) { int x = 5; return ft_printf("%p %d %s %c", (void *)&x, x, "ptr", 'P'); }
static int	m_quad5_std(void) { int x = 5; return printf("%p %d %s %c", (void *)&x, x, "ptr", 'P'); }

// ========== PENTA MIX (5 FLAGS) ==========
static int	m_pent1_ft(void) { return ft_printf("%d %c %s %u %x", 42, 'A', "mix", 99, 255); }
static int	m_pent1_std(void) { return printf("%d %c %s %u %x", 42, 'A', "mix", 99, 255); }

static int	m_pent2_ft(void) { return ft_printf("%s %d %x %o %c", "test", 100, 100, 100, 'T'); }
static int	m_pent2_std(void) { return printf("%s %d %x %o %c", "test", 100, 100, 100, 'T'); }

static int	m_pent3_ft(void) { return ft_printf("%i %u %c %s %x", -77, 77, '7', "seven", 77); }
static int	m_pent3_std(void) { return printf("%i %u %c %s %x", -77, 77, '7', "seven", 77); }

static int	m_pent4_ft(void) { return ft_printf("%c %d %o %u %s", 'M', 88, 88, 88, "mix"); }
static int	m_pent4_std(void) { return printf("%c %d %o %u %s", 'M', 88, 88, 88, "mix"); }

static int	m_pent5_ft(void) { return ft_printf("%x %o %d %c %s", 512, 512, 512, '5', "512"); }
static int	m_pent5_std(void) { return printf("%x %o %d %c %s", 512, 512, 512, '5', "512"); }

// ========== HEXA MIX (6 FLAGS) ==========
static int	m_hex1_ft(void) { return ft_printf("%d %c %s %u %x %o", 1, 'A', "six", 6, 6, 6); }
static int	m_hex1_std(void) { return printf("%d %c %s %u %x %o", 1, 'A', "six", 6, 6, 6); }

static int	m_hex2_ft(void) { return ft_printf("%i %u %x %o %c %s", -11, 11, 11, 11, '1', "one"); }
static int	m_hex2_std(void) { return printf("%i %u %x %o %c %s", -11, 11, 11, 11, '1', "one"); }

static int	m_hex3_ft(void) { return ft_printf("%s %d %c %x %o %u", "all", 99, 'A', 99, 99, 99); }
static int	m_hex3_std(void) { return printf("%s %d %c %x %o %u", "all", 99, 'A', 99, 99, 99); }

static int	m_hex4_ft(void) { return ft_printf("%c %x %u %d %o %s", 'H', 777, 777, -777, 777, "oct"); }
static int	m_hex4_std(void) { return printf("%c %x %u %d %o %s", 'H', 777, 777, -777, 777, "oct"); }

static int	m_hex5_ft(void) { return ft_printf("%u %x %o %d %s %c", 256, 256, 256, 256, "256", '2'); }
static int	m_hex5_std(void) { return printf("%u %x %o %d %s %c", 256, 256, 256, 256, "256", '2'); }

// ========== BINARY MIX (WITH %b) ==========
static int	m_bin1_ft(void) { return ft_printf("%d %b %x", 15, 15, 15); }
static int	m_bin1_std(void) { return printf("%d %b %x", 15, 15, 15); }

static int	m_bin2_ft(void) { return ft_printf("%b %o %d", 8, 8, 8); }
static int	m_bin2_std(void) { return printf("%b %o %d", 8, 8, 8); }

static int	m_bin3_ft(void) { return ft_printf("%s %b %u", "bin", 255, 255); }
static int	m_bin3_std(void) { return printf("%s %b %u", "bin", 255, 255); }

static int	m_bin4_ft(void) { return ft_printf("%c %b %x %d", 'B', 127, 127, 127); }
static int	m_bin4_std(void) { return printf("%c %b %x %d", 'B', 127, 127, 127); }

static int	m_bin5_ft(void) { return ft_printf("%b %u %o %x %s", 511, 511, 511, 511, "binary"); }
static int	m_bin5_std(void) { return printf("%b %u %o %x %s", 511, 511, 511, 511, "binary"); }

// ========== POINTER MIX ==========
static int	m_ptr1_ft(void) { int x = 1; return ft_printf("%p %d", (void *)&x, 42); }
static int	m_ptr1_std(void) { int x = 1; return printf("%p %d", (void *)&x, 42); }

static int	m_ptr2_ft(void) { char buf[10]; return ft_printf("%s %p %d", "addr", (void *)buf, 100); }
static int	m_ptr2_std(void) { char buf[10]; return printf("%s %p %d", "addr", (void *)buf, 100); }

static int	m_ptr3_ft(void) { return ft_printf("%p %c %u %s", (void *)1000, 'P', 1000, "ptr"); }
static int	m_ptr3_std(void) { return printf("%p %c %u %s", (void *)1000, 'P', 1000, "ptr"); }

static int	m_ptr4_ft(void) { return ft_printf("%d %p %x %c", 44, (void *)44, 44, '4'); }
static int	m_ptr4_std(void) { return printf("%d %p %x %c", 44, (void *)44, 44, '4'); }

static int	m_ptr5_ft(void) { return ft_printf("%p %s %d %u %c", NULL, "null", 0, 0, 'N'); }
static int	m_ptr5_std(void) { return printf("%p %s %d %u %c", NULL, "null", 0, 0, 'N'); }

// ========== COMPLEX (7+ FLAGS) ==========
static int	m_cmplx1_ft(void) { return ft_printf("%d%c%s%u%x%o%b", 1, 'C', "mix", 2, 3, 4, 5); }
static int	m_cmplx1_std(void) { return printf("%d%c%s%u%x%o%b", 1, 'C', "mix", 2, 3, 4, 5); }

static int	m_cmplx2_ft(void) { return ft_printf("D:%d C:%c S:%s U:%u X:%x O:%o B:%b", 10, 'X', "test", 20, 30, 40, 50); }
static int	m_cmplx2_std(void) { return printf("D:%d C:%c S:%s U:%u X:%x O:%o B:%b", 10, 'X', "test", 20, 30, 40, 50); }

static int	m_cmplx3_ft(void) { return ft_printf("%i %d %u %x %X %o %b", 99, -99, 99, 99, 99, 99, 99); }
static int	m_cmplx3_std(void) { return printf("%i %d %u %x %X %o %b", 99, -99, 99, 99, 99, 99, 99); }

static int	m_cmplx4_ft(void) { int x = 7; return ft_printf("%s %c %d %u %x %p %b", "full", 'F', -7, 7, 7, (void *)&x, 7); }
static int	m_cmplx4_std(void) { int x = 7; return printf("%s %c %d %u %x %p %b", "full", 'F', -7, 7, 7, (void *)&x, 7); }

static int	m_cmplx5_ft(void) { return ft_printf("[%d][%c][%s][%u][%x][%o][%i][%b]", 1, '2', "3", 4, 5, 6, -7, 8); }
static int	m_cmplx5_std(void) { return printf("[%d][%c][%s][%u][%x][%o][%i][%b]", 1, '2', "3", 4, 5, 6, -7, 8); }

// ========== EDGE CASES (SPECIAL CHARS) ==========
static int	m_edge1_ft(void) { return ft_printf("Line1\n%d\n%c\n%s", 42, 'E', "text"); }
static int	m_edge1_std(void) { return printf("Line1\n%d\n%c\n%s", 42, 'E', "text"); }

static int	m_edge2_ft(void) { return ft_printf("Tab\t%d\t%c\t%s", 100, 'T', "val"); }
static int	m_edge2_std(void) { return printf("Tab\t%d\t%c\t%s", 100, 'T', "val"); }

static int	m_edge3_ft(void) { return ft_printf("100%% %d %c %s", 50, '%', "percent"); }
static int	m_edge3_std(void) { return printf("100%% %d %c %s", 50, '%', "percent"); }

static int	m_edge4_ft(void) { return ft_printf("%d!%c?%s.", 99, '!', "mixed"); }
static int	m_edge4_std(void) { return printf("%d!%c?%s.", 99, '!', "mixed"); }

static int	m_edge5_ft(void) { return ft_printf("%u\t%x\n%o %b", 255, 255, 255, 255); }
static int	m_edge5_std(void) { return printf("%u\t%x\n%o %b", 255, 255, 255, 255); }

// ========== ALL BASES (SAME NUMBER IN ALL BASES) ==========
static int	m_bases1_ft(void) { return ft_printf("16: %x %X | 10: %d | 8: %o | 2: %b", 16, 16, 16, 16); }
static int	m_bases1_std(void) { return printf("16: %x %X | 10: %d | 8: %o | 2: %b", 16, 16, 16, 16); }

static int	m_bases2_ft(void) { return ft_printf("Num %u: hex=%x oct=%o bin=%b", 255, 255, 255, 255); }
static int	m_bases2_std(void) { return printf("Num %u: hex=%x oct=%o bin=%b", 255, 255, 255, 255); }

static int	m_bases3_ft(void) { return ft_printf("D:%d X:%x O:%o U:%u B:%b", 100, 100, 100, 100, 100); }
static int	m_bases3_std(void) { return printf("D:%d X:%x O:%o U:%u B:%b", 100, 100, 100, 100, 100); }

static int	m_bases4_ft(void) { return ft_printf("%d=%x=%o (hex and octal)", 64, 64, 64); }
static int	m_bases4_std(void) { return printf("%d=%x=%o (hex and octal)", 64, 64, 64); }

static int	m_bases5_ft(void) { return ft_printf("Val: %i (unsigned=%u, hex=%X, octal=%o)", -42, 42, 42, 42); }
static int	m_bases5_std(void) { return printf("Val: %i (unsigned=%u, hex=%X, octal=%o)", -42, 42, 42, 42); }

void	run_mixed_tests(void)
{
	t_test_case	basic[] = {
		{m_mix1_ft, m_mix1_std},
		{m_mix2_ft, m_mix2_std},
		{m_mix3_ft, m_mix3_std},
		{m_mix4_ft, m_mix4_std},
		{m_mix5_ft, m_mix5_std},
	};
	t_test_case	triple[] = {
		{m_trip1_ft, m_trip1_std},
		{m_trip2_ft, m_trip2_std},
		{m_trip3_ft, m_trip3_std},
		{m_trip4_ft, m_trip4_std},
		{m_trip5_ft, m_trip5_std},
	};
	t_test_case	quad[] = {
		{m_quad1_ft, m_quad1_std},
		{m_quad2_ft, m_quad2_std},
		{m_quad3_ft, m_quad3_std},
		{m_quad4_ft, m_quad4_std},
		{m_quad5_ft, m_quad5_std},
	};
	t_test_case	pent[] = {
		{m_pent1_ft, m_pent1_std},
		{m_pent2_ft, m_pent2_std},
		{m_pent3_ft, m_pent3_std},
		{m_pent4_ft, m_pent4_std},
		{m_pent5_ft, m_pent5_std},
	};
	t_test_case	hex[] = {
		{m_hex1_ft, m_hex1_std},
		{m_hex2_ft, m_hex2_std},
		{m_hex3_ft, m_hex3_std},
		{m_hex4_ft, m_hex4_std},
		{m_hex5_ft, m_hex5_std},
	};
	t_test_case	binary[] = {
		{m_bin1_ft, m_bin1_std},
		{m_bin2_ft, m_bin2_std},
		{m_bin3_ft, m_bin3_std},
		{m_bin4_ft, m_bin4_std},
		{m_bin5_ft, m_bin5_std},
	};
	t_test_case	ptr[] = {
		{m_ptr1_ft, m_ptr1_std},
		{m_ptr2_ft, m_ptr2_std},
		{m_ptr3_ft, m_ptr3_std},
		{m_ptr4_ft, m_ptr4_std},
		{m_ptr5_ft, m_ptr5_std},
	};
	t_test_case	cmplx[] = {
		{m_cmplx1_ft, m_cmplx1_std},
		{m_cmplx2_ft, m_cmplx2_std},
		{m_cmplx3_ft, m_cmplx3_std},
		{m_cmplx4_ft, m_cmplx4_std},
		{m_cmplx5_ft, m_cmplx5_std},
	};
	t_test_case	edge[] = {
		{m_edge1_ft, m_edge1_std},
		{m_edge2_ft, m_edge2_std},
		{m_edge3_ft, m_edge3_std},
		{m_edge4_ft, m_edge4_std},
		{m_edge5_ft, m_edge5_std},
	};
	t_test_case	bases[] = {
		{m_bases1_ft, m_bases1_std},
		{m_bases2_ft, m_bases2_std},
		{m_bases3_ft, m_bases3_std},
		{m_bases4_ft, m_bases4_std},
		{m_bases5_ft, m_bases5_std},
	};
	t_test_group	groups[] = {
		{"Basic Mix (2 flags)", basic, 5},
		{"Triple Mix (3 flags)", triple, 5},
		{"Quad Mix (4 flags)", quad, 5},
		{"Penta Mix (5 flags)", pent, 5},
		{"Hexa Mix (6 flags)", hex, 5},
		{"Binary Mix", binary, 5},
		{"Pointer Mix", ptr, 5},
		{"Complex Mix (7+ flags)", cmplx, 5},
		{"Edge Cases (Special Chars)", edge, 5},
		{"All Bases", bases, 5},
	};

	print_grouped_results("MIXED FLAGS", groups, 10);
}

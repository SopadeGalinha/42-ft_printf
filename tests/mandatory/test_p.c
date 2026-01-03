#include "tests.h"
#include "../../ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// ========== BASIC TESTS ==========
static int	p_basic1_ft(void) { int x = 42; return ft_printf("%p", (void *)&x); }
static int	p_basic1_std(void) { int x = 42; return printf("%p", (void *)&x); }

static int	p_basic2_ft(void) { return ft_printf("%p", (void *)0); }
static int	p_basic2_std(void) { return printf("%p", (void *)0); }

static int	p_basic3_ft(void) { char *str = "test"; return ft_printf("%p", (void *)str); }
static int	p_basic3_std(void) { char *str = "test"; return printf("%p", (void *)str); }

static int	p_basic4_ft(void) { int arr[5]; return ft_printf("%p", (void *)arr); }
static int	p_basic4_std(void) { int arr[5]; return printf("%p", (void *)arr); }

static int	p_basic5_ft(void) { return ft_printf("Ptr: %p", (void *)1000); }
static int	p_basic5_std(void) { return printf("Ptr: %p", (void *)1000); }

// ========== MULTIPLE POINTERS ==========
static int	p_mult1_ft(void) { int x = 1, y = 2; return ft_printf("%p %p", (void *)&x, (void *)&y); }
static int	p_mult1_std(void) { int x = 1, y = 2; return printf("%p %p", (void *)&x, (void *)&y); }

static int	p_mult2_ft(void) { int arr[3]; return ft_printf("%p %p %p", (void *)&arr[0], (void *)&arr[1], (void *)&arr[2]); }
static int	p_mult2_std(void) { int arr[3]; return printf("%p %p %p", (void *)&arr[0], (void *)&arr[1], (void *)&arr[2]); }

static int	p_mult3_ft(void) { return ft_printf("Ptrs: %p and %p", (void *)1000, (void *)2000); }
static int	p_mult3_std(void) { return printf("Ptrs: %p and %p", (void *)1000, (void *)2000); }

static int	p_mult4_ft(void) { int x; return ft_printf("%p%p%p", (void *)&x, (void *)&x, (void *)&x); }
static int	p_mult4_std(void) { int x; return printf("%p%p%p", (void *)&x, (void *)&x, (void *)&x); }

static int	p_mult5_ft(void) { char buf[100]; return ft_printf("%p\n%p", (void *)buf, (void *)NULL); }
static int	p_mult5_std(void) { char buf[100]; return printf("%p\n%p", (void *)buf, (void *)NULL); }

// ========== NULL POINTER ==========
static int	p_null1_ft(void) { return ft_printf("%p", NULL); }
static int	p_null1_std(void) { return printf("%p", NULL); }

static int	p_null2_ft(void) { return ft_printf("NULL: %p", NULL); }
static int	p_null2_std(void) { return printf("NULL: %p", NULL); }

static int	p_null3_ft(void) { return ft_printf("%p is null", NULL); }
static int	p_null3_std(void) { return printf("%p is null", NULL); }

static int	p_null4_ft(void) { return ft_printf("%p and %p", NULL, NULL); }
static int	p_null4_std(void) { return printf("%p and %p", NULL, NULL); }

static int	p_null5_ft(void) { return ft_printf("%p %p", (void *)1, NULL); }
static int	p_null5_std(void) { return printf("%p %p", (void *)1, NULL); }

// ========== VARIOUS ADDRESSES ==========
static int	p_addr1_ft(void) { return ft_printf("%p", (void *)256); }
static int	p_addr1_std(void) { return printf("%p", (void *)256); }

static int	p_addr2_ft(void) { return ft_printf("%p", (void *)4096); }
static int	p_addr2_std(void) { return printf("%p", (void *)4096); }

static int	p_addr3_ft(void) { return ft_printf("%p", (void *)1048576); }
static int	p_addr3_std(void) { return printf("%p", (void *)1048576); }

static int	p_addr4_ft(void) { return ft_printf("Address: %p", (void *)0xDEADBEEF); }
static int	p_addr4_std(void) { return printf("Address: %p", (void *)0xDEADBEEF); }

static int	p_addr5_ft(void) { return ft_printf("Got %p here", (void *)0xCAFEBABE); }
static int	p_addr5_std(void) { return printf("Got %p here", (void *)0xCAFEBABE); }

// ========== WITH TEXT ==========
static int	p_text1_ft(void) { int x = 5; return ft_printf("Start %p End", (void *)&x); }
static int	p_text1_std(void) { int x = 5; return printf("Start %p End", (void *)&x); }

static int	p_text2_ft(void) { return ft_printf("Point to: %p", (void *)500); }
static int	p_text2_std(void) { return printf("Point to: %p", (void *)500); }

static int	p_text3_ft(void) { return ft_printf("%p is a pointer", (void *)100); }
static int	p_text3_std(void) { return printf("%p is a pointer", (void *)100); }

static int	p_text4_ft(void) { return ft_printf("Mem: %p\n", (void *)0xFFFFFFFF); }
static int	p_text4_std(void) { return printf("Mem: %p\n", (void *)0xFFFFFFFF); }

static int	p_text5_ft(void) { return ft_printf("Between %p and %p", (void *)10, (void *)20); }
static int	p_text5_std(void) { return printf("Between %p and %p", (void *)10, (void *)20); }

void	run_p_tests(void)
{
	t_test_case	basic[] = {
		{p_basic1_ft, p_basic1_std},
		{p_basic2_ft, p_basic2_std},
		{p_basic3_ft, p_basic3_std},
		{p_basic4_ft, p_basic4_std},
		{p_basic5_ft, p_basic5_std},
	};
	t_test_case	mult[] = {
		{p_mult1_ft, p_mult1_std},
		{p_mult2_ft, p_mult2_std},
		{p_mult3_ft, p_mult3_std},
		{p_mult4_ft, p_mult4_std},
		{p_mult5_ft, p_mult5_std},
	};
	t_test_case	null[] = {
		{p_null1_ft, p_null1_std},
		{p_null2_ft, p_null2_std},
		{p_null3_ft, p_null3_std},
		{p_null4_ft, p_null4_std},
		{p_null5_ft, p_null5_std},
	};
	t_test_case	addr[] = {
		{p_addr1_ft, p_addr1_std},
		{p_addr2_ft, p_addr2_std},
		{p_addr3_ft, p_addr3_std},
		{p_addr4_ft, p_addr4_std},
		{p_addr5_ft, p_addr5_std},
	};
	t_test_case	text[] = {
		{p_text1_ft, p_text1_std},
		{p_text2_ft, p_text2_std},
		{p_text3_ft, p_text3_std},
		{p_text4_ft, p_text4_std},
		{p_text5_ft, p_text5_std},
	};
	t_test_group	groups[] = {
		{"Basic test", basic, 5},
		{"Multiple Pointers", mult, 5},
		{"NULL Pointer", null, 5},
		{"Various Addresses", addr, 5},
		{"With Text", text, 5},
	};

	print_grouped_results("%%p", groups, 5);
}

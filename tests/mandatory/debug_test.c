#include "../../ft_printf.h"
#include "../test_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char	*ft_output;
	char	*std_output;
	int		ft_len;
	int		std_len;
	int		ft_ret;
	int		std_ret;

	ft_output = NULL;
	std_output = NULL;
	ft_len = 0;
	std_len = 0;

	// Test 1: Simple test with tab
	printf("\n=== TEST 1: Tab character ===\n");
	
	int test_ft1(void) { return ft_printf("Tab\t%d\tEnd", -55); }
	int test_std1(void) { return printf("Tab\t%d\tEnd", -55); }
	
	ft_ret = capture_output(test_ft1, &ft_output, &ft_len);
	std_ret = capture_output(test_std1, &std_output, &std_len);
	
	printf("Printf return: %d, output length: %d\n", std_ret, std_len);
	printf("Printf output: [%.*s]\n", std_len, std_output);
	printf("\nft_printf return: %d, output length: %d\n", ft_ret, ft_len);
	printf("ft_printf output: [%.*s]\n", ft_len, ft_output);
	
	free(ft_output);
	free(std_output);

	// Test 2: Basic number
	printf("\n=== TEST 2: Basic number ===\n");
	
	int test_ft2(void) { return ft_printf("%d", 42); }
	int test_std2(void) { return printf("%d", 42); }
	
	ft_output = NULL;
	std_output = NULL;
	ft_len = 0;
	std_len = 0;
	
	ft_ret = capture_output(test_ft2, &ft_output, &ft_len);
	std_ret = capture_output(test_std2, &std_output, &std_len);
	
	printf("Printf return: %d, output length: %d\n", std_ret, std_len);
	printf("Printf output: [%.*s]\n", std_len, std_output);
	printf("\nft_printf return: %d, output length: %d\n", ft_ret, ft_len);
	printf("ft_printf output: [%.*s]\n", ft_len, ft_output);
	
	free(ft_output);
	free(std_output);

	return (0);
}

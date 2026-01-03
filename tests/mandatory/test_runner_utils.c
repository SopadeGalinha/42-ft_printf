#include "tests.h"
#include "../test_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

int	run_test(t_test_case *test, FILE *err_file, const char *group_name, int test_num)
{
	char	*ft_output;
	char	*std_output;
	int		ft_len;
	int		std_len;
	int		ft_ret;
	int		std_ret;
	int		ok;

	ft_output = NULL;
	std_output = NULL;
	ft_len = 0;
	std_len = 0;

	ft_ret = capture_output(test->ft_fn, &ft_output, &ft_len);
	std_ret = capture_output(test->std_fn, &std_output, &std_len);

	ok = (ft_ret == std_ret) && (ft_len == std_len) && ft_ret != -1
		&& std_ret != -1 && ft_output && std_output
		&& memcmp(ft_output, std_output, ft_len) == 0;

	if (!ok && err_file)
	{
		fprintf(err_file, "===========================================\n");
		fprintf(err_file, "FAILED TEST: %s [Test %d]\n", group_name, test_num);
		fprintf(err_file, "===========================================\n");
		fprintf(err_file, "Expected Output (printf):\n");
		if (std_output && std_len > 0)
			fprintf(err_file, "%.*s", std_len, std_output);
		else
			fprintf(err_file, "(empty)");
		fprintf(err_file, "\nExpected Return: %d\n\n", std_ret);
		fprintf(err_file, "Actual Output (ft_printf):\n");
		if (ft_output && ft_len > 0)
			fprintf(err_file, "%.*s", ft_len, ft_output);
		else
			fprintf(err_file, "(empty)");
		fprintf(err_file, "\nActual Return: %d\n");
		fprintf(err_file, "Output Length - Expected: %d, Got: %d\n\n", std_len, ft_len);
	}

	free(ft_output);
	free(std_output);
	return (ok);
}

void	print_grouped_results(const char *flag, t_test_group *groups, int group_count)
{
	int		i;
	int		j;
	int		passed;
	int		total;
	FILE	*err_file;

	err_file = fopen("tests/mandatory/errors.log", "a");
	if (!err_file)
	{
		fprintf(stderr, "Warning: Could not open errors.log file\n");
		err_file = stderr;
	}

	if (err_file != stderr)
		fprintf(err_file, "\nERROR LOG FOR FLAG %s\n\n", flag);

	// Print TESTS FOR FLAG with colored (Extras) if present
	char	*extras_pos;
	extras_pos = strstr((char *)flag, "(Extras)");
	if (extras_pos)
	{
		printf("%sTESTS FOR FLAG ", BOLD);
		printf("%.*s", (int)(extras_pos - flag), flag);
		printf("%s(Extras)%s%s\n", YELLOW, BOLD, RESET);
	}
	else
		printf("%sTESTS FOR FLAG %s:%s\n", BOLD, flag, RESET);
	total = 0;
	passed = 0;
	i = 0;
	while (i < group_count)
	{
		printf("%s: ", groups[i].name);
		j = 0;
		while (j < groups[i].count)
		{
			if (run_test(&groups[i].tests[j], err_file == stderr ? NULL : err_file, groups[i].name, j + 1))
			{
				printf("%s[OK]%s", GREEN, RESET);
				passed++;
			}
			else
				printf("%s[KO]%s", RED, RESET);
			total++;
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n%sSummary: %d/%d tests passed%s\n\n", 
		passed == total ? GREEN : RED, passed, total, RESET);

	if (err_file != stderr)
		fclose(err_file);
}

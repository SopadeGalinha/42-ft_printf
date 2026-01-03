#ifndef TESTS_H
# define TESTS_H

#include <stdio.h>

typedef struct s_test_case
{
	int	(*ft_fn)(void);
	int	(*std_fn)(void);
}	t_test_case;

typedef struct s_test_group
{
	const char	*name;
	t_test_case	*tests;
	int			count;
}	t_test_group;

// Test runner utilities
int	run_test(t_test_case *test, FILE *err_file, const char *group_name, int test_num);
void	print_grouped_results(const char *flag, t_test_group *groups, int group_count);

// Test functions
void	run_d_tests(void);
void	run_c_tests(void);
void	run_s_tests(void);
void	run_u_tests(void);
void	run_x_tests(void);
void	run_o_tests(void);
void	run_b_tests(void);
void	run_i_tests(void);
void	run_p_tests(void);
void	run_mixed_tests(void);

#endif

#ifndef BONUS_TESTS_H
# define BONUS_TESTS_H

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
void	run_bonus_flags_tests(void);
void	run_bonus_mixed_tests(void);
void	run_bonus_comprehensive_tests(void);
void	run_rigorous_tests(void);

#endif

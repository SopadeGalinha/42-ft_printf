#ifndef TEST_UTILS_H
# define TEST_UTILS_H

# include <stddef.h>
# include <stdio.h>

typedef struct s_capture
{
	int	saved_fd;
	int	pipe_fds[2];
} t_capture;

int	start_capture(t_capture *cap);
char	*end_capture(t_capture *cap, int *len);
int	capture_output(int (*fn)(void), char **output, int *len);
FILE	*open_error_file(const char *path);
void	write_mismatch(FILE *fp, const char *name, const char *std_output,
		int std_len, int std_ret, const char *ft_output, int ft_len, int ft_ret);

#endif

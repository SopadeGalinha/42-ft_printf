#include "test_utils.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

static void	close_pipe(int pipe_fds[2])
{
	close(pipe_fds[0]);
	close(pipe_fds[1]);
}

int	start_capture(t_capture *cap)
{
	if (!cap)
		return (-1);
	if (pipe(cap->pipe_fds) == -1)
		return (-1);
	cap->saved_fd = dup(STDOUT_FILENO);
	if (cap->saved_fd == -1)
	{
		close_pipe(cap->pipe_fds);
		return (-1);
	}
	fflush(stdout);
	if (dup2(cap->pipe_fds[1], STDOUT_FILENO) == -1)
	{
		close_pipe(cap->pipe_fds);
		dup2(cap->saved_fd, STDOUT_FILENO);
		close(cap->saved_fd);
		return (-1);
	}
	close(cap->pipe_fds[1]);
	return (0);
}

char	*end_capture(t_capture *cap, int *len)
{
	char		buffer[1024];
	char		*out;
	size_t		size;
	ssize_t		bytes_read;

	if (!cap)
		return (NULL);
	out = NULL;
	size = 0;
	fflush(stdout);
	dup2(cap->saved_fd, STDOUT_FILENO);
	close(cap->saved_fd);
	while (1)
	{
		bytes_read = read(cap->pipe_fds[0], buffer, sizeof(buffer));
		if (bytes_read <= 0)
			break ;
		char *new_out = realloc(out, size + (size_t)bytes_read + 1);
		if (!new_out)
		{
			free(out);
			close(cap->pipe_fds[0]);
			return (NULL);
		}
		out = new_out;
		memcpy(out + size, buffer, (size_t)bytes_read);
		size += (size_t)bytes_read;
	}
	close(cap->pipe_fds[0]);
	if (!out)
	{
		out = malloc(1);
		if (!out)
			return (NULL);
		size = 0;
	}
	out[size] = '\0';
	if (len)
		*len = (int)size;
	return (out);
}

int	capture_output(int (*fn)(void), char **output, int *len)
{
	int		ret;
	char	*buffer;
	t_capture cap;

	if (!fn)
		return (-1);
	if (start_capture(&cap) == -1)
		return (-1);
	ret = fn();
	buffer = end_capture(&cap, len);
	if (output)
		*output = buffer;
	else
		free(buffer);
	return (ret);
}

FILE	*open_error_file(const char *path)
{
	FILE	*fp;

	fp = fopen(path, "w");
	return (fp);
}

void	write_mismatch(FILE *fp, const char *name, const char *std_output,
		int std_len, int std_ret, const char *ft_output, int ft_len, int ft_ret)
{
	if (!fp)
		return ;
	fprintf(fp, "%s\n", name);
	fprintf(fp, "  expected (%d bytes, ret %d): \"%.*s\"\n",
		std_len, std_ret, std_len, std_output ? std_output : "");
	fprintf(fp, "  got      (%d bytes, ret %d): \"%.*s\"\n\n",
		ft_len, ft_ret, ft_len, ft_output ? ft_output : "");
}

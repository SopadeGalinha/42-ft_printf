/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:08:12 by jhogonca          #+#    #+#             */
/*   Updated: 2024/01/30 20:46:41 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_setwidth(const char *fmt, t_data *data, int flag)
{
	int	result;

	data->flags.zero = flag == '0';
	data->flags.space = flag == ' ';
	data->flags.minus = flag == '-';
	data->flags.precision = flag == '.';
	while (fmt[data->index] == flag)
		data->index++;
	result = 0;
	while (fmt[data->index] >= '0' && fmt[data->index] <= '9')
		result = (result * 10) + (fmt[data->index++] - '0');
	data->index--;
	if (flag == '.')
	{
		data->flags.precision = result;
		data->flags.width = -1;
	}
	else
	{
		data->flags.width = result;
		data->flags.precision = -1;
	}
}

void	ft_putwidth(t_data *data, int content_width)
{
	data->flags.width = data->flags.width - content_width;
	while (data->flags.width > 0)
	{
		if (data->flags.zero == 1 && data->flags.minus == 0)
			ft_putchar('0', data);
		else
			ft_putchar(' ', data);
		data->flags.width--;
	}
}

static void	parse_flags(const char *fmt, t_data *data)
{
	while (ft_strchr(FLAGS, fmt[data->index]) \
	|| (fmt[data->index] >= '0' && fmt[data->index] <= '9'))
	{
		if (fmt[data->index] == '0')
			ft_setwidth(fmt, data, '0');
		else if (fmt[data->index] == '-' || \
		(fmt[data->index] >= '0' && fmt[data->index] <= '9'))
			ft_setwidth(fmt, data, '-');
		else if (fmt[data->index] == ' ')
			ft_setwidth(fmt, data, ' ');
		else if (fmt[data->index] == '.')
			ft_setwidth(fmt, data, '.');
		else if (fmt[data->index] == '#')
			data->flags.hash = 1;
		else if (fmt[data->index] == '+')
			data->flags.plus = 1;
		else if (fmt[data->index] == '*')
			data->flags.width = va_arg(data->argument_list, int);
		data->index++;
	}
}

static void	handle_conversion(const char *fmt, t_data *data)
{
	bool	uppercase;

	if (ft_strchr(FLAGS, fmt[++data->index]) \
	|| ft_strchr(DEC_BASE, fmt[data->index]))
		parse_flags(fmt, data);
	uppercase = fmt[data->index] == 'X';
	if (fmt[data->index] == 'd' || fmt[data->index] == 'i')
		print_integer(data);
	else if (fmt[data->index] == 'c')
		print_char(data);
	else if (fmt[data->index] == 's')
		print_string(data);
	else if (fmt[data->index] == 'p')
		print_pointer(data);
	else if (fmt[data->index] == 'u')
		print_unsigned(data);
	else if (fmt[data->index] == 'x' || fmt[data->index] == 'X')
		print_hexadecimal(data, uppercase);
	else if (fmt[data->index] == '%')
		ft_putchar('%', data);
}

int	ft_printf(const char *fmt, ...)
{
	t_data	data;

	data = (t_data){0};
	va_start(data.argument_list, fmt);
	while (fmt[data.index])
	{
		init_flags(&data);
		if (fmt[data.index] == '%')
			handle_conversion(fmt, &data);
		else
			ft_putchar(fmt[data.index], &data);
		data.index++;
	}
	va_end(data.argument_list);
	return (data.bytes_written);
}

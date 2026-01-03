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

static int	parse_number(const char *fmt, int *idx)
{
	int	result;

	result = 0;
	while (fmt[*idx] >= '0' && fmt[*idx] <= '9')
	{
		result = (result * 10) + (fmt[*idx] - '0');
		(*idx)++;
	}
	(*idx)--;
	return (result);
}

static void	parse_flags(const char *fmt, t_data *data)
{
	while (fmt[data->index] && (ft_strchr(FLAGS, fmt[data->index]) ||
		(fmt[data->index] >= '0' && fmt[data->index] <= '9')))
	{
		if (fmt[data->index] == '-')
		{
			data->flags.minus = 1;
			data->flags.zero = 0;
		}
		else if (fmt[data->index] == '0' && data->flags.minus == 0
			&& data->flags.precision < 0)
			data->flags.zero = 1;
		else if (fmt[data->index] == ' ' && data->flags.plus == 0)
			data->flags.space = 1;
		else if (fmt[data->index] == '+')
		{
			data->flags.plus = 1;
			data->flags.space = 0;
		}
		else if (fmt[data->index] == '#')
			data->flags.hash = 1;
		else if (fmt[data->index] == '*')
		{
			data->flags.width = va_arg(data->argument_list, int);
			if (data->flags.width < 0)
			{
				data->flags.minus = 1;
				data->flags.width *= -1;
				data->flags.zero = 0;
			}
		}
		else if (fmt[data->index] == '.')
		{
			data->flags.precision = 0;
			data->index++;
			if (fmt[data->index] == '*')
			{
				data->flags.precision = va_arg(data->argument_list, int);
				if (data->flags.precision < 0)
					data->flags.precision = -1;
			}
			else if (fmt[data->index] >= '0' && fmt[data->index] <= '9')
				data->flags.precision = parse_number(fmt, &data->index);
			else
				data->index--;
			data->flags.zero = 0;
		}
		else if (fmt[data->index] >= '0' && fmt[data->index] <= '9')
			data->flags.width = parse_number(fmt, &data->index);
		data->index++;
	}
}

static void	print_percent(t_data *data)
{
	int	pad;
	char	pad_char;

	pad = 0;
	if (data->flags.width > 1)
		pad = data->flags.width - 1;
	pad_char = (data->flags.zero && !data->flags.minus) ? '0' : ' ';
	if (!data->flags.minus)
		ft_putnchar(data, pad_char, pad);
	ft_putchar('%', data);
	if (data->flags.minus)
		ft_putnchar(data, ' ', pad);
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
		print_percent(data);
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

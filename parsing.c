/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:08:12 by jhogonca          #+#    #+#             */
/*   Updated: 2026/01/03 00:00:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_basic_flag(const char flag, t_data *data)
{
	if (flag == '-')
	{
		data->flags.minus = 1;
		data->flags.zero = 0;
	}
	else if (flag == '0' && data->flags.minus == 0 && data->flags.precision < 0)
		data->flags.zero = 1;
	else if (flag == ' ' && data->flags.plus == 0)
		data->flags.space = 1;
	else if (flag == '+')
	{
		data->flags.plus = 1;
		data->flags.space = 0;
	}
	else if (flag == '#')
		data->flags.hash = 1;
}

static void	parse_flags(const char *fmt, t_data *data)
{
	while (fmt[data->index] && (ft_strchr(FLAGS, fmt[data->index])
			|| (fmt[data->index] >= '0' && fmt[data->index] <= '9')))
	{
		if (fmt[data->index] == '.')
			apply_precision(fmt, data);
		else if (ft_strchr("-0 #+", fmt[data->index]))
			handle_basic_flag(fmt[data->index], data);
		else if (fmt[data->index] == '*')
			apply_star_width(data);
		else if (fmt[data->index] >= '0' && fmt[data->index] <= '9')
			data->flags.width = parse_number(fmt, &data->index);
		data->index++;
	}
}

void	handle_conversion(const char *fmt, t_data *data)
{
	bool	uppercase;

	if (ft_strchr(FLAGS, fmt[++data->index])
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
	else if (fmt[data->index] == 'o')
		print_octal(data);
	else if (fmt[data->index] == 'b')
		print_binary(data);
	else if (fmt[data->index] == '%')
		print_percent(data);
}

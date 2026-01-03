/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 00:00:00 by jhogonca          #+#    #+#             */
/*   Updated: 2026/01/03 00:00:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_number(const char *fmt, int *idx)
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

void	apply_star_width(t_data *data)
{
	data->flags.width = va_arg(data->argument_list, int);
	if (data->flags.width < 0)
	{
		data->flags.minus = 1;
		data->flags.width *= -1;
		data->flags.zero = 0;
	}
}

void	apply_precision(const char *fmt, t_data *data)
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

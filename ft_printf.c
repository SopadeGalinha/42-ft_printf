/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:08:12 by jhogonca          #+#    #+#             */
/*   Updated: 2026/01/03 00:00:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_flags(t_data *data)
{
	data->flags = (t_flags){0};
	data->flags.precision = -1;
	data->flags.width = -1;
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
			ft_putnchar(&data, fmt[data.index], 1);
		data.index++;
	}
	va_end(data.argument_list);
	return (data.bytes_written);
}

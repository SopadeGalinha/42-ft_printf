/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_csp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:39:58 by jhogonca          #+#    #+#             */
/*   Updated: 2026/01/03 00:00:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_data *data)
{
	char	c;
	int		pad;
	char	pad_char;

	c = va_arg(data->argument_list, int);
	pad = 0;
	if (data->flags.width > 1)
		pad = data->flags.width - 1;
	pad_char = ' ';
	if (data->flags.zero && data->flags.minus == 0)
		pad_char = '0';
	if (!data->flags.minus)
		ft_putnchar(data, pad_char, pad);
	ft_putnchar(data, c, 1);
	if (data->flags.minus)
		ft_putnchar(data, ' ', pad);
}

void	print_string(t_data *data)
{
	char	*str;
	int		len;
	int		effective_len;
	int		pad;

	str = va_arg(data->argument_list, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	effective_len = len;
	if (data->flags.precision >= 0 && data->flags.precision < len)
		effective_len = data->flags.precision;
	pad = 0;
	if (data->flags.width > effective_len)
		pad = data->flags.width - effective_len;
	if (!data->flags.minus)
		ft_putnchar(data, ' ', pad);
	while (str && *str && effective_len-- > 0)
		ft_putnchar(data, *str++, 1);
	if (data->flags.minus)
		ft_putnchar(data, ' ', pad);
}

void	print_pointer(t_data *data)
{
	unsigned long	ptr;
	int				len;
	int				pad;

	ptr = (unsigned long)va_arg(data->argument_list, void *);
	data->flags.zero = 0;
	if (ptr == 0)
		len = 5;
	else
		len = ft_strlen_base(ptr, HEXADECIMAL) + 2;
	pad = 0;
	if (data->flags.width > len)
		pad = data->flags.width - len;
	if (!data->flags.minus)
		ft_putnchar(data, ' ', pad);
	if (ptr == 0)
		ft_putstr("(nil)", data);
	else
	{
		ft_putstr("0x", data);
		ft_putstr_base(ptr, HEXADECIMAL, HEX_BASE, data);
	}
	if (data->flags.minus)
		ft_putnchar(data, ' ', pad);
}

void	print_percent(t_data *data)
{
	int		pad;
	char	pad_char;

	pad = 0;
	if (data->flags.width > 1)
		pad = data->flags.width - 1;
	pad_char = ' ';
	if (data->flags.zero && !data->flags.minus)
		pad_char = '0';
	if (!data->flags.minus)
		ft_putnchar(data, pad_char, pad);
	ft_putnchar(data, '%', 1);
	if (data->flags.minus)
		ft_putnchar(data, ' ', pad);
}

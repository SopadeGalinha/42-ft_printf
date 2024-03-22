/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:28:45 by jhogonca          #+#    #+#             */
/*   Updated: 2024/01/30 19:28:45 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_minus(t_data *data, int *sign, int *len)
{
	if (!data->flags.minus)
	{
		if (*sign && data->flags.plus)
			ft_putchar('+', data);
		else if (*sign && !data->flags.plus)
			ft_putchar('-', data);
		*sign = 0;
		ft_putwidth(data, *len);
	}
	if (*sign && data->flags.plus)
		ft_putchar('+', data);
	else if (*sign && !data->flags.plus)
		ft_putchar('-', data);
}

void	print_integer(t_data *data)
{
	long	number;
	int		len;
	int		sign;

	number = va_arg(data->argument_list, int);
	sign = number < 0 || data->flags.plus;
	if (number < 0)
	{
		data->flags.plus = 0;
		number *= -1;
	}
	len = ft_strlen_base(number, DECIMAL) + sign;
	if (data->flags.precision && data->flags.minus == 0 \
	&& data->flags.zero == 0)
	{
		data->flags.zero = 1;
		data->flags.width = data->flags.precision + sign;
	}
	if (data->flags.space && !sign)
		ft_putchar(' ', data);
	check_minus(data, &sign, &len);
	ft_putstr_base(number, DECIMAL, DEC_BASE, data);
	if (data->flags.minus)
		ft_putwidth(data, len);
}

void	print_unsigned(t_data *data)
{
	int				len;
	unsigned int	number;

	number = va_arg(data->argument_list, unsigned int);
	len = ft_strlen_base(number, DECIMAL);
	if (data->flags.precision && data->flags.minus == 0 \
	&& data->flags.zero == 0)
	{
		data->flags.zero = 1;
		data->flags.width = data->flags.precision;
	}
	if (data->flags.minus == 0)
		ft_putwidth(data, len);
	ft_putstr_base(number, DECIMAL, DEC_BASE, data);
	if (data->flags.minus == 1)
		ft_putwidth(data, len);
}

void	print_hexadecimal(t_data *data, bool uppercase)
{
	unsigned int	number;
	int				len;

	auto char prefix = "0x";
	auto char *base = HEX_BASE;
	if (uppercase)
	{
		prefix = "0X";
		base = HEX_BASE_UP;
	}
	number = va_arg(data->argument_list, unsigned int);
	len = ft_strlen_base(number, HEXADECIMAL);
	if (data->flags.precision && data->flags.minus == 0 \
	&& data->flags.zero == 0)
	{
		data->flags.zero = 1;
		data->flags.width = data->flags.precision;
	}
	if (data->flags.minus == 0)
		ft_putwidth(data, len);
	if (data->flags.hash && number != 0)
		ft_putstr(prefix, data);
	ft_putstr_base(number, HEXADECIMAL, base, data);
	if (data->flags.minus == 1)
		ft_putwidth(data, len);
}

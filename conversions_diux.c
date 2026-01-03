/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_diux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:28:45 by jhogonca          #+#    #+#             */
/*   Updated: 2026/01/03 00:00:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calc_signed_digits(unsigned long value)
{
	if (value == 0)
		return (1);
	return (ft_strlen_base(value, DECIMAL));
}

static void	print_signed_number(t_data *data, long number)
{
	unsigned long	value;
	int				digits;
	int				pad_zero;
	int				pad_space;
	char			prefix;

	if (number < 0)
		value = (unsigned long)(-number);
	else
		value = (unsigned long)number;
	digits = calc_signed_digits(value);
	if (data->flags.precision == 0 && value == 0)
		digits = 0;
	prefix = get_sign_prefix(data, number);
	pad_zero = calc_zero_padding(data, digits, (prefix != 0));
	pad_space = calc_padding_space(data, (prefix != 0), pad_zero, digits);
	if (!data->flags.minus)
		ft_putnchar(data, ' ', pad_space);
	if (prefix)
		ft_putnchar(data, prefix, 1);
	ft_putnchar(data, '0', pad_zero);
	if (digits > 0)
		ft_putstr_base(value, DECIMAL, DEC_BASE, data);
	if (data->flags.minus)
		ft_putnchar(data, ' ', pad_space);
}

void	print_integer(t_data *data)
{
	long	number;

	number = va_arg(data->argument_list, int);
	if (data->flags.precision >= 0)
		data->flags.zero = 0;
	print_signed_number(data, number);
}

void	print_unsigned(t_data *data)
{
	unsigned int	number;
	t_print_config	cfg;

	number = va_arg(data->argument_list, unsigned int);
	if (data->flags.precision >= 0)
		data->flags.zero = 0;
	cfg.number = number;
	cfg.base = DECIMAL;
	cfg.base_str = DEC_BASE;
	cfg.prefix = NULL;
	print_number_with_prefix(data, cfg);
}

void	print_hexadecimal(t_data *data, bool uppercase)
{
	unsigned int	number;
	t_print_config	cfg;

	number = va_arg(data->argument_list, unsigned int);
	if (data->flags.precision >= 0)
		data->flags.zero = 0;
	setup_hex_config(&cfg, number, uppercase, data->flags.hash);
	print_number_with_prefix(data, cfg);
}

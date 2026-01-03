/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions_diux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:28:45 by jhogonca          #+#    #+#             */
/*   Updated: 2026/01/02 00:00:00 by GitHubCopilot    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calc_zero_padding(t_data *data, int content_len, int prefix_len)
{
	int	pad;

	pad = 0;
	if (data->flags.precision > content_len)
		pad = data->flags.precision - content_len;
	else if (data->flags.zero && data->flags.precision < 0 && !data->flags.minus
		&& data->flags.width > content_len + prefix_len)
		pad = data->flags.width - (content_len + prefix_len);
	return (pad);
}

static void	print_signed_number(t_data *data, long number)
{
	unsigned long	value;
	int				digits;
	int				pad_zero;
	int				pad_space;
	char			prefix;
	int				prefix_len;

	value = (number < 0) ? (unsigned long)(-number) : (unsigned long)number;
	digits = (value == 0) ? 1 : ft_strlen_base(value, DECIMAL);
	if (data->flags.precision == 0 && value == 0)
		digits = 0;
	prefix = 0;
	if (number < 0)
		prefix = '-';
	else if (data->flags.plus)
		prefix = '+';
	else if (data->flags.space)
		prefix = ' ';
	prefix_len = (prefix != 0);
	pad_zero = calc_zero_padding(data, digits, prefix_len);
	pad_space = 0;
	if (data->flags.width > prefix_len + pad_zero + digits)
		pad_space = data->flags.width - (prefix_len + pad_zero + digits);
	if (!data->flags.minus)
		ft_putnchar(data, ' ', pad_space);
	if (prefix)
		ft_putchar(prefix, data);
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

static void	print_unsigned_number(t_data *data, unsigned long number,
		unsigned int base, const char *base_str, const char *prefix)
{
	int		digits;
	int		pad_zero;
	int		pad_space;
	int		prefix_len;

	digits = (number == 0) ? 1 : ft_strlen_base(number, base);
	if (data->flags.precision == 0 && number == 0)
		digits = 0;
	prefix_len = (prefix && prefix[0]) ? ft_strlen(prefix) : 0;
	if (number == 0 && prefix_len > 0)
		prefix_len = 0;
	pad_zero = calc_zero_padding(data, digits, prefix_len);
	pad_space = 0;
	if (data->flags.width > prefix_len + pad_zero + digits)
		pad_space = data->flags.width - (prefix_len + pad_zero + digits);
	if (!data->flags.minus)
		ft_putnchar(data, ' ', pad_space);
	if (prefix_len > 0)
		ft_putstr(prefix, data);
	ft_putnchar(data, '0', pad_zero);
	if (digits > 0)
		ft_putstr_base(number, base, base_str, data);
	if (data->flags.minus)
		ft_putnchar(data, ' ', pad_space);
}

void	print_unsigned(t_data *data)
{
	unsigned int	number;

	number = va_arg(data->argument_list, unsigned int);
	if (data->flags.precision >= 0)
		data->flags.zero = 0;
	print_unsigned_number(data, number, DECIMAL, DEC_BASE, NULL);
}

void	print_hexadecimal(t_data *data, bool uppercase)
{
	unsigned int	number;
	const char	*base;
	const char	*prefix;

	number = va_arg(data->argument_list, unsigned int);
	if (data->flags.precision >= 0)
		data->flags.zero = 0;
	base = uppercase ? HEX_BASE_UP : HEX_BASE;
	prefix = uppercase ? "0X" : "0x";
	print_unsigned_number(data, number, HEXADECIMAL, base,
		(data->flags.hash ? prefix : NULL));
}

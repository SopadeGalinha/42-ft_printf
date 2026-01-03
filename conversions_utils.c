/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:28:45 by jhogonca          #+#    #+#             */
/*   Updated: 2026/01/03 00:00:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	calc_zero_padding(t_data *data, int content_len, int prefix_len)
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

int	resolve_digits(t_data *data, unsigned long number, unsigned int base)
{
	if (number == 0)
	{
		if (data->flags.precision == 0)
			return ((base == OCTAL && data->flags.hash));
		return (1);
	}
	return (ft_strlen_base(number, base));
}

int	resolve_prefix_len(t_data *data, unsigned long number,
		const char *prefix, unsigned int base)
{
	if (!prefix || !prefix[0])
		return (0);
	if (number == 0)
	{
		if (base == OCTAL && data->flags.hash && data->flags.precision == 0)
			return (1);
		return (0);
	}
	return (ft_strlen(prefix));
}

char	get_sign_prefix(t_data *data, long number)
{
	if (number < 0)
		return ('-');
	if (data->flags.plus)
		return ('+');
	if (data->flags.space)
		return (' ');
	return (0);
}

int	calc_padding_space(t_data *data, int prefix_len, int pad_zero, int digits)
{
	int	pad_space;

	pad_space = 0;
	if (data->flags.width > prefix_len + pad_zero + digits)
		pad_space = data->flags.width - (prefix_len + pad_zero + digits);
	return (pad_space);
}

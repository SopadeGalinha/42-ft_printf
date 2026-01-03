/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:26:22 by jhogonca          #+#    #+#             */
/*   Updated: 2026/01/03 00:00:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnchar(t_data *data, char c, int count)
{
	while (count-- > 0)
		data->bytes_written += write(1, &c, 1);
}

void	ft_putstr(const char *s, t_data *st)
{
	while (s && *s)
		ft_putnchar(st, *s++, 1);
}

void	ft_putstr_base(unsigned long nb, unsigned int base,
		const char *base_str, t_data *data)
{
	if (nb >= base)
		ft_putstr_base(nb / base, base, base_str, data);
	data->bytes_written += write(1, &base_str[nb % base], 1);
}

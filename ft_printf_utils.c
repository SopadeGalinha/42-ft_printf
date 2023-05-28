/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:34:17 by jhogonca          #+#    #+#             */
/*   Updated: 2023/05/28 17:51:17 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putchar(const char c, t_data *st)
{
	st->count += write(1, &c, 1);
}

void	ft_putstr(const char *str, t_data *st)
{
	if (!str)
		return (ft_putstr("(null)", st));
	while (*str)
		ft_putchar(*str++, st);
}

void	ft_putnbr(int nb, t_data *st)
{
	if (nb == -2147483648)
		return (ft_putstr("-2147483648", st));
	if (nb < 0)
	{
		ft_putchar('-', st);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, st);
		ft_putnbr(nb % 10, st);
	}
	else
		ft_putchar("0123456789"[nb], st);
}

void	ft_hex_base(unsigned long nb, int fmt, t_data *st)
{
	char	*base;

	if (nb == 0)
		return (ft_putchar('0', st));
	if (fmt == 'x')
		base = "0123456789abcdef";
	if (fmt == 'X')
		base = "0123456789ABCDEF";
	if (fmt == 'u')
	{
		st->hex_ref = 10;
		base = "0123456789";
	}
	if (nb >= st->hex_ref)
	{
		ft_hex_base(nb / st->hex_ref, fmt, st);
		ft_hex_base(nb % st->hex_ref, fmt, st);
	}
	else
		ft_putchar(base[nb], st);
}

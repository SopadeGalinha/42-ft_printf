/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:34:17 by jhogonca          #+#    #+#             */
/*   Updated: 2023/05/28 15:15:22 by jhogonca         ###   ########.fr       */
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
	if ()
	if (nb > 9)
	{
		if (nb >= 16 && st->flag != 'u')
		{
			ft_hex_base(nb / 16, st);
			ft_hex_base(nb % 16, st);
		}
		else
			ft_hex_base(nb / 10, st);
			ft_hex_base(nb % 10, st);
	}
	else
		ft_putchar(base[nb], st);
}

void	ft_ubase(unsigned int nb, t_data *st)
{
	if (nb >= 10)
	{
		ft_ubase(nb / 10, st);
		ft_ubase(nb % 10, st);
	}
	else
		ft_putchar("0123456789"[nb], st);
}

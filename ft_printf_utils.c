/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:34:17 by jhogonca          #+#    #+#             */
/*   Updated: 2023/05/28 18:28:13 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putchar(const char c, t_data *st)
{
	st->count += write(1, &c, 1);
}

static void	ft_putstr(const char *str, t_data *st)
{
	if (!str)
		return (ft_putstr("(null)", st));
	while (*str)
		ft_putchar(*str++, st);
}

static void	ft_putnbr(int nb, t_data *st)
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

static void	ft_hex_base(unsigned long nb, int fmt, t_data *st)
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

void	flag_conversions(char fmt, t_data *st, va_list args)
{
	st->hex_ref = 16;
	if (fmt == '%')
		ft_putchar('%', st);
	if (fmt == 'c')
		ft_putchar(va_arg(args, int), st);
	if (fmt == 's')
		ft_putstr(va_arg(args, char *), st);
	if (fmt == 'd' || fmt == 'i')
		ft_putnbr(va_arg(args, int), st);
	if (fmt == 'x' || fmt == 'X' || fmt == 'u')
		ft_hex_base(va_arg(args, unsigned int), fmt, st);
	if (fmt == 'p')
	{
		st->pointer = va_arg(args, long);
		if (st->pointer == 0)
			return (ft_putstr("(nil)", st));
		ft_putstr("0x", st);
		ft_hex_base(st->pointer, 'x', st);
	}
}

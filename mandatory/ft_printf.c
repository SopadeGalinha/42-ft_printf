/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:33:24 by jhogonca          #+#    #+#             */
/*   Updated: 2023/07/15 07:14:27 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static void	ft_putchar(const char c, t_data *st)
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

static void	ft_hex_base(unsigned long nb, int fmt, t_data *st)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (fmt == 'x')
		base = "0123456789abcdef";
	if (fmt == 'b')
		st->base_ref = 2;
	if (fmt == 'o')
		st->base_ref = 8;
	if (fmt == 'u')
		st->base_ref = 10;
	if (nb >= st->base_ref)
		ft_hex_base(nb / st->base_ref, fmt, st);
	ft_putchar(base[nb % st->base_ref], st);
}

static void	flag_conversions(char fmt, t_data *st, va_list args)
{
	if (fmt == 'c')
		ft_putchar(va_arg(args, int), st);
	if (fmt == 's')
		ft_putstr(va_arg(args, char *), st);
	if (fmt == 'd' || fmt == 'i')
	{
		st->temporary = va_arg(args, int);
		if (st->temporary < 0)
		{
			ft_putchar('-', st);
			st->temporary *= -1;
		}
		ft_hex_base(st->temporary, 'u', st);
	}
	if (fmt == 'x' || fmt == 'X' || fmt == 'u'
		|| fmt == 'o' || fmt == 'b')
		ft_hex_base(va_arg(args, unsigned int), fmt, st);
	if (fmt == 'p')
	{
		st->temporary = va_arg(args, long);
		if (st->temporary == 0)
			return (ft_putstr("(nil)", st));
		ft_putstr("0x", st);
		ft_hex_base(st->temporary, 'x', st);
	}
}

int	ft_printf(const char *fmt, ...)
{
	t_data	st;
	va_list	args;

	st.count = 0;
	st.index = -1;
	va_start(args, fmt);
	while (fmt[++st.index])
	{
		st.base_ref = 16;
		if (fmt[st.index] == '%')
		{
			if (fmt[++st.index] == '%')
				ft_putchar('%', &st);
			else
				flag_conversions(fmt[+st.index], &st, args);
		}
		else
			ft_putchar(fmt[st.index], &st);
	}
	va_end(args);
	return (st.count);
}

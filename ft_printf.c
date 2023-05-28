/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:33:24 by jhogonca          #+#    #+#             */
/*   Updated: 2023/05/28 15:07:45 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static void	flag_conversions(char fmt, t_data *st, va_list args)
{
	if (fmt == '%')
		ft_putchar('%', st);
	if (fmt == 'c')
		ft_putchar(va_arg(args, int), st);
	if (fmt == 's')
		ft_putstr(va_arg(args, char *), st);
	if (fmt == 'd' || fmt == 'i')
		ft_putnbr(va_arg(args, int), st);
	if (fmt == 'u')
		ft_ubase(va_arg(args, unsigned int), st);
	if (fmt == 'x' || fmt == 'X')
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

int	ft_printf(const char *fmt, ...)
{
	t_data	st;
	va_list	args;

	st.count = 0;
	st.index = -1;
	va_start(args, fmt);
	while (fmt[++st.index])
	{
		if (fmt[st.index] == '%')
			flag_conversions(fmt[++st.index], &st, args);
		else
			ft_putchar(fmt[st.index], &st);
	}
	va_end(args);
	return (st.count);
}

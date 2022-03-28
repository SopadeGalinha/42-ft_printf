/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:38:25 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/02/16 19:38:25 by jhgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	flag_conversions(char fmt, va_list args)
{
	int	c;

	c = 0;
	if (fmt == '%')
		c += write(1, &fmt, 1);
	if (fmt == 'c')
		c += ft_putchar(va_arg(args, int));
	if (fmt == 's')
		c += ft_putstr(va_arg(args, char *));
	if (fmt == 'd' || fmt == 'i')
		c += ft_putnbr(va_arg(args, int));
	if (fmt == 'x' || fmt == 'X')
		c += ft_hex_base(va_arg(args, unsigned int), fmt);
	if (fmt == 'p')
	{
		c += write(1, "0x", 2);
		c += ft_hex_base(va_arg(args, unsigned long), 'x');
	}
	if (fmt == 'u')
		c += ft_ubase(va_arg(args, unsigned int));
	return (c);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		c;
	va_list	args;

	c = 0;
	i = -1;
	va_start(args, fmt);
	while (fmt[++i])
	{
		if (fmt[i] == '%')
		{
			c += flag_conversions(fmt[++i], args);
			continue ;
		}
		c += write(1, &fmt[i], 1);
	}
	va_end(args);
	return (c);
}

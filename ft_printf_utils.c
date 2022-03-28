/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:08:08 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/03/28 19:37:10 by jhgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_ubase(unsigned int nb)
{
	int	c;

	c = 0;
	if (nb >= 10)
	{
		c += ft_ubase(nb / 10);
		c += ft_ubase(nb % 10);
	}
	else
		c += ft_putchar("0123456789"[nb]);
	return (c);
}

int	ft_putstr(const char *str)
{
	int	c;

	c = -1;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[++c])
		write(1, &str[c], 1);
	return (c);
}

int	ft_putchar(const char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int nb)
{
	int	counter;

	counter = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb == -2147483648)
	{
		counter += ft_putstr("-2147483648");
		return (counter);
	}
	if (nb < 0)
	{
		counter += write(1, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
		counter += ft_putchar(nb + '0');
	else
	{
		counter += ft_putnbr(nb / 10);
		counter += ft_putchar((nb % 10) + '0');
	}
	return (counter);
}

int	ft_hex_base(unsigned long nb, int fmt)
{
	int		c;
	char	*base;

	c = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	if (fmt == 'x')
		base = "0123456789abcdef";
	if (fmt == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		c += ft_hex_base(nb / 16, fmt);
		c += ft_hex_base(nb % 16, fmt);
	}
	else
		c += ft_putchar(base[nb]);
	return (c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:26:22 by jhogonca          #+#    #+#             */
/*   Updated: 2024/01/30 19:26:22 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s && *s++)
		len++;
	return (len);
}

bool	ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (true);
		s++;
	}
	return (false);
}

int	ft_strlen_base(unsigned long nb, unsigned int base)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

void	ft_putstr_base(unsigned long nb, unsigned int base, \
const char *base_str, t_data *data)
{
	if (nb >= base)
		ft_putstr_base(nb / base, base, base_str, data);
	ft_putchar(base_str[nb % base], data);
}

void	init_flags(t_data *data)
{
	data->flags = (t_flags){0};
	data->flags.precision = -1;
	data->flags.width = -1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:26:22 by jhogonca          #+#    #+#             */
/*   Updated: 2026/01/03 13:25:06 by jhogonca         ###   ########.fr       */
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
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

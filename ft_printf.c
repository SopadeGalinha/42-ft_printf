/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:33:24 by jhogonca          #+#    #+#             */
/*   Updated: 2023/05/28 18:26:04 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

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

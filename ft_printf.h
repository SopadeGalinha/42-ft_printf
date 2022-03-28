/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:09:28 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/03/28 17:09:28 by jhgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/*
** \______________________________HEADERS_____________________________________/
*/

# include <stdarg.h>
# include <unistd.h>

/*
** \_____________________________FUNCTIONS_____________________________________/
*/

int	ft_putnbr(int nb);
int	ft_putchar(const char c);
int	ft_putstr(const char *str);
int	ft_printf(const char *fmt, ...);
int	ft_ubase(unsigned int nb);
int	ft_hex_base(unsigned long nb, int fmt);
int	flag_conversions(char fmt, va_list args);

#endif
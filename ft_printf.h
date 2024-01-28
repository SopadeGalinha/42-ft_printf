/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:34:43 by jhogonca          #+#    #+#             */
/*   Updated: 2024/01/28 11:35:47 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// - HEADERS

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define FLAGS		"-0.*# +"
#define CONVERSIONS	"cspdiuxX%"
#define DEC_BASE	"0123456789"
#define HEX_BASE	"0123456789abcdef"
#define HEX_BASE_UP "0123456789ABCDEF"

#define BINARY		2
#define OCTAL		8
#define DECIMAL		10
#define HEXADECIMAL	16

// -- STRUCT
typedef struct s_flags
{
	int minus;
	int zero;
	int precision;
	int width;

	int hash;
	int space;
	int plus;
}	t_flags;

typedef struct s_data
{
	unsigned int	base;
	int				index;
	int				bytes_written;
	va_list			argument_list;
	t_flags			flags;
}	t_data;

// - FUNCTIONS

int		ft_printf(const char *fmt, ...);

#endif

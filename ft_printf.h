/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:34:43 by jhogonca          #+#    #+#             */
/*   Updated: 2024/01/30 19:51:48 by jhogonca         ###   ########.fr       */
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
	int				index;
	int				bytes_written;
	va_list			argument_list;
	t_flags			flags;
}		t_data;

// - FUNCTIONS

int		ft_printf(const char *fmt, ...);
void	print_string(t_data *data);
void	print_char(t_data *data);
void	print_pointer(t_data *data);
void	print_integer(t_data *data);
void	print_unsigned(t_data *data);
void	print_hexadecimal(t_data *data, bool uppercase);
void	ft_putchar(const char c, t_data *st);
void	ft_putstr(const char *s, t_data *st);
void	ft_putwidth(t_data *data, int len);
void	ft_putstr_base(unsigned long nb, unsigned int base, \
const char *base_str, t_data *data);
void	init_flags(t_data *data);
int		ft_strlen_base(unsigned long nb, unsigned int base);
int		ft_strlen(const char *s);
bool	ft_strchr(const char *s, int c);


#endif

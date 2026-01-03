/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:34:43 by jhogonca          #+#    #+#             */
/*   Updated: 2026/01/03 00:00:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

# define FLAGS		"-0.*# +"
# define CONVERSIONS	"cspdiuoxXb%"
# define DEC_BASE		"0123456789"
# define HEX_BASE		"0123456789abcdef"
# define HEX_BASE_UP	"0123456789ABCDEF"
# define OCT_BASE		"01234567"
# define BIN_BASE		"01"

# define DECIMAL		10
# define HEXADECIMAL	16
# define OCTAL		8
# define BINARY		2

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	precision;
	int	width;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

typedef struct s_data
{
	int		index;
	int		bytes_written;
	va_list	argument_list;
	t_flags	flags;
}	t_data;

typedef struct s_print_config
{
	unsigned long	number;
	unsigned int	base;
	const char		*base_str;
	const char		*prefix;
}	t_print_config;

int		ft_printf(const char *fmt, ...);
void	print_string(t_data *data);
void	print_char(t_data *data);
void	print_pointer(t_data *data);
void	print_integer(t_data *data);
void	print_unsigned(t_data *data);
void	print_hexadecimal(t_data *data, bool uppercase);
void	print_octal(t_data *data);
void	print_binary(t_data *data);
void	print_percent(t_data *data);
void	handle_conversion(const char *fmt, t_data *data);
void	ft_putstr(const char *s, t_data *st);
void	ft_putstr_base(unsigned long nb, unsigned int base,
			const char *base_str, t_data *data);
int		ft_strlen_base(unsigned long nb, unsigned int base);
int		ft_strlen(const char *s);
void	ft_putnchar(t_data *data, char c, int count);
bool	ft_strchr(const char *s, int c);
int		parse_number(const char *fmt, int *idx);
void	apply_star_width(t_data *data);
void	apply_precision(const char *fmt, t_data *data);
int		calc_zero_padding(t_data *data, int content_len, int prefix_len);
int		resolve_digits(t_data *data, unsigned long number, unsigned int base);
int		resolve_prefix_len(t_data *data, unsigned long number,
			const char *prefix, unsigned int base);
char	get_sign_prefix(t_data *data, long number);
int		calc_padding_space(t_data *data, int prefix_len,
			int pad_zero, int digits);
void	setup_hex_config(t_print_config *cfg, unsigned int number,
			bool uppercase, bool use_prefix);
void	print_number_with_prefix(t_data *data, t_print_config cfg);

#endif

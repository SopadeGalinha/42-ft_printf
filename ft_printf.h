/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:34:43 by jhogonca          #+#    #+#             */
/*   Updated: 2023/05/28 17:50:34 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/*
** \______________________________HEADERS_____________________________________/
*/

# include <stdarg.h>
# include <unistd.h>

typedef struct s_data
{
	char			flag;
	int				count;
	int				index;
	long			pointer;
	unsigned int	hex_ref;
}	t_data;

/*
** \_____________________________FUNCTIONS_____________________________________/
*/

int		ft_printf(const char *fmt, ...);
void	ft_putnbr(int nb, t_data *st);
void	ft_putchar(const char c, t_data *st);
void	ft_putstr(const char *str, t_data *st);
void	ft_ubase(unsigned int nb, t_data *st);
void	ft_hex_base(unsigned long nb, int fmt, t_data *st);

#endif

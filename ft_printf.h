/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:34:43 by jhogonca          #+#    #+#             */
/*   Updated: 2023/05/30 23:07:03 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// - HEADERS

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

// -- STRUCT
typedef struct s_data
{
	int				count;
	int				index;
	long			pointer;
	unsigned int	hex_ref;
	char			*str;
}	t_data;

// - FUNCTIONS

int		ft_printf(const char *fmt, ...);

#endif

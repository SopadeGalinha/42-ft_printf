/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:34:43 by jhogonca          #+#    #+#             */
/*   Updated: 2023/07/15 07:15:04 by jhogonca         ###   ########.fr       */
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
	long			temporary;
	unsigned int	base_ref;
}	t_data;

// - FUNCTIONS

int		ft_printf(const char *fmt, ...);

#endif
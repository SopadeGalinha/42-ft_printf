/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_box.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:28:45 by jhogonca          #+#    #+#             */
/*   Updated: 2026/01/03 00:00:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_octal(t_data *data)
{
	unsigned int	number;
	t_print_config	cfg;

	number = va_arg(data->argument_list, unsigned int);
	if (data->flags.precision >= 0)
		data->flags.zero = 0;
	cfg.number = number;
	cfg.base = OCTAL;
	cfg.base_str = OCT_BASE;
	if (data->flags.hash)
		cfg.prefix = "0";
	else
		cfg.prefix = NULL;
	print_number_with_prefix(data, cfg);
}

void	print_binary(t_data *data)
{
	unsigned int	number;
	t_print_config	cfg;

	number = va_arg(data->argument_list, unsigned int);
	if (data->flags.precision >= 0)
		data->flags.zero = 0;
	cfg.number = number;
	cfg.base = BINARY;
	cfg.base_str = BIN_BASE;
	if (data->flags.hash)
		cfg.prefix = "0b";
	else
		cfg.prefix = NULL;
	print_number_with_prefix(data, cfg);
}

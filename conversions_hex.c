/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:28:45 by jhogonca          #+#    #+#             */
/*   Updated: 2026/01/03 00:00:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	setup_hex_config(t_print_config *cfg, unsigned int number,
		bool uppercase, bool use_prefix)
{
	cfg->number = number;
	cfg->base = HEXADECIMAL;
	if (uppercase)
	{
		cfg->base_str = HEX_BASE_UP;
		if (use_prefix)
			cfg->prefix = "0X";
		else
			cfg->prefix = NULL;
	}
	else
	{
		cfg->base_str = HEX_BASE;
		if (use_prefix)
			cfg->prefix = "0x";
		else
			cfg->prefix = NULL;
	}
}

void	print_number_with_prefix(t_data *data, t_print_config cfg)
{
	int	digits;
	int	pad_zero;
	int	pad_space;
	int	prefix_len;

	digits = resolve_digits(data, cfg.number, cfg.base);
	prefix_len = resolve_prefix_len(data, cfg.number, cfg.prefix, cfg.base);
	pad_zero = calc_zero_padding(data, digits, prefix_len);
	pad_space = calc_padding_space(data, prefix_len, pad_zero, digits);
	if (!data->flags.minus)
		ft_putnchar(data, ' ', pad_space);
	if (prefix_len > 0)
		ft_putstr(cfg.prefix, data);
	ft_putnchar(data, '0', pad_zero);
	if (digits > 0)
		ft_putstr_base(cfg.number, cfg.base, cfg.base_str, data);
	if (data->flags.minus)
		ft_putnchar(data, ' ', pad_space);
}

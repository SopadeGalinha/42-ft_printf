/* void	print_integer(t_data *data)
{
	data->temporary = va_arg(data->argument_list, int);
	if (data->temporary < 0)
	{
		data->flags.minus = 1;
		data->temporary *= -1;
	}
	if (data->flags.precision >= 0)
		data->flags.zero = 0;
	data->flags.width -= ft_nbrlen(data->temporary, data->base);
	if (data->flags.minus == 0)
		ft_putwidth(data);
	if (data->flags.plus == 1 && data->flags.minus == 0)
		ft_putchar('+', data);
	if (data->flags.precision >= 0)
	{
		ft_putprecision(data);
		ft_puthex(data->temporary, data->base, data);
	}
	else
		ft_puthex(data->temporary, data->base, data);
	if (data->flags.minus == 1)
		ft_putwidth(data);
}
 */

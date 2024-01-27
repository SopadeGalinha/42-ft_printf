/*

static void	ft_hex_base(unsigned long nb, int fmt, t_data *st)
{
	char	*base;

	if (fmt == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (fmt == 'b')
		st->base = 2;
	if (fmt == 'o')
		st->base = 8;
	if (fmt == 'u')
		st->base = 10;
	if (nb >= st->base)
		ft_hex_base(nb / st->base, fmt, st);
	ft_putchar(base[nb], st);
}

static void	flag_conversions(char fmt, t_data *st, va_list arguments)
{
	if (fmt == 'c')
		ft_putchar(va_arg(arguments, int), st);
	if (fmt == 's')
		ft_putstr(va_arg(arguments, char *), st);
	if (fmt == 'd' || fmt == 'i' || fmt == 'o' || fmt == 'b')
	{
		st->pointer = va_arg(arguments, int);
		if (st->pointer < 0)
		{
			ft_putchar('-', st);
			st->pointer *= -1;
		}
		ft_hex_base(st->pointer, 'u', st);
	}
	if (fmt == 'x' || fmt == 'X' || fmt == 'u')
		ft_hex_base(va_arg(arguments, unsigned int), fmt, st);
	if (fmt == 'p')
	{
		st->pointer = va_arg(arguments, long);
		if (st->pointer == 0)
			return (ft_putstr("(nil)", st));
		ft_putstr("0x", st);
		ft_hex_base(st->pointer, 'x', st);
	}
}
 */



static int ft_strlen(const char *s)
{
	int	len;
	
	len = 0;
	while (s && *s++)
		len++;
	return (len);
}



static void ft_putstr(const char *s, t_data *st)
{
	while (s && *s)
		ft_putchar(*s++, st);
}


static void print_char(t_data *data)
{
	auto char c = va_arg(data->argument_list, int);

	data->flags.zero = 0;

	if (data->flags.minus == 0)
		ft_putwidth(data, 1);
	ft_putchar(c, data);
	ft_putwidth(data, 1);
}

static void print_string(t_data *data)
{
	char *str = va_arg(data->argument_list, char *);
	if (!str)
		str = "(null)";
	int len = ft_strlen(str);
	if (data->flags.precision < 0)
		data->flags.precision = len;
	if (data->flags.minus == 0)
		ft_putwidth(data, len);
	while (str && *str && data->flags.precision--)
		ft_putchar(*str++, data);
	if (data->flags.minus == 1)
		ft_putwidth(data, len);
}

static void print_pointer(t_data *data)
{
	long pointer;
	int len;
	
	data->flags.hash = 1;
	data->flags.zero = 0;
	data->flags.plus = 0;
	data->flags.space = 0;
	data->flags.precision = -1;
	
	pointer = va_arg(data->argument_list, long);
	if (data->flags.minus == 0)
		ft_putwidth(data, 2);
	if (pointer == 0)
		return (ft_putstr("(nil)", data));
	ft_putstr("0x", data);
	ft_putstr_base(pointer, HEXADECIMAL, HEX_BASE, data);
	len = ft_strlen_base(pointer, HEXADECIMAL) + 2;
	while (data->flags.minus == 1 && --data->flags.width > len)
	{
		ft_putchar(' ', data);
	}
}

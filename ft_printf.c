
#include "ft_printf.h"

static void ft_putchar(const char c, t_data *st)
{
	st->bytes_written += write(1, &c, 1);
}

static void ft_putstr(const char *s, t_data *st)
{
	while (s && *s)
		ft_putchar(*s++, st);
}

static bool ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return true;
		s++;
	}
	return false;
}

static int ft_strlen(const char *s)
{
	int	len;
	
	len = 0;
	while (s && *s++)
		len++;
	return (len);
}

void	set_width(const char *fmt, t_data *data, int flag)
{
	int result;

	data->flags.zero = flag == '0';
	data->flags.space = flag == ' ';
	data->flags.minus = flag == '-';
	data->flags.precision = flag == '.';
	while (fmt[data->index] ==  flag)
		data->index++;
	result = 0;
	while (fmt[data->index] >= '0' && fmt[data->index] <= '9')
		result = (result * 10) + (fmt[data->index++] - '0');
	data->index--;
	if (flag == '.')
	{
		data->flags.precision = result;
		data->flags.width = -1;	
	}
	else
	{
		data->flags.width = result;
		data->flags.precision = -1;
	}
}

static void ft_putwidth(t_data *data, int content_width)
{
	data->flags.width = data->flags.width - content_width;
	while (data->flags.width > 0)
	{
		if (data->flags.zero == 1 && data->flags.minus == 0)
			ft_putchar('0', data);
		else
			ft_putchar(' ', data);
		data->flags.width--;
	}
}

static void ft_putstr_base(unsigned long nb, unsigned int base, \
const char *base_str, t_data *data)
{
	if (nb >= base)
		ft_putstr_base(nb / base, base, base_str, data);
	ft_putchar(base_str[nb % base], data);
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

int ft_strlen_base(unsigned long nb, unsigned int base)
{
	int len = 0;
	if (nb == 0)
		return 1;
	while (nb >= base)
	{
		nb /= base;
		len++;
	}
	return len;
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


static void print_integer(t_data *data)
{
	long number;
	int len;
	int sign;
	
	// Mandatory
	number = va_arg(data->argument_list, int);
	sign = (number < 0);
	if (sign)
		number *= -1;
	len = ft_strlen_base(number, DECIMAL) + sign + 1;

	if (data->flags.precision < 0)
		data->flags.precision = len;
	if (data->flags.minus == 0)
	{
		if (sign)
		{
			ft_putchar('-', data);
			len--;
			sign = 0;
		}
		ft_putwidth(data, len);
	}
	// Mandatory
	if (sign)
		ft_putchar('-', data);
	
	// Bonus
	while (data->flags.precision-- > len)
		ft_putchar('0', data);
	if (number == 0 && data->flags.precision == 0)
		return ;
	ft_putstr_base(number, DECIMAL, DEC_BASE, data);
	if (data->flags.minus == 1)
		ft_putwidth(data, len);
}

static void parse_flags(const char *fmt, t_data *data)
{
	while (ft_strchr(FLAGS, fmt[data->index]) || (fmt[data->index] >= '0' && fmt[data->index] <= '9'))
	{
		if (fmt[data->index] == '-' || (fmt[data->index] >= '0' && fmt[data->index] <= '9'))
			set_width(fmt, data, '-');
		else if (fmt[data->index] == '0')
			set_width(fmt, data, '0');
		else if (fmt[data->index] == ' ')
			set_width(fmt, data, ' ');
		else if (fmt[data->index] == '.')
			set_width(fmt, data, '.');
		else if (fmt[data->index] == '#')
			data->flags.hash = 1;
		else if (fmt[data->index] == '+')
			data->flags.plus = 1;
		else if (fmt[data->index] == '*')
			data->flags.width = va_arg(data->argument_list, int);
		data->index++;
	}
}

static void handle_conversion(const char *fmt, t_data *data)
{
	data->index++;
	if (ft_strchr(FLAGS, fmt[data->index]) \
	|| ft_strchr(DEC_BASE, fmt[data->index]))
		parse_flags(fmt, data);
	if (fmt[data->index] == 'c')
		print_char(data);
	else if (fmt[data->index] == 's')
		print_string(data);
	else if (fmt[data->index] == 'p')
		print_pointer(data);
	else if (fmt[data->index] == 'd' || fmt[data->index] == 'i')
		print_integer(data);
}

static void init_flags(t_data *data)
{
	data->flags = (t_flags){0};
	data->flags.precision = -1;
	data->flags.width = -1;
	data->base = HEXADECIMAL;
}

int ft_printf(const char *fmt, ...)
{
	t_data data;

	data = (t_data){0};
	data.index = 0;
	va_start(data.argument_list, fmt);
	while (fmt[data.index])
	{
		init_flags(&data);
		if (fmt[data.index] == '%')
			handle_conversion(fmt, &data);
		else
			ft_putchar(fmt[data.index], &data);
		data.index++;
	}
	va_end(data.argument_list);
	return data.bytes_written;
}

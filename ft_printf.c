
#include "ft_printf.h"

static void	ft_putwidth(t_data *data);
static void	ft_putprecision(t_data *data);
static void	ft_puthex(unsigned long nbr, unsigned int base, t_data *data);
static int	ft_nbrlen(unsigned long nbr, unsigned int base);


static void	ft_putchar(const char c, t_data *st)
{
	st->bytes_written += write(1, &c, 1);
}

static void	ft_putstr(const char *str, t_data *st)
{
	if (!str)
		return (ft_putstr("(null)", st));
	while (*str)
		ft_putchar(*str++, st);
}

void	print_char(t_data *data)
{
	char	c;

	c = va_arg(data->argument_list, int);
	data->flags.width--;
	if (data->flags.minus == 0)
		ft_putwidth(data);
	ft_putchar(c, data);
	if (data->flags.minus == 1)
		ft_putwidth(data);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	initialize_data(t_data *data)
{
	data->flags = (t_flags){0};
	data->base = HEXADECIMAL;
	data->flags.width = -1;
	data->flags.precision = -1;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -sign;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i++] - '0');
		if (result < 0)
			return (-1);
	}
	return (result * sign);
}

static	bool ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (true);
		s++;
	}
	return (false);
}

static void parse_flags(const char *fmt, t_data *data)
{
	while (ft_strchr(FLAGS, fmt[data->index]))
	{
		if (fmt[data->index] == '-')
			data->flags.minus = 1;
		if (fmt[data->index] == '0')
			data->flags.zero = 1;
		if (fmt[data->index] == '.')
		{
			data->flags.precision = 0;
			while (fmt[++data->index] >= '0' && fmt[data->index] <= '9')
				data->flags.precision = \
				(data->flags.precision * 10) + (fmt[data->index] - '0');
			continue ;
		}
		if (fmt[data->index] == '#')
			data->flags.hash = 1;
		if (fmt[data->index] == ' ')
			data->flags.space = 1;
		if (fmt[data->index] == '+')
			data->flags.plus = 1;
		if (fmt[data->index] == '*')
			data->flags.width = va_arg(data->argument_list, int);
		data->index++;
	}
}

static void ft_putwidth(t_data *data)
{
	if (data->flags.precision >= 0 && data->flags.precision < data->flags.width)
		data->flags.width = data->flags.width - data->flags.precision;
	while (data->flags.width > 0)
	{
		if (data->flags.zero == 1 && data->flags.precision < 0 && data->flags.minus == 0)
			ft_putchar('0', data);
		else
			ft_putchar(' ', data);
		data->flags.width--;
	}
}


static void	ft_putprecision(t_data *data)
{
	while (data->flags.precision > 0)
	{
		ft_putchar('0', data);
		data->flags.precision--;
	}
}

static void	ft_puthex(unsigned long nbr, unsigned int base, t_data *data)
{
	char	*hex_base;

	if (data->flags.precision == 0 && nbr == 0)
		return ;
	if (data->flags.hash == 1 && data->flags.zero == 1)
	{
		if (data->base == HEXADECIMAL)
			ft_putstr("0x", data);
		if (data->base == HEXADECIMAL)
			ft_putstr("0X", data);
	}
	if (nbr >= base)
		ft_puthex(nbr / base, base, data);
	if (data->base == HEXADECIMAL)
		hex_base = HEX_BASE;
	if (data->base == HEXADECIMAL)
		hex_base = HEX_BASE_UP;
	ft_putchar(hex_base[nbr % base], data);
}

static int	ft_nbrlen(unsigned long nbr, unsigned int base)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}


void	print_string(t_data *data)
{
	char	*str;
	int		len;

	str = va_arg(data->argument_list, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (data->flags.precision >= 0 && data->flags.precision < len)
		len = data->flags.precision;
	data->flags.width -= len;
	if (data->flags.minus == 0)
		ft_putwidth(data);
	while (len--)
		ft_putchar(*str++, data);
	if (data->flags.minus == 1)
		ft_putwidth(data);
}

void	handle_conversion(const char *fmt, t_data *data)
{
	data->index++;
	if (ft_strchr(FLAGS, fmt[data->index]))
		parse_flags(fmt, data);
	if (ft_strchr(CONVERSIONS, fmt[data->index]))
	{
		if (fmt[data->index] == 'c')
			print_char(data);
		if (fmt[data->index] == 's')
			print_string(data);
	}
}

int	ft_printf(const char *fmt, ...)
{
	t_data	data;
	
	data = (t_data){0};
	va_start(data.argument_list, fmt);
	while (fmt[data.index])
	{
		initialize_data(&data);
		if (fmt[data.index] == '%')
			handle_conversion(fmt, &data);
		else
			ft_putchar(fmt[data.index], &data);
		data.index++;
	}
	va_end(data.argument_list);
	return (data.bytes_written);
}

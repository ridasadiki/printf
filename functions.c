#include "main.h"
/**** PRINT CHAR ****/
/*
 * print_chars = he print charchter
 * @buffer = handle the buffer array
 * @width = easy is the width
 * @types = arguments list
 * @flags = how many flags are active
 * @size = put the exact size
 * @precision = specific precision
 * Return = how many charachters are printed
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
		char c = va_arg(types, int);
		return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**** PRINT A STRING ****/
/*
 * print_string = sting printed
 * @types = arguments list
 * @buffer = handle the buffer array
 * @flags = how many flags are active
 * @precision = specific precision
 * @size = put the exact size
 * @width = easy is the width
 * Return = how many charachters are printed
 */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
		UNUSED(flags);
		UNUSED(buffer);
		UNUSED(precision);
		UNUSED(width);
		UNUSED(size);
		if (str == NULL)
		{
			str = "(null)";
			if (precision >= 6)
				str = "      ";
		}
			while (str[length] != '\0')
				length++;
			if (precision >= 0 && precision < length)
				length = precision;
			if (width > length)
			{
				if (flags & F_MINUS)
				{
					write(1, &str[0], length);
					for (i = width - length; i > 0; i--)
						write(1, " ", 1);
					return (width);
				}
				else
				{
					for (i = width - length; i > 0; i--)
						write(1, " ", 1);
					write(1, &str[0], length);
					return (width);
				}
			}
			return (write(1, str, length));
}
/**** PRINT PERCENT SIGN ****/
/*
 * print_percent = percent sign to be printed
 * @buffer = handle the buffer array
 * @types = arguments list
 * @flags = how many flags are active
 * @width = easy is the width
 * @precision = specific precision
 * @size = put the exact size
 * Return = how many charachters are printed
 */
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(types);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);
	return (write(1, "%%", 1));
}
/**** PRINT INT ****/
/*
 * print_int = int printed
 * @types = arguments list
 * @buffer = handle the buffer array
 * @flags = how many flags are active
 * @precision = specific precision
 * @size = put the exact size
 * @width = easy is the width
 * Return = how many charachters are printed
 */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;
	n = convert_size_number(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
/**** Print BINARY ****/
/*
 * print_binary = one number printed
 * @types = arguments list
 * @buffer = handle the buffer array
 * @flags = how many flags are active
 * @precision = specific precision
 * @size = put the exact size
 * @width = easy is the width
 * Return = how many charachters are printed
 */
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;
	UNUSED(flags);
	UNUSED(width);
	UNUSED(buffer);
	UNUSED(precision);
	UNUSED(size);
	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];
			write(1, &z, 1);
			count++;
		}
	}
	return (count);
	{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;
	UNUSED(flags);
	UNUSED(width);
	UNUSED(buffer);
	UNUSED(precision);
	UNUSED(size);
	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
	m /= 2;
	a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
	sum += a[i];
	if (sum || i == 31)

	char z = '0' + a[i];
	write(1, &z, 1);
	count++;
	}
	}
return (count);
}}

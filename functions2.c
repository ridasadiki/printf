#include "main.h"
/**** PRINT POINTER ****/
/*
 * print_pointer - the value of pointer to print
 * @types: arguments list
 * @buffer: handle the buffer array
 * @flags: how many flags are active
 * @precision: specific precision
 * @size: put the exact size
 * @width: easy is the width
 * Return: how many charachters are printed
 */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = '';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(size);
	UNUSED(width);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	num_addrs = (unsigned long)addrs;

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	while (num_addrs > 0)
	{
		um_addrs /= 16;
		buffer[ind--] = map_to[num_addrs % 16];
		length++;
	}
	if (flags & F_PLUS)
		extra_c = '+', length++;
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(buffer, ind, length,
				width, flags, padd, extra_c, padd_start));
}

/**** PRINT REVERSE ****/
/*
 * print_reverse - a reverse string printed
 * @types: arguments list
 * @buffer: handle the buffer array
 * @flags: how many flags are active
 * @precision: specific precision
 * @size: put the exact size
 * @width: easy is the width
 * Return: how many charachters are printed
 */

int print_reverse(va_list types, char buffer[],
		int flags, int width, int size, int precision)
{
	char *str;
	int i, count = 0;

	UNUSED(flags);
	UNUSED(width);
	UNUSED(buffer);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		for (i = i - 1; i >= 0; i--)
		{
			char z = str[i];

			write(1, &z, 1);
			count++;
		}
	return (count);

}

/**** PRINT A STRING IN ROT13 ****/
/*
 * print_rot13string - rot13 is a string to print
 * @types: arguments list
 * @buffer: handle the buffer array
 * @flags: how many flags are active
 * @precision: specific precision
 * @size: put the exact size
 * @width: easy is the width
 * Return: how many charachters are printed
 */
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	unsigned int i, j;
	char *str;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(buffer);
	UNUSED(precision);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

/**** print NON PRINTABLE ****/
/*
 * print_non_printable - ascii codes in hexadecimal of non print charachters
 * @types: arguments list
 * @buffer: handle the buffer array
 * @flags: how many flags are active
 * @precision: specific precision
 * @size: put the exact size
 * @width: easy is the width
 * Return: how many charachters are printed
 */
int print_non_printable(va_list types, char buffer[],
		int size, int precision, int flags, int width)
{
	char *str = va_arg(types, char *);
	int i = 0, offset = 0;

	UNUSED(size);
	UNUSED(precision);
	UNUSED(flags);
	UNUSED(width);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);
		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}


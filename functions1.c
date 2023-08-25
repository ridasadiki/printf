#include "main.h"

/**** Print UNSIGNED NUMBER ****/
/**
 * print_unsigned - unsigned number printed
 * @types: arguments list
 * @buffer: handle the buffer array
 * @flags: how many flags are active
 * @precision: specific precision
 * @size: put the exact size
 * @width: easy is the width
 * Return: how many charachters are printed
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsigned int(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**** Print UNSIGNED NUMBER IN OCTAL  ****/
/**
 * print_octal - unsigned number in octal to be printed
 * @types: arguments list
 * @buffer: handle the buffer array
 * @flags: how many flags are active
 * @precision: specific precision
 * @size: put the exact size
 * @width: easy is the width
 * Return: how many charachters are printed
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**** PRINT HEXX NUM IN LOWER OR UPPER ****/
/*
 * print_hexa - hexadecimal num in low or up to print
 * @map_to: map of number in array of values
 * @types: arguments list
 * @buffer: handle the buffer array
 * @flag_ch: how many flags are active
 * @flags: how many flags are active
 * @precision: specific precision
 * @size: put the exact size
 * @width: easy is the width
 * Return: how many charachters are printed
 */
int print_hexa(va_list types, char map_to[],
		char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ****/
/*
 * print_hexa_upper - unsigned number in upper hexa notation to print
 * @types: arguments list
 * @buffer: handle the buffer array
 * @flags: how many flags are active
 * @precision: specific precision
 * @size: put the exact size
 * @width: easy is the width
 * Return: how many charachters are printed
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**** PRINT UNSIGNED NUMBER HEXADECIMAL ****/
/*
 * print_hexadecimal - unsigned number in hexa notation to print
 * @types: arguments list
 * @buffer: handle the buffer array
 * @flags: how many flags are active
 * @precision: specific precision
 * @size: put the exact size
 * @width: easy is the width
 * Return: how many charachters are printed
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
		return (print_hexa(types, "0123456789ABCDEF",
					buffer, flags, 'X', width, precision, size));
}

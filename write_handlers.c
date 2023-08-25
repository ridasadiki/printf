#include "main.h"
/**** WRITE NUMBER ****/
/**
 * write_number - Prints a string
 * @is_negative: arguments list
 * @buffer: array to print
 * @ind: type of charach
 * @width: width
 * @flags: how many flags are active
 * @size: specific size
 * @precision: specific precision
 * Return: number of charach printed
 */
int write_number(int is_negative, int ind, char buffer[],
		int width, int flags, int size, int precision)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);
	if (is_negative)
		extra_ch = '-';
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	else if (flags & F_SPACE)
		extra_ch = ' ';
	else if (flags & F_PLUS)
		extra_ch = '+';
	return (write_num(ind, buffer, flags, width, precision,
				lenght, extra_ch, padd));
}

/*
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number of length
 * @padd: Pading char
 * @extra_c: Extra char
 * Return: Number of printed chars
 */

int write_num(int ind, char buffer[],
		int width, int flags, int prec,
		int padd, char lengh, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: if the num is negative
 * @ind: which the number starts in the buffer
 * @buffer: Array of charachters
 * @flags: Flags
 * @width: Width
 * @precision: specific precision
 * @size: specific size
 * Return: Number of written charachters.
 */
int write_unsgnd(int is_negative, int ind,
		char buffer[],
		int size, int flags, int precision, int width)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(size);
	UNUSED(is_negative);
	if (precision > 0 && precision < length)
		padd = ' ';
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
		return (write(1, &buffer[ind], length));
	}
}
/**
 * write_pointer - Write a memory address
 * @buffer: buff
 * @ind: which the number starts in the buff
 * @length: Length
 * @width: Width
 * @flags: Flags
 * @padd: Charachter representing the padd
 * @extra_c: Charachter represent extra charachter
 * @padd_start: which padd should start
 * Return: Number of charachters wroten
 */
int write_pointer(char buffer[], int ind, int length,
		int flags, int width, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)

	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd

				buffer[i] = '\0';
			if (flags & F_MINUS && padd == ' ')
			{
				buffer[--ind] = '0';
				buffer[--ind] = 'x';
				if (extra_c)
					buffer[--ind] = extra_c;
				return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
			}
			else if (!(flags & F_MINUS) && padd == ' ')
			{
				buffer[--ind] = '0';
				buffer[--ind] = 'x';
				if (extra_c)
					buffer[--ind] = extra_c;
				return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
			}
			else if (!(flags & F_MINUS) && padd == '0')
			{
				if (extra_c)
					buffer[--padd_start] = extra_c;
				buffer[2] = 'x';
				buffer[1] = '0';
				return (write(1, &buffer[padd_start], i - padd_start) +
						write(1, &buffer[ind], length - (1 - padd_start) - 2));
			}
		}
		buffer[--ind] = '0';
		buffer[--ind] = 'x';
		if (extra_c)
			buffer[--ind] = extra_c;
		return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
	}
	/** WRITE HANDLE **/
	/**
	 * handle_write_char - Prints a string
	 * @c: types of charachters
	 * @buffer: Buff
	 * @flags: how many flags are active
	 * @width: width
	 * @precision: precision
	 * @size: specific size
	 * Return: Number of charachters print
	 */
	int handle_write_char(char c, char buffer[],
			int width, int flags, int precision, int size)
	{
		char padd = ' ';
		int i = 0;

		UNUSED(size);
		UNUSED(precision);
		if (flags & F_ZERO)
			padd = '0';
		buffer[i] = '\0';
		buffer[i++] = c;
		if (width > 1)
		{
			buffer[BUFF_SIZE - 1] = '\0';
			for (i = 0; i < width - 1; i++)
				buffer[BUFF_SIZE - i - 2] = padd;
			if (flags & F_MINUS)
				return (write(1, &buffer[0], 1) +
						write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
			else
				return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
						write(1, &buffer[0], 1));
		}
		return (write(1, &buffer[0], 1));
	}

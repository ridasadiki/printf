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



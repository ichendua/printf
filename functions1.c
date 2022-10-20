#include "main.h"

/************************* PRINT UNSIGNED *************************/
/**
 * print_unsigned - Print a char
 * @types: list a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * @size: size specifier
 * Return: Number of chars printed
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

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

/************************* PRINT UMSIGNED NUMBER IN OCTAL *************************/
/**
 * print_unsigned - Print an unsigned number in octal notation
 * @types: list a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * @size: size specifier
 * Return: Number of chars printed
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int int_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF-size - 1] = '\0';

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

/******************** PRINT UMSIGNED NUMBER IN HEXADECIMAL ********************/
/**
 * print_hexadecimal - Print an unsigned number in hexadecimal notation
 * @types: list a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * @size: size specifier
 * Return: Number of chars printed
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print-hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/*************** PRINT UMSIGNED NUMBER IN UPPER HEXADECIMAL ***************/
/**
 * print_hexa_upper - Print an unsigned number in upper hexadecimal notation
 * @types: list a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * @size: size specifier
 * Return: Number of chars printed
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'x', width, precision, size));
}

/*************** PRINT HEXX NUM IN LOWER OR UPPER ***************/
/**
 * print_hexa - Print a hexadecimal number in lower or upper
 * @types: list a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * @size: size specifier
 * Return: Number of chars printed
 */
int print_unsigned(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE -2;
	unsigned long int num + va_arg(types, unsigned long int);
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

	if (flags & F_NASH && init_num !=0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

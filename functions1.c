#include "main.h"

/**
* print_unsigned - Prints an u
* @types: List a of arg
* @buffer: Buffer to handle print
* @flags:  Calates active flags
* @width: gewidth
* @precision: Precision
* @size: Size specif
* Return: Number of cted.
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

/**
* print_octal - Prints an uctal notation
* @types: Lista of argus
* @buffer: Buffer to handle print
* @flags:  Cates active flags
* @width: gwidth
* @precision: Precision specfication
* @size: Size specif
* Return: Numberchars printed
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

/**
* print_hexadecimal - Prints an unsigned number in hexadecimal notation
* @types: Lista of argume
* @buffer: Buffeay to handle print
* @flags:  Calculatesags
* @width: get wi
* @precision: Precision ication
* @size: Size specif
* Return: Numbechars printed
*/

int print_hexadecimal(va_list types, char buffer[],

	int flags, int width, int precision, int size)

{

	return (print_hexa(types, "0123456789abcdef", buffer,

		flags, 'x', width, precision, size));

}

/**
* print_hexa_upper - Prints an unsinotation
* @types: Lista of arg
* @buffer: Buy to handle print
* @flags:  Calculates ags
* @width: get
* @precision: Precision specifi
* @size: Size spe
* Return: Number of cha
*/

int print_hexa_upper(va_list types, char buffer[],

	int flags, int width, int precision, int size)

{

	return (print_hexa(types, "0123456789ABCDEF", buffer,

		flags, 'X', width, precision, size));

}

/**
* print_hexa - Prints a hexadecimal number in lower
* @types: Lista of arg
* @map_to: Array olues to map the number to
* @buffer: Barray to handle print
* @flags:  Calculates activ
* @flag_ch: Calculates acve flags
* @width: get widt
* @precision: Precisioon
* @size: Size specir
* @size: Size specifica
* Return: Numberrs printed
*/

int print_hexa(va_list types, char map_to[], char buffer[],

	int flags, char flag_ch, int width, int precision, int size)

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

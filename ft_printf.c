/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:47:50 by dsoroko           #+#    #+#             */
/*   Updated: 2022/05/09 12:40:44 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_check_format(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

int ft_formats(va_list args, const char format)
{
	int format_return;

	format_return = 0;
	if (format == 'c')
		format_return = ft_print_char(va_arg(args, int));
	else if (format == 's')
		format_return = ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		format_return = ft_print_ptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		format_return = ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		format_return = ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		format_return = ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		format_return = ft_print_percent();
	return (format_return);
}

int ft_printf(const char *str, ...)
{
	int i;
	va_list args;
	int return_value;
	char *set;

	i = -1;
	return_value = 0;
	set = "cspdiuxX%";
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%' && ft_check_format(str[i + 1], set))
		{
			return_value += ft_formats(args, str[i + 1]);
			i++;
		}
		else if (str[i] == '%' && !(ft_check_format(str[i + 1], set)))
		{
			return_value += ft_print_char(str[i + 1]);
			i++;
		}
		else
			return_value += ft_print_char(str[i]);
	}
	va_end(args);
	return (return_value);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *str = "Hello";
// 	int integer = -10;
// 	int digit = -10;
// 	unsigned int max_u_int = 4294967295;
// 	unsigned int hex_x = -128;
// 	int hex_X = -128;
// 	char c = 'c';
// 	int *ptr = &integer;
// 	ft_printf("-------------------------------------\n");
// 	ft_printf("|    My ft_printf implimentation    |\n");
// 	ft_printf("-------------------------------------\n");
// 	ft_printf("String is: %s\nChar is : %c\n", str, c);
// 	ft_printf("Decimal is : %d\nInteger is : %i\n", integer, digit);
// 	ft_printf("Unsigned integer is : %u\n", max_u_int);
// 	ft_printf("Hexadecimal integer x is : %x\n", hex_x);
// 	ft_printf("Hexadecimal integer X is : %X\n", hex_X);
// 	ft_printf("Pointer is : %p\n", ptr);

// 	printf("-------------------------------------\n");
// 	printf("|            Real printf            |\n");
// 	printf("-------------------------------------\n");
// 	printf("String is: %s\nChar is : %c\n", str, c);
// 	printf("Decimal is : %d\nInteger is : %i\n", integer, digit);
// 	printf("Unsigned integer is : %u\n", max_u_int);
// 	printf("Hexadecimal integer x is : %x\n", hex_x);
// 	printf("Hexadecimal integer X is : %X\n", hex_X);
// 	printf("Pointer is : %p\n", ptr);
// 	return 0;
// }

// #include <stdio.h>
// int main()
// {
// 	char *str = "Hello";
// 	int integer = -1;
// 	int digit = -2147483648;
// 	unsigned int max_u_int = 4294967295;
// 	unsigned int hex_x = -128;
// 	int hex_X = -128;
// 	ft_printf("-------------------------------------\n");
// 	ft_printf("|    My ft_printf implimentation    |\n");
// 	ft_printf("-------------------------------------\n");
// 	int ret_ft_printf = ft_printf("Value : %d\n", integer);
// 	printf("Return : %d\n", ret_ft_printf);
// 	printf("-------------------------------------\n");
// 	printf("|            Real printf            |\n");
// 	printf("-------------------------------------\n");
// 	int ret_printf = printf("Value : %d\n", integer);
// 	printf("Return  : %d\n", ret_printf);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_and_print_pointer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:43:28 by dsoroko           #+#    #+#             */
/*   Updated: 2022/05/05 16:20:29 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_get_ptr_len(unsigned long n)
{
	int len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void ft_get_ptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_get_ptr(num / 16);
		ft_get_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_print_char((num + '0'));
		else
			ft_print_char((num - 10 + 'a'));
	}
}

int	ft_print_ptr(unsigned long ptr)
{
	int	print_ptr;

	print_ptr = 0;
	print_ptr += write(1, "0x", 2);
	if (ptr == 0)
		print_ptr += write(1, "0", 1);
	else
	{
		ft_get_ptr(ptr);
		print_ptr += ft_get_ptr_len(ptr);
	}
	return (print_ptr);
}
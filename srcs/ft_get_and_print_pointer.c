/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_and_print_pointer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:43:28 by dsoroko           #+#    #+#             */
/*   Updated: 2022/05/10 12:21:44 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_ptr_len(unsigned long n)
{
	int	len;

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

void	ft_get_ptr(unsigned long num)
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
	int	ptr_len;

	ptr_len = 0;
	ptr_len += write(1, "0x", 2);
	if (ptr == 0)
		ptr_len += write(1, "0", 1);
	else
	{
		ft_get_ptr(ptr);
		ptr_len += ft_get_ptr_len(ptr);
	}
	return (ptr_len);
}

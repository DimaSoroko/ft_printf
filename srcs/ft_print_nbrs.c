/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:53:11 by dsoroko           #+#    #+#             */
/*   Updated: 2022/05/10 12:21:12 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_int_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_get_unsigned_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_print_nbr(int n)
{
	int		str_ret;
	char	*num;

	str_ret = 0;
	num = ft_itoa(n);
	str_ret = ft_print_str(num);
	free(num);
	if (n < 0)
		return (str_ret + 1);
	return (str_ret);
}

int	ft_print_unsigned(unsigned int n)
{
	unsigned int	str_ret;
	char			*num;

	str_ret = 0;
	num = ft_uitoa(n);
	str_ret = ft_print_str(num);
	free(num);
	return (str_ret);
}

int	ft_print_hex(unsigned int n, const char format)
{
	if (n == 0)
		ft_print_char('0');
	else
		ft_get_hex(n, format);
	return (ft_get_hex_len(n));
}

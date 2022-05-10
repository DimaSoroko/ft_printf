/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_and_transform.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:19:44 by dsoroko           #+#    #+#             */
/*   Updated: 2022/05/10 12:20:29 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_hex_len(unsigned int n)
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

char	*ft_itoa(int nb)
{
	char	*str;
	long	n;
	int		len;

	n = nb;
	len = ft_get_int_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

char	*ft_uitoa(unsigned int nb)
{
	char			*str;
	unsigned int	len;

	len = ft_get_unsigned_len(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	return (str);
}

void	ft_get_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_get_hex(num / 16, format);
		ft_get_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_print_char((num + '0'));
		else
		{
			if (format == 'x')
				ft_print_char((num - 10 + 'a'));
			if (format == 'X')
				ft_print_char((num - 10 + 'A'));
		}
	}
}

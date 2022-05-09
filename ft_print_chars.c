/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:54:22 by dsoroko           #+#    #+#             */
/*   Updated: 2022/05/09 11:40:59 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_print_str(char *str)
{
	int i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		i = 6;
	}
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}

int ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}
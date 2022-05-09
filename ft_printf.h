/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:43:08 by dsoroko           #+#    #+#             */
/*   Updated: 2022/05/09 11:29:15 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_strlen(char *str);
int				ft_print_str(char *str);
int				ft_print_percent(void);
int				ft_print_char(char c);
int				ft_print_percent(void);
int				ft_get_int_len(int n);
int				ft_get_unsigned_len(unsigned int n);
int				ft_get_hex_len(unsigned int n);
char			*ft_itoa(int nb);
char			*ft_uitoa(unsigned int nb);
void			ft_get_hex(unsigned int num, const char format);
int				ft_print_nbr(int n);
int				ft_print_unsigned(unsigned int n);
int				ft_print_hex(unsigned int n, const char format);
int				ft_get_ptr_len(unsigned long n);
void			ft_get_ptr(unsigned long num);
int				ft_print_ptr(unsigned long ptr);
int				ft_check_format(char c, char *set);
int				ft_formats(va_list args, const char format);
int				ft_printf(const char *str, ...);

#endif
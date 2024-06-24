/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:04:49 by rucorrei          #+#    #+#             */
/*   Updated: 2024/06/24 23:16:14 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

/* File ft_printf.c */
int		ft_printf(const char *str, ...);
int		ft_parse(va_list args, const char format);
/* File ft_printf_utils.c */
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_print_int(int n);
/* File ft_print_ptr.c */
int		ft_print_ptr(unsigned long ptr);
int		ft_ptr_len(unsigned long ptr);
/* File ft_print_unsigned.c */
int		ft_print_unsigned(unsigned int n);
int		ft_unsigned_len(unsigned int n);
/* File ft_print_hex.c */
int		ft_print_hex(unsigned int n, const char format);
int		ft_hex_len(unsigned int n);
void	ft_put_hex(unsigned int n, const char format);

#endif
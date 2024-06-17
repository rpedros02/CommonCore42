/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:02:10 by rucorrei          #+#    #+#             */
/*   Updated: 2024/06/17 16:40:28 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "libft.h"

int	ft_printnbr(int n)
{
	int	len;
	
	len = 0;
	if (n < 0){
		ft_putchar('-');
		len++;
		n = -n;
	}
	if (n >= 10)
		len += ft_printnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (len + 1);
}

int	ft_parse(const char c, va_list args)
{
	if (c == 'c')
		return ft_printchar(va_arg(args, int));
	if (c == 's')
		return (ft_printstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	if (c == 'x')
		// return (ft_puthex(va_arg(args, unsigned int), 0));
	if (c == 'X')
		// return (ft_puthex(va_arg(args, unsigned int), 1));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...){
	va_list			args;
	int				i;
	unsigned int	len;
	
	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i] != '\0'){
		if (str[i] == '%'){
			i++;
			len += ft_parse(&str[i], args);
		}
		else{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
}

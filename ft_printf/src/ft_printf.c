/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:02:10 by rucorrei          #+#    #+#             */
/*   Updated: 2024/06/24 20:49:18 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "libft.h"

/* Parses the output by receiving the va_list and the format(char) */
int	ft_parse(va_list args, const char format)
{
	int	len;

	len = 0;
	if(format == 'c')
		len += ft_printchar(va_arg(args, int));
	else if(format == 's')
		len += ft_printstr(va_arg(args, char *)); 
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				i;
	unsigned int	len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_parse(&str[i], args);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

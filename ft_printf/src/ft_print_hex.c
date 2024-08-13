/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:03:06 by rucorrei          #+#    #+#             */
/*   Updated: 2024/08/13 16:30:30 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* Returns print length */
int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int n, const char format)
{
	if (n == 0)
		return ;
	ft_put_hex(n / 16, format);
	if (format == 'x')
		ft_printchar("0123456789abcdef"[n % 16]);
	else
		ft_printchar("0123456789ABCDEF"[n % 16]);
}

int	ft_print_hex(unsigned int n, const char format)
{
	if (n == 0)
		return (ft_printchar('0'));
	else
		ft_put_hex(n, format);
	return (ft_hex_len(n));
}

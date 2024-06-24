/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:03:06 by rucorrei          #+#    #+#             */
/*   Updated: 2024/06/24 23:39:00 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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
		ft_putchar("0123456789abcdef"[n % 16]);
	else
		ft_putchar("0123456789ABCDEF"[n % 16]);
}

int	ft_print_hex(unsigned int n, const char format)
{
	if(n == 0)
		return (ft_printchar('0'));
	else
		ft_put_hex(n, format);

	return (ft_hex_len(n));
}

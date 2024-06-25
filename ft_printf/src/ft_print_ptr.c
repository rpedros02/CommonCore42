/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:45:18 by rucorrei          #+#    #+#             */
/*   Updated: 2024/06/25 12:01:37 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long ptr)
{
	if (ptr == 0)
		return ;
	ft_put_ptr(ptr / 16);
	ft_printchar("0123456789abcdef"[ptr % 16]);
}

/* Returns print length. */
int	ft_print_ptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len += ft_printstr("(nil)");
	else
	{
		ft_printstr("0x");
		len += 2;
		ft_put_ptr(ptr);
		len += ft_ptr_len(ptr);
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:45:18 by rucorrei          #+#    #+#             */
/*   Updated: 2024/06/24 23:07:20 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

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
	ft_putchar("0123456789abcdef"[ptr % 16]);
}

/* Returns print length. */
int	ft_print_ptr(unsigned long ptr)
{
	int	len;

	len = 0;
	ft_putstr("0x");
	len += 2;
	if (ptr == 0)
	{
		ft_putchar('0');
		len++;
	}
	else
	{
		ft_put_ptr(ptr);
		len += ft_ptr_len(ptr);
	}
	return (len);
}
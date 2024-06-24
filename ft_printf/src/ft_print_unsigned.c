/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:55:11 by rucorrei          #+#    #+#             */
/*   Updated: 2024/06/24 23:07:14 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

/* Returns unsigned int length */
int	ft_unsigned_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

/* Prints an unsigned int, returns string size */
int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(n);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

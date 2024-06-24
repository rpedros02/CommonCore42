/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:18:30 by rucorrei          #+#    #+#             */
/*   Updated: 2024/06/24 22:38:07 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

/* Prints a char, returns 1 */
int	ft_printchar(char c)
{
	ft_putchar(c);
	return (1);
}

/* Prints a string, returns size */
int	ft_printstr(char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr(str);
	return (ft_strlen(str));
}

/* Prints an int, returns string size */
int	ft_print_int(int n)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:18:30 by rucorrei          #+#    #+#             */
/*   Updated: 2024/06/17 16:20:03 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int ft_printchar(char c)
{
	ft_putchar(c);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;
	
	len = 0;
	while (str[len] != '\0'){
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}

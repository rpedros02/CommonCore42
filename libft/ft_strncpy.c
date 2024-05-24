/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:11:23 by rucorrei          #+#    #+#             */
/*   Updated: 2024/01/08 18:12:04 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char const *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < size - 1)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

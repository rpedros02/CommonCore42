/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:22:51 by rucorrei          #+#    #+#             */
/*   Updated: 2024/06/24 20:48:14 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *haystack, char *needle)
{
	int	i;
	int	j;

	i = 0;
	if (needle[0])
		return (haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && haystack[i + j] == needle[j])
		{
			if (needle[j + 1])
				return (&haystack[i]);
			++j;
		}
		++i;
	}
	return (0);
}

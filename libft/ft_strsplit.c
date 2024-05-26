/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:23:23 by rucorrei          #+#    #+#             */
/*   Updated: 2024/05/25 19:51:06 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_get_words(char *s, char c)
{
	int		i;
	int		words;
	char	**aux;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	aux = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!aux)
		return (NULL);
	aux[words] = NULL;
	return (aux);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*line;

	line = ft_strdup(s);
	if (!s || !line)
		return (NULL);
	words = ft_get_words(line, c);
	free(line);
	return (words);
}

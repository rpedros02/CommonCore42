/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:23:23 by rucorrei          #+#    #+#             */
/*   Updated: 2024/02/12 12:40:54 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

char	*ft_get_word(char *word, char c)
{
	char	*start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

void	ft_free_words(char **words, size_t i)
{
	while (i--)
		ft_strdel(&(words[i]));
	free(*words);
}

char	**ft_get_words(char *s, char c, size_t words_count)
{
	char	**words;
	size_t	i;

	words = (char **)ft_memalloc(sizeof(char *) * (words_count + 1));
	i = 0;
	if (words)
	{
		while (i < words_count)
		{
			if (*s)
			{
				words[i] = ft_get_word(s, c);
				if (!words[i])
				{
					ft_free_words(words, i);
					return (NULL);
				}
				s += (ft_strlen(words[i]) + 1);
				i++;
			}
		}
		words[i] = NULL;
	}
	return (words);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*line;

	line = ft_strdup((char *) s);
	if (!s || !line)
		return (NULL);
	words = ft_get_words(line, c, ft_count_words(line, c));
	free(line);
	return (words);
}

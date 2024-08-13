/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:28:34 by rucorrei          #+#    #+#             */
/*   Updated: 2024/08/13 18:26:28 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Get the lenght of the line from the list node. */
int	get_len(t_list *list)
{
	int	len;
	int	i;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			len++;
			i++;
			if (list->buffer[i] == '\n')
			{
				return (len);
			}
		}
		list = list->next;
	}
	return (len);
}
/* Copy the line from the node into a string */

void	copy_line(t_list *list, char *str)
{
	int	i;
	int	j;

	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			str[j++] = list->buffer[i++];
			if (list->buffer[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
		}
		list = list->next;
	}
	str[j] = '\0';
}

/* Polish list for next call */
void	polish_list(t_list **list)
{
	t_list	*last;
	t_list	*tmp;
	int		i;
	int		j;
	char	*line;

	tmp = malloc(sizeof(t_list));
	line = malloc(BUFFER_SIZE + 1);
	if (!line || !tmp)
		return ;
	last = find_last(*list);
	i = 0;
	j = 0;
	while (last->buffer[i]
		&& last->buffer[i] != '\n')
		++i;
	while (last->buffer[i]
		&& last->buffer[++i])
		line[j++] = last->buffer[i];
	line[j] = '\0';
	tmp->buffer = line;
	tmp->next = NULL;
	free_all(list, tmp, line);
}

void	free_all(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->buffer);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->buffer[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}

int	found_nl(t_list *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buffer[i] && i < BUFFER_SIZE)
		{
			if (list->buffer[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

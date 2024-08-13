/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:27:10 by rucorrei          #+#    #+#             */
/*   Updated: 2024/08/13 19:30:02 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line(list);
	polish_list(&list);
	return (next_line);
}
/* Creates a list with all the lines on the file */

void	create_list(t_list **list, int fd)
{
	int		c_read;
	char	*line;

	while (!found_nl(*list))
	{
		line = malloc(BUFFER_SIZE + 1);
		if (!line)
			return ;
		c_read = read(fd, line, BUFFER_SIZE);
		if (!c_read)
		{
			free(line);
			return ;
		}
		line[c_read] = '\0';
		append(list, line);
	}
}
/* Append node to list */

void	append(t_list **list, char *line)
{
	t_list	*new;
	t_list	*last;

	last = find_last(*list);
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	if (!last)
		*list = new;
	else
		last->next = new;
	new->buffer = line;
	new->next = NULL;
}
/* Find last node on list */

t_list	*find_last(t_list *list)
{
	t_list	*last;

	last = list;
	if (!last)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}
/* Get that line! */

char	*get_line(t_list *list)
{
	int		len;
	char	*line;

	if (!list)
		return (NULL);
	len = get_len(list);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	copy_line(list, line);
	return (line);
}

/* int	main()
{
	int fd;
	char *line;
	int lines;
	
	lines = 0;
	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		++lines;
	}
	printf("number of lines: %d\n", lines);
} */
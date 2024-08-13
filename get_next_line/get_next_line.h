/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:28:30 by rucorrei          #+#    #+#             */
/*   Updated: 2024/08/13 18:25:34 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	char			*buffer;
	struct s_list	*next;
}	t_list;
char	*get_next_line(int fd);
int		found_nl(t_list *list);
void	create_list(t_list **list, int fd);
void	append(t_list **list, char *line);
t_list	*find_last(t_list *list);
char	*get_line(t_list *list);
int		get_len(t_list *list);
void	copy_line(t_list *list, char *str);
void	free_all(t_list **list, t_list *clean_node, char *buf);
void	polish_list(t_list **list);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:39:45 by rucorrei          #+#    #+#             */
/*   Updated: 2024/06/24 20:48:51 by rucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = ft_lstlast(*(lst));
			temp->next = new;
		}
	}
}

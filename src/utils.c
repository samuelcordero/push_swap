/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 00:10:10 by sacorder          #+#    #+#             */
/*   Updated: 2023/07/06 00:49:59 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_duplicates(t_list *list)
{
	t_list	*current;
	t_list	*next;
	int		*current_content;
	int		*next_content;

	current = list;
	while (current != NULL)
	{
		current_content = (int *) current->content;
		next = current->next;
		while (next != NULL)
		{
			next_content = (int *) next->content;
			if (*current_content == *next_content)
				return (1);
			next = next->next;
		}
		current = current->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 00:10:10 by sacorder          #+#    #+#             */
/*   Updated: 2023/07/12 17:14:20 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_clrintlst_content(void *content)
{
	int	*content_cast;

	content_cast = content;
	free(content_cast);
}

static void	asgn_relative_val(t_list *to_asgn, t_list *list, t_list *current)
{
	int	*to_asgn_content;
	int	*current_content;
	int	*tmp_content;

	to_asgn->content = malloc(sizeof(int));
	if (!to_asgn->content)
		exit(-1);
	to_asgn_content = to_asgn->content;
	current_content = current->content;
	*to_asgn_content = 0;
	while (list)
	{
		tmp_content = list->content;
		if (*tmp_content < *current_content)
			++(*to_asgn_content);
		list = list->next;
	}
}

t_list	*reformat_list(t_list *list)
{
	t_list	*new_list;
	t_list	*current;
	t_list	*current_new;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		exit(-1);
	current = list;
	current_new = new_list;
	while (current)
	{
		asgn_relative_val(current_new, list, current);
		if (current->next)
		{
			current_new->next = malloc(sizeof(t_list));
			if (!current_new->next)
				exit(-1);
			current_new = current_new->next;
		}
		current = current->next;
	}
	current_new->next = NULL;
	ft_lstclear(&list, &ft_clrintlst_content);
	return (new_list);
}

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

void	print_stack(t_list *stack)
{
	int		*content;
	t_list	*current;

	current = stack;
	while (current)
	{
		content = (int *) current->content;
		ft_printf("Node content: %i\n\n", *content);
		current = current->next;
	}
}

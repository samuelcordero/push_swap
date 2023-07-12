/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:36:41 by sacorder          #+#    #+#             */
/*   Updated: 2023/07/12 17:53:14 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_sorted(t_list *stack)
{
	int		*content;
	int		*prev_content;
	t_list	*node;

	node = stack;
	prev_content = node->content;
	while(node)
	{
		content = node->content;
		if (*content < *prev_content)
			return (0);
		prev_content = content;
		node = node->next;
	}
	return (1);
}

static void	radix_sort(t_list *stack_a, t_list *stack_b)
{
	int		*content;
	int		loop_ctr;
	t_list	*first_rotated;

	loop_ctr = 0;
	while(!is_sorted(stack_a))
	{
		first_rotated = NULL;
		while(first_rotated != stack_a)
		{
			content = stack_a->content;
			if (!(*content & (1 << loop_ctr)))
				push(&stack_b, &stack_a, "pb");
			else
			{
				if (!first_rotated)
					first_rotated = stack_a;
				rotate(&stack_a, "ra");
			}
		}
		while (stack_b)
			push(&stack_a, &stack_b, "pa");
		++loop_ctr;
	}
}

void	sort(t_list *stack_a, int argc)
{
	t_list *stack_b;

	stack_b = NULL;
	if (argc == 2)
		return ;
	else
		radix_sort(stack_a, stack_b);
}

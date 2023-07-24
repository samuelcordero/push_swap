/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:36:41 by sacorder          #+#    #+#             */
/*   Updated: 2023/07/24 17:00:31 by sacorder         ###   ########.fr       */
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
	while (node)
	{
		content = node->content;
		if (*content < *prev_content)
			return (0);
		prev_content = content;
		node = node->next;
	}
	return (1);
}

static void	sort_three(t_list *stack_a, t_list *stack_b)
{
	int	*a;
	int	*b;
	int	*c;

	a = stack_a->content;
	b = stack_a->next->content;
	c = stack_a->next->next->content;
	(void) stack_b;
	if (*a > *b && *b < *c && *a < *c)
		swap(&stack_a, "sa");
	else if (*a > *b && *b > *c)
	{
		swap(&stack_a, "sa");
		rev_rotate(&stack_a, "rra");
	}
	else if (*a > *b && *b < *c && *a > *c)
		rotate(&stack_a, "ra");
	else if (*a < *b && *b > *c && *a < *c)
	{
		swap(&stack_a, "sa");
		rotate(&stack_a, "ra");
	}
	else if (*a < *b && *b > *c && *a > *c)
		rev_rotate(&stack_a, "rra");
}

static void	sort_ltf(t_list *stack_a, t_list *stack_b, int argc)
{
	push(&stack_b, &stack_a, "pb");
	if (argc == 6)
		push(&stack_b, &stack_a, "pb");
	sort_three(stack_a, stack_b);
	push(&stack_a, &stack_b, "pa");
	rotate(&stack_a, "ra");
	push(&stack_a, &stack_b, "pa");
}

static void	radix_sort(t_list *stack_a, t_list *stack_b)
{
	int		*content;
	int		loop_ctr;
	t_list	*first_rotated;

	loop_ctr = 0;
	while (!is_sorted(stack_a))
	{
		first_rotated = NULL;
		while (first_rotated != stack_a && !is_sorted(stack_a))
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
	t_list	*stack_b;

	stack_b = NULL;
	if (argc == 2)
		return ;
	else if (argc == 4)
		sort_three(stack_a, stack_b);
	else if (argc >= 5 && argc <= 6)
		sort_ltf(stack_a, stack_b, argc);
	else
		radix_sort(stack_a, stack_b);
}

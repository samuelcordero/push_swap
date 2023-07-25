/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:36:41 by sacorder          #+#    #+#             */
/*   Updated: 2023/07/25 20:34:00 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_three(t_list **stack_a, t_list **stack_b)
{
	int	*a;
	int	*b;
	int	*c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	(void) stack_b;
	if (*a > *b && *b < *c && *a < *c)
		swap(stack_a, "sa\n");
	else if (*a > *b && *b > *c)
	{
		swap(stack_a, "sa\n");
		rev_rotate(stack_a, "rra\n");
	}
	else if (*a > *b && *b < *c && *a > *c)
		rotate(stack_a, "ra\n");
	else if (*a < *b && *b > *c && *a < *c)
	{
		swap(stack_a, "sa\n");
		rotate(stack_a, "ra\n");
	}
	else if (*a < *b && *b > *c && *a > *c)
		rev_rotate(stack_a, "rra\n");
}

static void	sort_ltf(t_list **stack_a, t_list **stack_b, int argc)
{
	if (*(int *) (ft_lstlast(*stack_a)->content) == 0)
		rev_rotate(stack_a, "rra\n");
	else
	{
		while (*(int *) ((*stack_a)->content) != 0)
			rotate(stack_a, "ra\n");
	}
	push(stack_b, stack_a, "pb\n");
	if (argc == 6)
	{
		while (*(int *) ((*stack_a)->content) != 1)
			rotate(stack_a, "ra\n");
		push(stack_b, stack_a, "pb\n");
	}
	sort_three(stack_a, stack_b);
	while (*stack_b)
		push(stack_a, stack_b, "pa\n");
}

static void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		*content;
	int		loop_ctr;
	t_list	*first_rotated;

	loop_ctr = 0;
	while (!is_sorted(stack_a))
	{
		first_rotated = NULL;
		while (first_rotated != *stack_a && !is_sorted(stack_a))
		{
			content = (*stack_a)->content;
			if (!(*content & (1 << loop_ctr)))
				push(stack_b, stack_a, "pb\n");
			else
			{
				if (!first_rotated)
					first_rotated = *stack_a;
				rotate(stack_a, "ra\n");
			}
		}
		while (*stack_b)
			push(stack_a, stack_b, "pa\n");
		++loop_ctr;
	}
}

void	sort(t_list **stack_a, int argc)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (is_sorted(stack_a))
		return ;
	else if (argc == 4)
		sort_three(stack_a, &stack_b);
	else if (argc >= 5 && argc <= 6)
		sort_ltf(stack_a, &stack_b, argc);
	else
		radix_sort(stack_a, &stack_b);
}

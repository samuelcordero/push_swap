/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:16:54 by sacorder          #+#    #+#             */
/*   Updated: 2023/07/12 12:58:17 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_list **stack_to, t_list **stack_from, char *str)
{
	t_list	*first_right;
	t_list	*second_right;

	first_right = *stack_from;
	second_right = (*stack_from)->next;
	first_right->next = *stack_to;
	*stack_to = first_right;
	*stack_from = second_right;
	ft_putendl_fd(str, 1);
}

void	swap(t_list **stack, char *str)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	second_node = (*stack)->next;
	if ((*stack)->next)
	{
		*stack = second_node;
		first_node->next = second_node->next;
		second_node->next = first_node;
	}
	ft_putendl_fd(str, 1);
}

void	rotate(t_list **stack, char *str)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	second_node = (*stack)->next;
	if ((*stack)->next)
	{
		*stack = second_node;
		first_node->next = NULL;
		ft_lstadd_back(stack, first_node);
		
	}
	ft_putendl_fd(str, 1);
}

void	rev_rotate(t_list **stack, char *str)
{
	t_list	*first_node;
	t_list	*last_node;
	t_list	*prev_last_node;

	first_node = *stack;
	prev_last_node = *stack;
	last_node = (*stack)->next;
	while (last_node->next)
	{
		prev_last_node = last_node;
		last_node = last_node->next;
	}
	if ((*stack)->next)
	{
		*stack = last_node;
		last_node->next = first_node;
		prev_last_node->next = NULL;
	}
	ft_putendl_fd(str, 1);
}

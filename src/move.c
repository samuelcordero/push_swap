/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:16:54 by sacorder          #+#    #+#             */
/*   Updated: 2023/07/08 17:17:33 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* void	push(t_list **stack_in, t_list **stack_out)
{
	
} */

void	swap(t_list **stack, char *str)
{
	t_list	*firstNode;
	t_list	*secondNode;

	firstNode = *stack;
	secondNode = (*stack)->next;
	*stack = secondNode;
	firstNode->next = secondNode->next;
	secondNode->next = firstNode;
	ft_putendl_fd(str, 1);
}

/* void	rotate(t_list **stack_in, t_list **stack_out)
{
		
}

void	rev_rotate(t_list **stack_in, t_list **stack_out)
{
		
} */
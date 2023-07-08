/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:51:34 by sacorder          #+#    #+#             */
/*   Updated: 2023/07/08 17:07:06 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

//utils.c
void	ft_clrintlst_content(void *content);
t_list	*reformat_list(t_list *list);
int		check_duplicates(t_list *list);
void	print_stack(t_list *stack);

//sort.c
void	sort(t_list *stack_a, int argc);

//move.c
void	swap(t_list **stack, char *str);

#endif
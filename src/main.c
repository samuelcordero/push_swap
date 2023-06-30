/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:53:41 by sacorder          #+#    #+#             */
/*   Updated: 2023/06/30 16:00:18 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc)
{
	t_list *a;
	t_list *b;

	if (argc < 2)
		return (-1); //not enough args
	if (argc == 2)
		return (0); //we shold check if its an integer but we suppose it is for the moment, in case it is it is already sorted
	
	return (0);
}
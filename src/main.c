/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:53:41 by sacorder          #+#    #+#             */
/*   Updated: 2023/07/25 21:12:55 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	init_stack(t_list *stack, char **argv)
{
	t_list	*current;
	int		i;
	int		*content;

	current = stack;
	i = 0;
	while (argv[++i])
	{
		current->content = malloc(sizeof(int));
		if (!current->content)
			exit(-1);
		content = (int *) current->content;
		*content = ft_atoi(argv[i]);
		if (argv[i + 1])
		{
			current->next = malloc(sizeof(t_list));
			if (!current->next)
				exit(-1);
			current = current->next;
		}
		else
			current->next = NULL;
	}
}

static t_list	*parse_check_list(t_list *list)
{
	t_list	*res;

	res = reformat_list(list);
	if (check_duplicates(res))
	{
		ft_putendl_fd("Error!", 2);
		exit (1);
	}
	return (res);
}

int	main(int argc, char **argv)
{
	t_list	*a;

	check_args(argv, argc);
	a = malloc(sizeof(t_list));
	if (!a)
		return (1);
	init_stack(a, argv);
	a = parse_check_list(a);
	sort(&a, argc);
	ft_lstclear(&a, &ft_clrintlst_content);
	return (0);
}

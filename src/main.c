/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:53:41 by sacorder          #+#    #+#             */
/*   Updated: 2023/07/27 11:38:35 by sacorder         ###   ########.fr       */
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
			print_error_exit();
		content = (int *) current->content;
		*content = ft_atoi(argv[i]);
		if (argv[i + 1])
		{
			current->next = malloc(sizeof(t_list));
			if (!current->next)
				print_error_exit();
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
		print_error_exit();
	return (res);
}

int	main(int argc, char **argv)
{
	t_list	*a;

	if (argc < 2)
		print_error_exit();
	check_args(argv);
	a = malloc(sizeof(t_list));
	if (!a)
		print_error_exit();
	init_stack(a, argv);
	a = parse_check_list(a);
	sort(&a, argc);
	ft_lstclear(&a, &ft_clrintlst_content);
	return (0);
}

/*
void	leaks(void)
{
	system("leaks -q push_swap");
}
*/
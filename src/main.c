/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:53:41 by sacorder          #+#    #+#             */
/*   Updated: 2023/07/25 12:50:56 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_space_sign(char c)
{
	if (c == ' ' || c == '+' || c == '-' || c == '\v'
		|| c == '\t' || c == '\r' || c == '\n' || c == '\f')
		return (c);
	return (0);
}

static void	check_args(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		exit (-1);
	while (argv[++i])
	{
		if (!*argv[i])
		{
			ft_putendl_fd("Error!", 2);
			exit (-1);
		}
		j = -1;
		while (argv[i][++j])
		{
			if ((!ft_isdigit(argv[i][j]) && !ft_space_sign(argv[i][j]))
					|| (argv[i][j] == '+' && !ft_isdigit(argv[i][j + 1]))
					|| (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1])))
			{
				ft_putendl_fd("Error!", 2);
				exit (-1);
			}
		}
	}
}

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
	if (check_duplicates(list))
		exit (-1);
	return (reformat_list(list));
}

int	main(int argc, char **argv)
{
	t_list	*a;

	check_args(argv, argc);
	a = malloc(sizeof(t_list));
	if (!a)
		return (-1);
	init_stack(a, argv);
	a = parse_check_list(a);
	sort(&a, argc);
	print_stack(a);
	return (0);
}

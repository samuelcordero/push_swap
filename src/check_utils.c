/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:39:53 by sacorder          #+#    #+#             */
/*   Updated: 2023/07/31 11:52:55 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\v'
		|| c == '\t' || c == '\r' || c == '\n' || c == '\f')
		return (c);
	return (0);
}

static void	str_int_limits(char *str)
{
	int	pos;
	int	limit;
	int	length;

	pos = 0;
	limit = 0;
	while (ft_isspace(str[pos]))
		++pos;
	if (str[pos] == '+')
		++pos;
	else if (str[pos] == '-')
		limit = ++pos;
	while (str[pos] == '0')
		++pos;
	length = ft_strlen(&str[pos]);
	if (length == 10)
	{
		if ((limit && ft_strncmp(&str[pos], "2147483648", length) > 0)
			|| (!limit && ft_strncmp(&str[pos], "2147483647", length) > 0))
			print_error_exit();
	}
	else if (length > 10)
		print_error_exit();
}

static void	check_str_numeric(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		++i;
	if ((str[i] != '+' && str[i] != '-') && !ft_isdigit(str[i]))
		print_error_exit();
	else if (str[i] == '+' || str[i] == '-')
		++i;
	if (!ft_isdigit(str[i]))
		print_error_exit();
	while (ft_isdigit(str[i]))
		++i;
	while (ft_isspace(str[i]))
		++i;
	if (str[i])
		print_error_exit();
}

void	check_args(char **in)
{
	int	i;

	i = 0;
	while (in[++i])
	{
		if (!*in[i])
			print_error_exit();
		str_int_limits(in[i]);
		check_str_numeric(in[i]);
	}
}

int	is_sorted(t_list **stack)
{
	int		*content;
	int		*prev_content;
	t_list	*node;

	node = *stack;
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

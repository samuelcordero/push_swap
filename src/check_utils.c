/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:39:53 by sacorder          #+#    #+#             */
/*   Updated: 2023/07/26 16:18:33 by sacorder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_space_sign_zero(char c)
{
	if (c == ' ' || c == '+' || c == '-' || c == '\v' || c == '0'
		|| c == '\t' || c == '\r' || c == '\n' || c == '\f')
		return (c);
	return (0);
}

static int	str_int_limits(char *str)
{
	int	pos;
	int	limit;
	int	length;

	pos = 0;
	limit = 0;
	while (ft_space_sign_zero(str[pos]))
		++pos;
	if (pos && (str[pos - 1] == '-'))
		limit = 1;
	length = ft_strlen(&str[pos]);
	if (length == 10)
	{
		if ((limit && ft_strncmp(&str[pos], "2147483648", length) > 0)
			|| (!limit && ft_strncmp(&str[pos], "2147483647", length) > 0))
			return (1);
	}
	else if (length > 10)
		return (1);
	return (0);
}

void	check_args(char **in)
{
	int	i;
	int	j;
	int	digit_flag;

	i = 0;
	while (in[++i])
	{
		if (!*in[i] || str_int_limits(in[i]))
			print_error_exit();
		j = -1;
		digit_flag = 0;
		while (in[i][++j])
		{
			if ((!ft_isdigit(in[i][j]) && !ft_space_sign_zero(in[i][j])) ||
					((in[i][j] == '+' || in[i][j] == '-') &&
					(!ft_isdigit(in[i][j + 1]))) || (j > 0 && (in[i][j] == '+'
					|| in[i][j] == '-') && in[i][j - 1] != ' '))
				print_error_exit();
			if (!digit_flag && ft_isdigit(in[i][j]))
				digit_flag = 1;
		}
		if (!digit_flag)
			print_error_exit();
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

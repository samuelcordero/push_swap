/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacorder <sacorder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:39:53 by sacorder          #+#    #+#             */
/*   Updated: 2023/07/25 19:13:55 by sacorder         ###   ########.fr       */
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

void	check_args(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		exit (-1);
	while (argv[++i])
	{
		if (!*argv[i] || str_int_limits(argv[i]))
		{
			ft_putendl_fd("Error!", 2);
			exit (-1);
		}
		j = -1;
		while (argv[i][++j])
		{
			if ((!ft_isdigit(argv[i][j]) && !ft_space_sign_zero(argv[i][j]))
					|| (argv[i][j] == '+' && !ft_isdigit(argv[i][j + 1]))
					|| (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1])))
			{
				ft_putendl_fd("Error!", 2);
				exit (-1);
			}
		}
	}
}

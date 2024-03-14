/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:13:10 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/13 08:15:33 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_letter(int i, char **argv);
static bool	check_double_arg(t_stacks stacks);

bool	parsing(t_stacks stacks, int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (false);
	if (!check_double_arg(stacks))
		return (false);
	i = 1;
	while (i < argc)
	{
		if (!check_letter(i, argv))
			return (false);
		i++;
	}
	return (true);
}

static bool	check_double_arg(t_stacks stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks.len_a)
	{
		if (stacks.a[i] >= INT_MAX)
			return (false);
		j = 0;
		while (j < stacks.len_a)
		{
			if (stacks.a[i] == stacks.a[j] && i != j)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	check_letter(int i, char **argv)
{
	int	j;

	j = 0;
	while (argv[i][j])
	{
		if ((!(argv[i][j] >= '0' && argv[i][j] <= '9')) &&
			argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' ')
			return (false);
		if ((argv[i][j] == '-' || argv[i][j] == '+') &&
			!(argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9'))
			return (false);
		if (argv[i][j] >= '0' && argv[i][j] <= '9')
			if (!(argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9') &&
				argv[i][j + 1] != ' ' && argv[i][j + 1] != 0)
				return (false);
		j++;
	}
	return (true);
}

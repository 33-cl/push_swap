/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:13:10 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/06 17:50:55 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_double_arg(int argc, char **args);
bool	check_letter(int i, char **argv);


bool	parsing(int	argc, char **argv)
{
	int	i;
	
	if (argc < 2)
		return (false);
	if (!check_double_arg(argc, argv))
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
	

bool	check_double_arg(int argc, char **args)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!check_letter(i, args))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_letter(int i, char **argv)
{
	int	j;

	j = 0;
	while(argv[i][j])
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
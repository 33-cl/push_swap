/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:25:01 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/13 21:01:52 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_stack(int *stack, int *len_stack, int value)
{
	int	i;

	i = *len_stack;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	(*len_stack)++;
	stack[0] = value;
	stack[*len_stack] = 0;
	stack[*len_stack + 1] = 0;
}

void	remove_stack(int *stack, int *len_stack)
{
	int	i;

	i = 0;
	while (i < *len_stack)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	(*len_stack)--;
}

static bool	create_a(t_stacks *stacks, int argc, char **argv)
{
	int	i;

	i = -1;
	while (i++, i < stacks->len_a)
	{
		if (ft_atoi(argv[i + (argc != 2)]) >= INT_MAX
			|| ft_atoi(argv[i + (argc != 2)]) <= INT_MIN
			|| ft_strlen(argv[i + (argc != 2)]) > 10)
			return (write(2, "Error\n", 6), false);
		stacks->a[i] = ft_atoi(argv[i + (argc != 2)]);
	}
	return (true);
}

bool	create_stacks(t_stacks *stacks, int argc, char **argv)
{
	int			i;
	int			error;

	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv || argc <= 1)
		return (false);
	i = 0;
	while (argv[i] && argv[i + 1])
		i++;
	i += (argc == 2);
	stacks->a = malloc(sizeof(int) * (i + 2));
	stacks->b = malloc(sizeof(int) * (i + 2));
	stacks->len_a = i;
	stacks->len_b = 0;
	stacks->len_total = i;
	if (!create_a(stacks, argc, argv))
		return (false);
	stacks->a[i] = 0;
	stacks->a[i + 1] = 0;
	stacks->b[0] = 0;
	stacks->b[1] = 0;
	if (argc == 2)
		free_map(argv);
	return (true);
}

int	stack_len(int *stack)
{
	int	length;

	length = 0;
	while (*stack != 0 && *(stack + 1) != 0)
	{
		length++;
		stack++;
	}
	return (length);
}

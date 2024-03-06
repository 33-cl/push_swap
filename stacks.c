/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:25:01 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/06 18:18:08 by maeferre         ###   ########.fr       */
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

bool	create_stacks(t_stacks *stacks, int argc, char **argv)
{
	int		i;
	
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv || argc <= 1)
		return (printf("Error\n"), false);
	i = 0;
	while (argv[i] && argv[i + 1])
		i++;
	stacks->a = malloc(sizeof(int) * (i + 2));
	stacks->b = malloc(sizeof(int) * (i + 2));
	stacks->len_a = i + (argc == 2);
	stacks->len_b = 0;
	stacks->len_total = i;
	i = (argc != 2) - 1;
	while (i++, argv[i])
		stacks->a[i - (argc != 2)] = atoi(argv[i]);
	//i += (argc == 2);
	stacks->a[i - 1] = 0;
	stacks->a[i] = 0;
	stacks->b[0] = 0;
	stacks->b[1] = 0;
	if (argc == 2)
		free_map(argv);	
	return (true);
}

void	display_stacks(t_stacks stacks)
{	
	int	i;

	i = -1;
	printf("\n");
	while (i++, i < stacks.len_a || i < stacks.len_b )
	{
		printf("    ");
		//if (stacks.len_a > i)
			printf("%d ", stacks.a[i]);
		//if (stacks.len_b > i)
			printf("%d", stacks.b[i]);
		printf("\n");
	}
	printf("   \n    ---\n    a b\n-------------\n");
}

int		stack_len(int *stack)
{
	int length = 0;

	while (*stack != 0 && *(stack + 1) != 0) 
	{
		length++;
		stack++;
	}
	return (length);
}
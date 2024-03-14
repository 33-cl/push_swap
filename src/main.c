/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:06:08 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/13 19:51:51 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stacks *stacks);
void	radix_sort(t_stacks *stacks);
void	little_sort(t_stacks *stacks);

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (!create_stacks(&stacks, argc, argv))
		return (0);
	if (!parsing(stacks, argc, argv))
	{
		write(2, "Error\n", 6);
		free(stacks.a);
		free(stacks.b);
		return (0);
	}
	transform_stack(&stacks);
	if (stacks.len_a >= 6)
		radix_sort(&stacks);
	else if (!is_sorted(&stacks))
		little_sort(&stacks);
	free(stacks.a);
	free(stacks.b);
	return (0);
}

/*
	Main algorithm based on Radix sort method
*/

void	radix_sort(t_stacks *stacks)
{
	int	i;
	int	j;
	int	len_a;
	int	len_b;

	len_a = stacks->len_a;
	i = -1;
	while (i++, !is_sorted(stacks))
	{
		j = -1;
		while (j++, j < len_a)
		{
			if (((stacks->a[0] >> i) & 1) == 1)
				rotate_a(stacks);
			else
				push_b(stacks);
		}
		len_b = stacks->len_b;
		j = -1;
		while (j++, j < len_b)
			push_a(stacks);
	}
}

/*
	Returns a bool indicating if the list is sorted or not
	sorted     = true
	not sorted = false

*/

bool	is_sorted(t_stacks *stacks)
{
	int	i;

	if (stacks->len_b != 0)
		return (false);
	i = 1;
	while (i < stacks->len_a)
	{
		if (stacks->a[i - 1] > stacks->a[i])
			return (false);
		i++;
	}
	return (true);
}

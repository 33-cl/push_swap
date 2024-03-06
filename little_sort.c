/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:20:16 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/04 14:51:03 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sort(t_stacks *stacks);
void	three_sort(t_stacks *stacks);
void	four_sort(t_stacks *stacks);
void	five_sort(t_stacks *stacks);

void	little_sort(t_stacks *stacks)
{
	if (stacks->len_a == 2)
		two_sort(stacks);
	else if (stacks->len_a == 3)
		three_sort(stacks);
	else if (stacks->len_a == 4)
		four_sort(stacks);
	else if (stacks->len_a == 5)
		five_sort(stacks);
}

/*
-----------------------------------------
-----------------------------------------
*/

void	two_sort(t_stacks *stacks)
{
	if (stacks->len_a == 2 && stacks->a[0] > stacks->a[1])
		swap_a(stacks);
}

void	three_sort(t_stacks *stacks)
{
	two_sort(stacks);
	if (stacks->a[0] > stacks->a[1])
		swap_a(stacks);
	if (stacks->a[1] > stacks->a[2])
		reverse_rotate_a(stacks);
	if (stacks->a[0] > stacks->a[1])
		swap_a(stacks);
}

void	four_sort(t_stacks *stacks)
{
	int	i;
	int	j;
	int	smallest;

	i = -1;
	while (i++, i < 2)
	{
		j = 0;
		smallest = 0;
		while (j++, j < stacks->len_a)
			if (stacks->a[j] < stacks->a[smallest])
				smallest = j;
		j = -1;
		if (smallest < stacks->len_a / 2)
		{
			while (j++, j < smallest)
			{
				rotate_a(stacks);
			}
		}
		else
		{
			while (j++, j < (stacks->len_a - smallest))
			{
				reverse_rotate_a(stacks);
			}
		}
		push_b(stacks);
	}
	two_sort(stacks);
	push_a(stacks);
	push_a(stacks);
}

void	five_sort(t_stacks *stacks)
{
	int	i;
	int	j;
	int	smallest;

	i = -1;
	while (i++, i < 2)
	{
		j = 0;
		smallest = 0;
		while (j++, j < stacks->len_a)
			if (stacks->a[j] < stacks->a[smallest])
				smallest = j;
		j = -1;
		if (smallest < stacks->len_a / 2)
		{
			while (j++, j < smallest)
			{
				rotate_a(stacks);
			}
		}
		else
		{
			while (j++, j < (stacks->len_a - smallest))
			{
				reverse_rotate_a(stacks);
			}
		}
		push_b(stacks);
	}
	three_sort(stacks);
	push_a(stacks);
	push_a(stacks);
}

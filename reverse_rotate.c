/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:23:50 by maeferre          #+#    #+#             */
/*   Updated: 2024/02/15 20:41:44 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stacks *stacks)
{
	int	value;
	int	i;

	value = stacks->a[stacks->len_a - 1];
	
	i = stacks->len_a;
	while (i > 0)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[0] = value;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stacks *stacks)
{
	int	value;
	int	i;

	value = stacks->b[stacks->len_b - 1];
	
	i = stacks->len_b;
	while (i > 0)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
	}
	stacks->b[0] = value;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_stacks *stacks)
{
	reverse_rotate_a(stacks);
	reverse_rotate_b(stacks);
}
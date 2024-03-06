/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:40:39 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/04 11:17:54 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stacks)
{
	int	i;
	int	end;
	int	value;
	
	if (stacks->len_a < 2)
		return ;
	i = 0;
	end = stacks->len_a;
	value = stacks->a[0];
	while (i < end - 1)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->a[stacks->len_a - 1] = value;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stacks *stacks)
{
	int	i;
	int	end;
	int	value;
	
	if (stacks->len_b < 2)
		return ;
	i = 0;
	end = stacks->len_b;
	value = stacks->b[0];
	while (i < end - 1)
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[stacks->len_b - 1] = value;
}

void	rotate_both(t_stacks *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
}
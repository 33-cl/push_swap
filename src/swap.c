/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:45:10 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/13 08:08:52 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	if (stacks->len_a >= 2)
	{
		ft_swap(&stacks->a[0], &stacks->a[1]);
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_stacks *stacks)
{
	if (stacks->len_b >= 2)
	{
		ft_swap(&stacks->b[0], &stacks->b[1]);
		write(1, "sb\n", 3);
	}
}

void	swap_both(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}

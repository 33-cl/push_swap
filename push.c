/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:59:55 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/04 11:18:28 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *stacks)
{
	add_stack(stacks->a, &stacks->len_a, stacks->b[0]);
	remove_stack(stacks->b, &stacks->len_b);
	write(1, "pa\n", 3);
}

void	push_b(t_stacks *stacks)
{
	add_stack(stacks->b, &stacks->len_b, stacks->a[0]);
	remove_stack(stacks->a, &stacks->len_a);
	write(1, "pb\n", 3);
}
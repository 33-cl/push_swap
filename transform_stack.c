/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:59:30 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/06 16:01:24 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	transform_stack(t_stacks *stacks)
{
	int	*sorted_tab;
	int	map_values[stacks->len_a];
	int	value;
	int	i;
	int	j;

	sorted_tab = malloc(stacks->len_a * sizeof(int));
	if (!sorted_tab)
		return ;
	i = -1;
	while (i++, i < stacks->len_a)
		sorted_tab[i] = stacks->a[i];
	ft_sort_int_tab(sorted_tab, stacks->len_a);
	i = -1;
	while (i++, i < stacks->len_a)
		map_values[i] = -1;
	value = 1;
	i = -1;
	while (i++, i < stacks->len_a)
		if (map_values[i] == -1)
			map_values[i] = value++;
	i = -1;
	while (i++, i < stacks->len_a)
	{
		j = 0;
		while (stacks->a[i] != sorted_tab[j])
			j++;
		stacks->a[i] = map_values[j];
	}
	free(sorted_tab);
}

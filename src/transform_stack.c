/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:59:30 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/14 14:05:57 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_a_and_free(t_stacks *stacks, int *sorted_tab, int *map_values);

void	transform_stack(t_stacks *stacks)
{
	int	*sorted_tab;
	int	*map_values;
	int	value;
	int	i;
	int	j;

	sorted_tab = malloc(stacks->len_a * sizeof(int));
	map_values = malloc(stacks->len_a * sizeof(int));
	if (!sorted_tab || !map_values)
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
	fill_a_and_free(stacks, sorted_tab, map_values);
}

static void	fill_a_and_free(t_stacks *stacks, int *sorted_tab, int *map_values)
{
	int	i;
	int	j;

	i = -1;
	while (i++, i < stacks->len_a)
	{
		j = 0;
		while (stacks->a[i] != sorted_tab[j])
			j++;
		stacks->a[i] = map_values[j];
	}
	free(sorted_tab);
	free(map_values);
}

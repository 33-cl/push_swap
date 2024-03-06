/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:06:08 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/06 17:58:05 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stacks *stacks, int first_neg);
void	radix_sort(t_stacks *stacks);
void	little_sort(t_stacks *stacks);


/*

	-----ALGO-----
	
	- Pour chaque chiffre du plus grand element
		* decouper la liste en 2 box en fonction du bit selectionne
		* regrouper dans A

	Fin.


*/

int		main(int argc, char **argv)
{
	t_stacks	stacks;
	bool		error;

	// CHECKER QUE ARGV CONTIENNE DES VALEURS VALIDES

	
	if (!parsing(argc, argv))
		return (write(2, "error\n", 6), 0);

	if (!create_stacks(&stacks, argc, argv))
		return (write(2, "error\n", 6), 0);
	transform_stack(&stacks);

	//display_stacks(stacks);

	if (argc > 6 || argc == 2)
		radix_sort(&stacks);
	else
		little_sort(&stacks);

	display_stacks(stacks);

	free(stacks.a);
	free(stacks.b);
	return (0);
}

/*

	---------------------------------------------------------

*/

void	radix_sort(t_stacks *stacks)
{
	int	i;
	int	j;
	int	len_a;
	int	len_b;
	
	len_a = stacks->len_a;
	i = 0;
	j = 0;
	while (j < stacks->len_a && stacks->a[j] >= 0)
		j++;
	while (!is_sorted(stacks, j))
	{
		j = 0;
		while (j < len_a)
		{
			if (((stacks->a[0] >> i) & 1) == 1)
				rotate_a(stacks);
			else
				push_b(stacks);
			j++;
		}
		len_b = stacks->len_b;
		j = 0;
		while (j < len_b)
		{
			push_a(stacks);
			j++;
		}
		j = 0;
		while (j < stacks->len_a && stacks->a[j] >= 0)
			j++;
		
		i++;
	}
}


/*

	Renvoie un booleen indiquant si la liste est triee ou non
	triee     = true
	non triee = false

*/

bool	is_sorted(t_stacks *stacks, int first_neg)
{
	int	i;

	i = 1;
	while (i < stacks->len_a)
	{
		if (stacks->a[i - 1] > stacks->a[i])
			return (false);
		i++;
	}
	return (true);
}

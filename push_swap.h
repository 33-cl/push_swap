/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:58:22 by maeferre          #+#    #+#             */
/*   Updated: 2024/03/05 18:36:59 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	__PUSH_SWAP__H__
#define	__PUSH_SWAP__H__

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum
{
	false,
	true
}bool;

typedef	struct s_stacks
{
	int	*a;
	int	*b;
	int	i;
	int	len_a;
	int	len_b;
	int	len_total;
}t_stacks;

// Libft functions
int		ft_atoi(const char *str);
void	ft_swap(int *a, int *b);
char	**ft_split(char const *s, char c);
void	ft_sort_int_tab(int *tab, int size);
size_t	ft_strlen2d(char **tab);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

// Stack related functions
int		stack_len(int *stack);
void	display_stacks(t_stacks stacks);
bool	create_stacks(t_stacks *stacks, int argc, char **argv);
void	add_stack(int *stack, int *len_stack, int value);
void	remove_stack(int *stack, int *len_stack);
void	transform_stack(t_stacks *stacks);

// Parsing
bool	parsing(int	argc, char **argv);

// Subject functions
void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	swap_both(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	push_a(t_stacks *stacks);
void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	rotate_both(t_stacks *stacks);
void	reverse_rotate_a(t_stacks *stacks);
void	reverse_rotate_b(t_stacks *stacks);
void	reverse_rotate_both(t_stacks *stacks);

// Little sort functions
void	little_sort(t_stacks *stacks);

// Free functions
void	free_map(char **map);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:14:44 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/15 10:14:45 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

int	swap_check(t_list **list_a)
{
	int	i;

	if ((*list_a)->next->order - (*list_a)->order == 2)
		i = -1;
	if ((*list_a)->next->order - (*list_a)->order == 1)
		i = 2;
	return (i);
}

void	turn_choice(t_list **list_a, t_list **list_b, int i, int argc)
{
	if (i == 2)
	{
		if ((*list_a)->order > 2 && (ft_position_x(list_b, (*list_a)->order - 1)
				< ft_find_size(list_b) / 2 || (ft_lstlast(*list_a)->order
					== argc - 1 && ft_position_x(list_b, (*list_a)->order - 2)
					< ft_find_size(list_b) / 2)))
			rotate_b(list_b);
		else
			rev_rotate_b(list_b);
	}
	if (i == -1)
	{
		if (ft_position_x(list_b, (*list_a)->order + 1)
			< ft_find_size(list_b) / 2)
			rotate_b(list_b);
		else
			rev_rotate_b(list_b);
	}
	return ;
}

void	return_to_a_ps(t_list **list_a, t_list **list_b)
{
	push_a(list_a, list_b);
	swap(list_a, list_b);
}

void	return_to_a_pr(t_list **list_a, t_list **list_b)
{
	push_a(list_a, list_b);
	rotate_r2a(list_a, list_b);
}

void	return_to_a(t_list **list_a, t_list **list_b, int argc)
{
	int	i;

	i = 2;
	while (*list_b)
	{
		i = swap_check(list_a);
		if ((i == 2 && (*list_a)->order - ft_lstlast(*list_a)->order == 1))
			rev_rotate_a(list_a);
		else if ((*list_a)->order - (*list_b)->order >= -1
			&& (*list_a)->order - (*list_b)->order <= i)
			return_to_a_ps(list_a, list_b);
		else if (((*list_a)->order - (*list_b)->order > 2
				&& ft_lstlast(*list_a)->order == argc - 1)
			|| (*list_b)->order - ft_lstlast(*list_a)->order == 1)
			return_to_a_pr(list_a, list_b);
		else if ((*list_b)->next)
			turn_choice(list_a, list_b, i, argc);
	}
	while ((*list_a)->order != 1)
		rev_rotate_a(list_a);
	return ;
}

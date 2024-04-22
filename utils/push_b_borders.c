/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:41:27 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/13 14:41:29 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

void	push_b_borders(t_list **list_a, t_list **list_b, int argc, int div)
{
	int	original_div;
	int	a;
	int	b;
	int	*choice;

	original_div = find_div(argc);
	a = calculate_fraction(argc, 0, div);
	b = (argc - 1) / original_div;
	b = calculate_fraction(argc, b, div);
	if (div == 1)
		b = (argc - 1);
	if ((*list_a)->order > a && (*list_a)->order <= b
		&& (*list_a)->order <= argc - 4)
	{
		push_b(list_b, list_a);
		choice = choice_ra_rra(list_a, argc, div, original_div);
		if ((choice[0] == 1 || (choice[0] == 0 && choice[1] == 0))
			&& (*list_b)->next && ((original_div != 1 && (*list_b)->order
					> b - (b - a) / 2) | (original_div == 1 && (*list_b)->order
					< b - (b - a) / 2 && (*list_b)->next->order
					>= b - (b - a) / 2)))
			rotate_b(list_b);
		free (choice);
	}		
	return ;
}

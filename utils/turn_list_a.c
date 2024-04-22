/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_list_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:07:51 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/19 20:07:52 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

void	turn_list_a_utils(int *choice, t_list **list_a)
{
	int	i;

	i = 0;
	while (i < choice[1])
	{
		rev_rotate_a(list_a);
		i++;
	}
	return ;
}

void	turn_list_a(t_list **list_a, t_list **list_b, int argc, int div)
{
	int	*choice;
	int	original_div;
	int	i;

	original_div = find_div(argc);
	choice = choice_ra_rra(list_a, argc, div, original_div);
	if (original_div == 1 && ft_find_size(list_a) > 3)
		rotate_ps(list_a, list_b, argc, div);
	else if (choice[0] == 0)
	{
		i = 0;
		while (i < choice[1])
		{
			rotate_ps(list_a, list_b, argc, div);
			i++;
		}
	}
	else
		turn_list_a_utils(choice, list_a);
	free(choice);
	return ;
}

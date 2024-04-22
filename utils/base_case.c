/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:15:52 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/07 13:15:53 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	base_case(t_list **list_a, int min)
{
	t_list	*last;

	last = ft_lstlast(*list_a);
	if (check_order(*list_a) != 0)
	{
		if ((*list_a)->order - (*list_a)->next->order == 1)
			swap_a(list_a);
		else if ((*list_a)->next->order == min
			&& (*list_a)->order - last->order == 1)
			rotate_a(list_a);
		else if ((*list_a)->order - last->order == 1)
			rev_rotate_a(list_a);
		else
		{
			swap_a(list_a);
			rotate_a(list_a);
		}
	}
	return ;
}

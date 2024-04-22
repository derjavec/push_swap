/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:58:32 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/30 12:58:33 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_a(t_list **list_a)
{
	t_list	*temp;

	if (ft_find_size(list_a) <= 1)
		return ;
	temp = *list_a;
	*list_a = (*list_a)->next;
	temp->next = NULL;
	ft_lstadd_back(list_a, temp);
	write(1, "ra", 2);
	write(1, "\n", 1);
	return ;
}

void	rotate_b(t_list **list_b)
{
	t_list	*temp;

	if (ft_find_size(list_b) <= 1)
		return ;
	temp = *list_b;
	*list_b = (*list_b)->next;
	temp->next = NULL;
	ft_lstadd_back(list_b, temp);
	write(1, "rb", 2);
	write(1, "\n", 1);
	return ;
}

void	rotate_r(t_list **list_a, t_list **list_b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	if (ft_find_size(list_a) <= 1 || ft_find_size(list_b) <= 1)
		return ;
	temp_a = *list_a;
	*list_a = (*list_a)->next;
	temp_a->next = NULL;
	ft_lstadd_back(list_a, temp_a);
	temp_b = *list_b;
	*list_b = (*list_b)->next;
	temp_b->next = NULL;
	ft_lstadd_back(list_b, temp_b);
	write(1, "rr", 2);
	write(1, "\n", 1);
	return ;
}

void	rotate_ps(t_list **list_a, t_list **list_b, int argc, int div)
{
	int	a;
	int	b;
	int	original_div;

	original_div = find_div(argc);
	a = 0;
	a = calculate_fraction(argc, a, div);
	b = (argc - 1) / original_div;
	b = calculate_fraction(argc, b, div);
	if (div == 1)
		b = (argc - 1);
	if (*list_b && (*list_b)->next && ((original_div != 1 && (*list_b)->order
				> b - (b - a) / 2) || (original_div == 1 && (*list_b)->order < b
				- (b - a) / 2 && (*list_b)->next->order > b - (b - a) / 2)))
		rotate_r(list_a, list_b);
	else if ((*list_a)->order <= a || ((div == 1 && (*list_a)->order > b - 3)
			|| (div != 1 && (*list_a)->order > b)))
		rotate_a(list_a);
	return ;
}

void	rotate_r2a(t_list **list_a, t_list **list_b)
{
	if (*list_b && (*list_b)->next && ft_position_x
		(list_b, (*list_a)->order - 1) < ft_find_size(list_b) / 2)
		rotate_r(list_a, list_b);
	else
		rotate_a(list_a);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:30:14 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/30 12:30:18 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_a(t_list **list_a)
{
	t_list	*temp_1;
	t_list	*temp_2;

	if (ft_find_size(list_a) <= 1)
		return ;
	temp_1 = *list_a;
	temp_2 = (*list_a)->next;
	*list_a = (*list_a)->next->next;
	temp_1->next = NULL;
	temp_2->next = NULL;
	ft_lstadd_front(list_a, temp_1);
	ft_lstadd_front(list_a, temp_2);
	write(1, "sa", 2);
	write(1, "\n", 1);
	return ;
}

void	swap_b(t_list **list_b)
{
	t_list	*temp_1;
	t_list	*temp_2;

	if (ft_find_size(list_b) <= 1)
		return ;
	temp_1 = *list_b;
	temp_2 = (*list_b)->next;
	*list_b = (*list_b)->next->next;
	temp_1->next = NULL;
	temp_2->next = NULL;
	ft_lstadd_front(list_b, temp_1);
	ft_lstadd_front(list_b, temp_2);
	write(1, "sb", 2);
	write(1, "\n", 1);
	return ;
}

void	swap_s(t_list **list_a, t_list **list_b)
{
	t_list	*temp_a1;
	t_list	*temp_a2;
	t_list	*temp_b1;
	t_list	*temp_b2;

	if (ft_find_size(list_a) == 1 || ft_find_size(list_b) == 1)
		return ;
	temp_a1 = *list_a;
	temp_a2 = (*list_a)->next;
	*list_a = (*list_a)->next->next;
	temp_a1->next = NULL;
	temp_a2->next = NULL;
	ft_lstadd_front(list_a, temp_a1);
	ft_lstadd_front(list_a, temp_a2);
	temp_b1 = *list_b;
	temp_b2 = (*list_b)->next;
	*list_b = (*list_b)->next->next;
	temp_b1->next = NULL;
	temp_b2->next = NULL;
	ft_lstadd_front(list_b, temp_b1);
	ft_lstadd_front(list_b, temp_b2);
	write(1, "ss", 2);
	write(1, "\n", 1);
	return ;
}

void	swap(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	temp = *list_a;
	if (*list_b && (*list_b)->next && (*list_a)->order - (*list_b)->next->order
		< (*list_a)->order - (*list_b)->order && temp->order
		- temp->next->order == 1)
		swap_s(list_a, list_b);
	else if (temp->order - temp->next->order == 1)
		swap_a(list_a);
	return ;
}

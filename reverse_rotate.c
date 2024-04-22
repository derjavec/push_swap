/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:56:32 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/19 19:30:03 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	**rev_rotate_a(t_list **list_a)
{
	t_list		*temp;
	t_list		*prev;

	if (ft_find_size(list_a) <= 1)
		return (list_a);
	temp = *list_a;
	prev = NULL;
	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	temp->next = *list_a;
	prev->next = NULL;
	*list_a = temp;
	write(1, "rra", 3);
	write(1, "\n", 1);
	return (list_a);
}

void	rev_rotate_b(t_list **list_b)
{
	t_list	*temp;
	t_list	*prev;

	if (ft_find_size(list_b) <= 1)
		return ;
	temp = *list_b;
	prev = NULL;
	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	temp->next = *list_b;
	prev->next = NULL;
	*list_b = temp;
	write(1, "rrb", 3);
	write(1, "\n", 1);
	return ;
}

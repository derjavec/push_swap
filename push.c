/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:44:21 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/30 12:44:22 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_a(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	if (*list_b == NULL)
		return ;
	temp = *list_b;
	*list_b = (*list_b)->next;
	ft_lstadd_front(list_a, temp);
	write(1, "pa", 2);
	write(1, "\n", 1);
	return ;
}

void	push_b(t_list **list_b, t_list **list_a)
{
	t_list	*temp;

	if (*list_a == NULL)
		return ;
	temp = *list_a;
	*list_a = (*list_a)->next;
	ft_lstadd_front(list_b, temp);
	write(1, "pb", 2);
	write(1, "\n", 1);
	return ;
}

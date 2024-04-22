/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:58:32 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/30 12:58:33 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	rotate_a_bonus(t_list **list_a)
{
	t_list	*temp;

	if (ft_find_size(list_a) <= 1)
		return ;
	temp = *list_a;
	*list_a = (*list_a)->next;
	temp->next = NULL;
	ft_lstadd_back(list_a, temp);
	return ;
}

void	rotate_b_bonus(t_list **list_b)
{
	t_list	*temp;

	if (ft_find_size(list_b) <= 1)
		return ;
	temp = *list_b;
	*list_b = (*list_b)->next;
	temp->next = NULL;
	ft_lstadd_back(list_b, temp);
	return ;
}

void	rotate_r_bonus(t_list **list_a, t_list **list_b)
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
	return ;
}

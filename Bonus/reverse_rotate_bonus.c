/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:56:32 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/19 19:30:03 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	rev_rotate_a_bonus(t_list **list_a)
{
	t_list		*temp;
	t_list		*prev;

	if (ft_find_size(list_a) <= 1)
		return ;
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
	return ;
}

void	rev_rotate_b_bonus(t_list **list_b)
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
	return ;
}

void	rev_rotate_r_bonus_utils(t_list **list_b)
{
	t_list	*temp_b;
	t_list	*prev_b;

	temp_b = *list_b;
	prev_b = NULL;
	while (temp_b->next)
	{
		prev_b = temp_b;
		temp_b = temp_b->next;
	}
	temp_b->next = *list_b;
	prev_b->next = NULL;
	*list_b = temp_b;
	return ;
}

void	rev_rotate_r_bonus(t_list **list_a, t_list **list_b)
{
	t_list	*temp_a;
	t_list	*prev_a;

	if (ft_find_size(list_a) <= 1 || ft_find_size(list_b) <= 1)
		return ;
	temp_a = *list_a;
	prev_a = NULL;
	while (temp_a->next)
	{
		prev_a = temp_a;
		temp_a = temp_a->next;
	}
	temp_a->next = *list_a;
	prev_a->next = NULL;
	rev_rotate_r_bonus_utils(list_b);
	return ;
}

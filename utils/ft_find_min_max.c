/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:53:24 by derjavec          #+#    #+#             */
/*   Updated: 2024/02/06 13:53:26 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

int	ft_find_rest(int argc)
{
	int	rest;

	if ((argc -1) % 3 == 0)
		rest = 0;
	else
		rest = 1;
	return (rest);
}

int	ft_find_size(t_list	**lst)
{
	t_list	*temp;
	int		i;

	temp = *lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	ft_find_min(t_list	**lst)
{
	t_list	*temp;
	int		min;

	temp = *lst;
	min = temp->order;
	while (temp->next)
	{
		if (temp->next->order < min)
			min = temp->next->order;
		temp = temp->next;
	}	
	return (min);
}

int	ft_find_max(t_list	**lst)
{
	t_list	*temp;
	int		max;

	temp = *lst;
	max = temp->order;
	while (temp->next)
	{
		if (temp->next->order > max)
			max = temp->next->order;
		temp = temp->next;
	}
	return (max);
}

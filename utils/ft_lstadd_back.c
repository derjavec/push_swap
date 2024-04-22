/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:27:22 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/18 11:27:23 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (lst && new)
	{
		current = *lst;
		if (current == NULL)
		{
			*lst = new;
			return ;
		}
		while (current ->next != NULL)
		{
			current = current ->next;
		}
		current ->next = new;
	}
	return ;
}

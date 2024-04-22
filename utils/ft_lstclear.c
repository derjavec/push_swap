/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:08:49 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/18 11:08:51 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL)
		return ;
	current = *lst;
	while (current)
	{
		next = current ->next;
		free (current);
		current = next;
	}
	*lst = NULL;
}

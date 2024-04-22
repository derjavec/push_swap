/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:00:45 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/31 16:00:46 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	ft_lstdellast(t_list **lst)
{
	t_list	*temp;
	t_list	*prev;

	if (lst == NULL || *lst == NULL)
		return ;
	temp = *lst;
	prev = NULL;
	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	if (prev)
		prev->next = NULL;
	else
		*lst = NULL;
}

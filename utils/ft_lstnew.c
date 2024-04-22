/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:22:07 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/18 10:22:09 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

t_list	*ft_lstnew(int content, int order)
{
	t_list	*new;

	new = malloc (sizeof (t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->order = order;
	new->next = NULL;
	return (new);
}

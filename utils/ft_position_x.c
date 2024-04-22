/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:00:20 by derjavec          #+#    #+#             */
/*   Updated: 2024/02/02 15:00:22 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

int	ft_position_x(t_list **lst, int x)
{
	t_list	*temp;
	int		count;

	temp = *lst;
	count = 0;
	while (temp)
	{
		if (temp->order == x)
			return (count + 1);
		count++;
		temp = temp->next;
	}
	return (0);
}

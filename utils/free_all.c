/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:56:59 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/15 13:57:02 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

void	free_all(t_list **list_a, int *num_a, int *order)
{
	free(num_a);
	free(order);
	ft_lstclear(list_a);
	free(list_a);
	return ;
}

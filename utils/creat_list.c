/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:11:47 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/15 10:11:49 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

t_list	**creat_list(int *num, int *num_ordered, int size)
{
	t_list	**list_a;
	t_list	*node;
	int		i;

	list_a = malloc((size) * sizeof (t_list *));
	if (list_a == NULL)
	{
		free(num);
		free(num_ordered);
		error();
	}
	i = 0;
	*list_a = NULL;
	while (i < size)
	{
		node = ft_lstnew(num[i], num_ordered[i]);
		if (node == NULL)
		{
			free_all(list_a, num, num_ordered);
			error();
		}	
		ft_lstadd_back(list_a, node);
		i++;
	}
	return (list_a);
}

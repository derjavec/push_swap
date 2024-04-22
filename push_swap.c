/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:25:58 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/29 14:26:00 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	push_until_base_case(t_list **list_a, t_list **list_b,
		int argc, int div)
{
	while (ft_find_size(list_a) > 3)
	{	
		push_b_borders(list_a, list_b, argc, div);
		if (div > 1 && ft_find_size(list_b) == break_point(argc, div))
			div = div - 1;
		if (ft_find_size(list_a) > 3)
			turn_list_a(list_a, list_b, argc, div);
	}
	return ;
}

static void	too_much_args(t_list **list_a, t_list **list_b, int *num_a, int *order)
{
	free(list_b);
	free_all(list_a, num_a, order);
	error();
}

void	push_swap(t_list **list_a, int *num_a, int *order, int argc)
{
	t_list	**list_b;
	int		min;
	int		div;

	list_b = malloc((argc - 1) * sizeof (t_list *));
	if (list_b == NULL)
	{
		free_all(list_a, num_a, order);
		error();
	}
	*list_b = NULL;
	div = find_div(argc);
	if (div == -1)
		too_much_args(list_a, list_b, num_a, order);
	while (check_order(*list_a) != 0)
	{
		push_until_base_case(list_a, list_b, argc, div);
		min = ft_find_min(list_a);
		base_case(list_a, min);
	}
	return_to_a(list_a, list_b, argc);
	free(list_b);
	return ;
}

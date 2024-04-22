/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_ra_rra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:50:13 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/13 14:50:15 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

static int	ft_count_r(int argc, int div, int original_div, t_list *temp)
{
	int		a;
	int		b;
	int		count_r;

	count_r = 0;
	a = 0;
	a = calculate_fraction(argc, a, div);
	b = (argc - 1) / original_div;
	b = calculate_fraction(argc, b, div);
	if (div == 1)
		b = (argc - 1);
	while (temp)
	{
		if ((temp->order > a && temp->order <= b
				&& temp->order <= (argc - 1) - 3))
			break ;
		count_r++;
		temp = temp->next;
	}
	return (count_r);
}

static t_list	*ft_count_rr_utils(t_list *temp)
{
	t_list	*last_node;

	last_node = NULL;
	while (temp)
	{
		if (last_node)
			temp->prev = last_node;
		last_node = temp;
		temp = temp->next;
	}
	return (last_node);
}

static int	ft_count_rr(int argc, int div, int original_div, t_list *temp)
{
	int		a;
	int		b;
	int		count_rr;

	count_rr = 0;
	a = 0;
	a = calculate_fraction(argc, a, div);
	b = (argc - 1) / original_div;
	b = calculate_fraction(argc, b, div);
	if (div == 1)
		b = (argc - 1);
	temp = ft_count_rr_utils(temp);
	while (temp)
	{
		count_rr++;
		if ((temp->order > a && temp->order <= b
				&& temp->order <= (argc - 1) - 3))
			break ;
		temp = temp->prev;
	}
	return (count_rr);
}

int	*choice_ra_rra(t_list **list_a, int argc, int div, int original_div)
{
	int		count_r;
	int		count_rr;
	int		*result;
	t_list	*temp;

	result = malloc (2 * sizeof(int));
	temp = *list_a;
	count_r = ft_count_r(argc, div, original_div, temp);
	temp = *list_a;
	count_rr = ft_count_rr(argc, div, original_div, temp);
	if (count_r < count_rr)
	{
		result[0] = 0;
		result[1] = count_r;
		return (result);
	}
	else
	{
		result[0] = 1;
		result[1] = count_rr;
		return (result);
	}
}

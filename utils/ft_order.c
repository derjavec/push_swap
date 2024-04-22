/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:22:42 by derjavec          #+#    #+#             */
/*   Updated: 2024/02/05 15:22:44 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

int	*ft_qsort(int *num, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (num[j] > num[j + 1])
			{
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (num);
}

int	find_median(int num[], int size)
{
	int	mid1;
	int	mid2;

	if (size % 2 == 0)
	{
		mid1 = num[size / 2 - 1];
		mid2 = num[size / 2];
		return ((mid1 + mid2) / 2);
	}
	else
		return (num[size / 2]);
}

int	*checkargs_returnordered(int *num_a, int *order, int argc)
{
	int		i;
	int		j;
	int		*temp;

	temp = malloc((argc - 1) * sizeof(int));
	if (temp == NULL)
		error();
	i = 0;
	while (i < argc - 1)
	{
		j = 1;
		while (j + i < argc - 1)
		{
			if (num_a[i] == num_a[i + j])
			{
				free(num_a);
				free(order);
				error();
			}
			j++;
		}
		temp[i] = num_a[i];
		i++;
	}
	return (ft_qsort(temp, argc - 1));
}

int	*assign_order(int *num_a, int argc)
{
	int	i;
	int	j;
	int	*num_ordered;
	int	*order;

	order = (int *)malloc((argc - 1) * sizeof(int));
	if (order == NULL)
	{
		free(num_a);
		error();
	}
	num_ordered = checkargs_returnordered(num_a, order, argc);
	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (num_a[i] == num_ordered[j])
				order[i] = j + 1;
			j++;
		}
		i++;
	}
	return (free(num_ordered), order);
}

int	check_order(t_list	*list_a)
{
	t_list	*temp;

	temp = list_a;
	while (temp->next)
	{
		if (temp->next->order != temp->order + 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

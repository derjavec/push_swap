/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:34:33 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/13 14:34:34 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

int	check_borders(int argc, int div, int result)
{
	int	a;
	int	b;
	int	original_div;

	original_div = find_div(argc);
	a = 0;
	a = calculate_fraction(argc, a, div);
	b = (argc - 1) / original_div;
	b = calculate_fraction(argc, b, div);
	if (div == 1)
		b = (argc - 1);
	if (b == argc - 1)
		result = (argc - 1) - 3;
	return (result);
}

int	break_point(int argc, int div)
{
	int	original_div;
	int	result;
	int	i;

	original_div = find_div(argc);
	result = (argc -1) / original_div;
	i = div;
	while (i < original_div)
	{
		result += (argc -1) / original_div;
		i++;
	}
	result = check_borders(argc, div, result);
	return (result);
}

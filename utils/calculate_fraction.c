/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fraction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:34:59 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/13 14:35:01 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

int	calculate_fraction(int argc, int init, int div)
{
	int	result;
	int	original_div;
	int	i;

	i = div;
	original_div = find_div(argc);
	result = init;
	while (i < original_div)
	{
		result = result + (argc - 1) / original_div;
		i++;
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:39:37 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/13 14:39:38 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

static int	find_div_max(int argc)
{
	int	div;

	if (argc < 1050)
		div = 7 + (argc - 1 - 550) / 100;
	else if (argc < 10050)
		div = 12 + (argc - 1 - 1050) / 200;
	else if (argc < 100050)
		div = 22 + (argc - 1 - 10050) / 300;
	else
		div = -1;
	return (div);
}

int	find_div(int argc)
{
	int	div;

	if (argc <= 35)
		div = 1;
	else if (argc <= 75)
		div = 2;
	else if (argc <= 125)
		div = 3;
	else if (argc <= 175)
		div = 4;
	else if (argc < 250)
		div = 5;
	else if (argc < 350)
		div = 6;
	else if (argc < 450)
		div = 7;
	else if (argc < 550)
		div = 9;
	else if (argc < 1050)
		find_div_max(argc);
	return (div);
}

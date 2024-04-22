/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:50:36 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/21 17:50:42 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	free_all_bonus(char **instructions, t_list **list_a,
		int *num_a, int *order)
{
	int	i;

	i = 0;
	while (instructions[i])
		free(instructions[i++]);
	free (instructions);
	free_all(list_a, num_a, order);
	return ;
}

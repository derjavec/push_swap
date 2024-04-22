/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:54:28 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/02 13:54:30 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	check_order_write(t_list	**list_a, t_list **list_b)
{
	if (list_b && *list_b != NULL)
		write(1, "KO\n", 3);
	else if (check_order(*list_a) == 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

void	checker_utils(t_list	**list_a, t_list **list_b
		, char **instructions, int i)
{
	if (*list_a && ft_strncmp(instructions[i], "sa\n", 3) == 0)
		swap_a_bonus(list_a);
	else if (ft_strncmp(instructions[i], "sb\n", 3) == 0)
		swap_b_bonus(list_b);
	else if (ft_strncmp(instructions[i], "ss\n", 3) == 0)
		swap_s_bonus(list_a, list_b);
	else if (ft_strncmp(instructions[i], "ra\n", 3) == 0)
		rotate_a_bonus(list_a);
	else if (ft_strncmp(instructions[i], "rb\n", 3) == 0)
		rotate_b_bonus(list_b);
	else if (ft_strncmp(instructions[i], "rr\n", 3) == 0)
		rotate_r_bonus(list_a, list_b);
	else if (ft_strncmp(instructions[i], "rra\n", 3) == 0)
		rev_rotate_a_bonus(list_a);
	else if (ft_strncmp(instructions[i], "rrb\n", 3) == 0)
		rev_rotate_b_bonus(list_b);
	else if (ft_strncmp(instructions[i], "rrr\n", 3) == 0)
		rev_rotate_r_bonus(list_a, list_b);
	else if (ft_strncmp(instructions[i], "pb\n", 3) == 0)
		push_b_bonus(list_b, list_a);
	else if (ft_strncmp(instructions[i], "pa\n", 3) == 0)
		push_a_bonus(list_a, list_b);
}

void	checker(t_list	**list_a, t_list **list_b, char **instructions)
{
	int	i;

	i = 0;
	while (instructions[i])
	{
		checker_utils(list_a, list_b, instructions, i);
		i++;
	}
	i = 0;
	check_order_write(list_a, list_b);
	return ;
}

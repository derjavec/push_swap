/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:30:42 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/18 13:30:46 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "gnl/get_next_line.h"

void	push_swap(t_list **list_a, int *num_a, int *order, int argc);
int		ft_strncmp(const char *first, const char *second, size_t length);
char	**take_instructions(int*num_a, int*order, t_list **list_a, int argc);
void	free_all_bonus(char **instructions, t_list **list_a,
			int *num_a, int *order);
void	swap_a_bonus(t_list **list_a);
void	swap_b_bonus(t_list **list_b);
void	swap_s_bonus(t_list **list_a, t_list **list_b);
void	rotate_a_bonus(t_list **list_a);
void	rotate_b_bonus(t_list **list_b);
void	rotate_r_bonus(t_list **list_a, t_list **list_b);
void	rev_rotate_a_bonus(t_list **list_a);
void	rev_rotate_b_bonus(t_list **list_b);
void	rev_rotate_r_bonus(t_list **list_a, t_list **list_b);
void	push_a_bonus(t_list **list_a, t_list **list_b);
void	push_b_bonus(t_list **list_b, t_list **list_a);
void	checker(t_list	**list_a, t_list **list_b, char **instructions);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:26:26 by derjavec          #+#    #+#             */
/*   Updated: 2024/01/29 14:26:28 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				order;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

size_t	ft_strlen( const char *c);
int		ft_atoi(const char *str, int **num_a);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char *s, char c, char *special_c);
char	*ft_copylettres(char **tableau, int mot, char *s, char **ce);
void	error(void);
int		**parsing(char *argv[]);
int		*assign_order(int *num_a, int argc);
int		check_order(t_list	*list_a);
int		ft_position_x(t_list **lst, int min);
int		ft_find_size(t_list	**lst);
int		ft_find_max(t_list	**lst);
int		ft_find_min(t_list	**lst);
int		find_div(int argc);
t_list	*ft_lstnew(int content, int order);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstdellast(t_list **lst);
t_list	**creat_list(int *num, int *num_ordered, int size);
void	swap_a(t_list **list_a);
void	swap_b(t_list **list_b);
void	swap(t_list **list_a, t_list **list_b);
void	push_a(t_list **list_a, t_list **list_b);
void	push_b(t_list **list_b, t_list **list_a);
void	rotate_ps(t_list **list_a, t_list **list_b, int argc, int div);
void	rotate_r2a(t_list **list_a, t_list **list_b);
void	rotate_a(t_list **list_a);
void	rotate_b(t_list **list_b);
t_list	**rev_rotate_a(t_list **list_a);
void	rev_rotate_b(t_list **list_b);
void	base_case(t_list **list_a, int min);
int		break_point(int argc, int div);
int		*choice_ra_rra(t_list **list_a, int argc, int div, int original_div);
int		calculate_fraction(int argc, int init, int div);
void	turn_list_a(t_list **list_a, t_list **list_b, int argc, int div);
void	push_b_borders(t_list **list_a, t_list **list_b, int argc, int div);
void	return_to_a(t_list **list_a, t_list **list_b, int argc);
void	free_all(t_list **list_a, int *num_a, int *order);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:44:25 by derjavec          #+#    #+#             */
/*   Updated: 2023/11/09 08:44:27 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct f_list
{
	char			*content;
	struct f_list	*next;
}	t_lst;

char	*get_next_line(int fd);
size_t	ft_strlen0_findline1(const char *c, int choice);
size_t	ft_strlen( const char *c);
t_lst	*ft_lstnew_lstaddback(t_lst **list, char *content);
void	ft_lstclear_gnl(t_lst **lst, void (*del)(void *));
int		ft_lstlen(t_lst *list);
int		ft_lstfind_line(t_lst *list);
void	*ft_memcpy(void *d, const void *s, size_t n);

#endif

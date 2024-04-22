/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:45:18 by derjavec          #+#    #+#             */
/*   Updated: 2023/11/09 08:45:20 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen0_findline1(const char *c, int choice)
{
	int	i;

	i = 0;
	if (choice == 0)
	{
		while (c[i])
			i++;
	}
	if (choice == 1)
	{
		while (c [i] && c[i] != '\n')
			i++;
		if (c[i] == '\n')
			i++;
	}
	else if (choice == 2)
	{
		while (c[i])
		{
			if (c[i++] == '\n')
				return (1);
		}
		return (0);
	}
	return (i);
}

t_lst	*ft_lstnew_lstaddback(t_lst **list, char *content)
{
	t_lst	*new;
	t_lst	*current;

	new = malloc (sizeof (t_lst));
	if (new == NULL)
		return (ft_lstclear_gnl(list, free), NULL);
	new->content = content;
	new->next = NULL;
	if (*list == NULL)
	{
		*list = new;
		return (*list);
	}
	current = *list;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (*list);
}	

int	ft_lstlen(t_lst *list)
{
	int		i;
	int		size;
	t_lst	*temp;

	if (list == NULL)
		return (0);
	i = 0;
	size = 0;
	temp = list;
	while (temp)
	{
		if (temp->content[i] == '\n')
			return (size + 1);
		if (temp->content[i + 1] == '\0')
		{
			temp = temp->next;
			i = 0;
		}
		else
			i++;
		size++;
	}
	return (size);
}

int	ft_lstfind_line(t_lst *list)
{
	int		i;
	t_lst	*temp;

	if (list == NULL)
		return (0);
	i = 0;
	temp = list;
	while (temp)
	{
		if (temp->content[i] == '\n' )
			return (1);
		if (temp->content[i + 1] == '\0')
		{
			temp = temp->next;
			i = 0;
		}
		else
			i++;
	}
	return (0);
}

void	ft_lstclear_gnl(t_lst **lst, void (*del)(void *))
{
	t_lst	*current;
	t_lst	*next;

	if (lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current)
	{
		next = current ->next;
		if (current->content)
			del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

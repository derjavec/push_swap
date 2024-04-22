/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:33:57 by derjavec          #+#    #+#             */
/*   Updated: 2024/02/20 13:33:59 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ps;

	ps = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		ps[i] = '\0';
		i++;
	}
}

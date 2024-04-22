/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:35:52 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/02 14:00:39 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static char	*erase_spaces(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (str + i);
}

static const char	*erase_sign(const char *str, int **num_a)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
		{
			free (num_a[1]);
			free (num_a);
			error();
		}
		i++;
	}
	if (str[0] == '-' || str[0] == '+')
		return (str + 1);
	else
		return (str);
}

static int	check_sign(const char *str, int **num_a)
{
	int	sign;

	sign = 1;
	if (str[0] == '-')
		sign = -1;
	if ((str[0] == '-' || str[0] == '+')
		&& (str[1] == '-' || str[1] == '+' || str[1] == '\0'))
	{
		free (num_a[1]);
		free (num_a);
		error();
	}
	return (sign);
}

static int	ft_atoi_utils(const char *str, int **num_a, int sign)
{
	int		i;
	long	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			c = c * 10 + str[i] - 48;
			if (sign * c > INT_MAX || sign * c < INT_MIN)
			{
				free (num_a[1]);
				free(num_a);
				error();
			}
		}
		else
			break ;
		i++;
	}
	return (c);
}

int	ft_atoi(const char *str, int **num_a)
{
	long	c;
	int		sign;

	str = erase_spaces((char *) str);
	sign = check_sign(str, num_a);
	str = erase_sign(str, num_a);
	if (str[0] == '\0')
	{
		free(num_a[1]);
		free(num_a);
		error();
	}
	c = ft_atoi_utils(str, num_a, sign);
	return ((int)c * sign);
}

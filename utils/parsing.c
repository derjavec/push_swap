/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:03:51 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/02 08:43:02 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void	str_to_int(char *argv[], int **num_a)
{
	char	**str_a;
	int		i;

	str_a = ft_split(argv[1], ' ', "");
	if (str_a == NULL)
	{
		free(num_a[1]);
		error();
	}
	i = 0;
	while (str_a[i])
	{
		num_a[1][i] = ft_atoi(str_a[i], num_a);
		i++;
	}
	i = 0;
	while (str_a[i])
		free(str_a[i++]);
	free (str_a);
	return ;
}

static int	check_parsing(char *argv[])
{
	int	i;
	int	size;

	i = 0;
	size = 1;
	while (argv[1][i + 1])
	{
		if ((argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13))
			&& argv[1][i + 1] && argv[1][i + 1] != 32
			&& (argv[1][i] < 9 || argv[1][i] > 13))
			size++;
		i++;
	}
	return (size);
}

int	**parsing(char *argv[])
{
	int	size;
	int	**num_a;

	size = check_parsing(argv);
	num_a = NULL;
	if (size != 1)
	{
		num_a = malloc(2 * sizeof(int *));
		if (num_a == NULL)
			error();
		num_a[0] = malloc(sizeof(int));
		num_a[1] = malloc((size) * sizeof(int));
		if (num_a[0] == NULL || num_a[1] == NULL)
		{
			if (num_a[0])
				free(num_a[0]);
			if (num_a[1])
				free(num_a[1]);
			free(num_a);
			error();
		}
		num_a[0][0] = size;
		str_to_int(argv, num_a);
	}
	return (num_a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:43:11 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/18 13:43:12 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bonus/checker.h"

static int	**args_to_int( int argc, char *argv[], int **num_a)
{
	int	i;

	num_a = malloc (2 * sizeof(int *));
	if (num_a == NULL)
		error();
	num_a[0] = NULL;
	num_a[1] = malloc((argc - 1) * sizeof(int));
	if (num_a[1] == NULL)
	{
		free(num_a);
		error();
	}
	i = 0;
	while (argv[i + 1])
	{	
		num_a[1][i] = ft_atoi(argv[i + 1], num_a);
		i++;
	}
	return (num_a);
}

static void	run_ps(int **num_a, int size)
{
	int		*order;
	t_list	**list_a;

	order = assign_order(num_a[1], size + 1);
	list_a = creat_list(num_a[1], order, size);
	push_swap(list_a, num_a[1], order, size + 1);
	free_all(list_a, num_a[1], order);
	if (num_a[0])
		free(num_a[0]);
	free(num_a);
	return ;
}

int	main(int argc, char *argv[])
{
	int		size;
	int		**num_a;

	num_a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		num_a = parsing(argv);
		if (num_a)
			size = num_a[0][0];
	}
	if (num_a == NULL)
	{
		num_a = args_to_int(argc, argv, num_a);
		size = argc - 1;
	}
	run_ps(num_a, size);
	return (0);
}

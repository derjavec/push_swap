/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:25:20 by derjavec          #+#    #+#             */
/*   Updated: 2024/03/21 15:25:21 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

char	**ft_remalloc(char **instructions, int size, int i)
{
	char	**new_instructions;
	int		j;

	if (i >= size)
	{
		size = size * 2;
		new_instructions = malloc(size * sizeof(char *));
		if (new_instructions == NULL)
			free(instructions);
		j = 0;
		while (j < i)
		{
			new_instructions[j] = instructions[j];
			j++;
		}
		free(instructions);
		return (new_instructions);
	}
	return (instructions);
}

int	check_instructions(char	*line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0
		||ft_strncmp(line, "sb\n", 3) == 0
		||ft_strncmp(line, "ss\n", 3) == 0
		||ft_strncmp(line, "ra\n", 3) == 0
		||ft_strncmp(line, "rb\n", 3) == 0
		||ft_strncmp(line, "rr\n", 3) == 0
		||ft_strncmp(line, "rra\n", 3) == 0
		||ft_strncmp(line, "rrb\n", 3) == 0
		||ft_strncmp(line, "rrr\n", 3) == 0
		||ft_strncmp(line, "pb\n", 3) == 0
		||ft_strncmp(line, "pa\n", 3) == 0)
		return (0);
	else
		return (1);
}

char	**take_instructions_utils(int size, t_list **list_a,
			int *num_a, int *order)
{
	char	**instructions;

	instructions = malloc(size * sizeof(char *));
	if (instructions == NULL)
	{
		free_all(list_a, num_a, order);
		error();
	}
	return (instructions);
}

void	error_case(t_list **list_a, int *num_a, int *order)
{
	free_all(list_a, num_a, order);
	error();
}

char	**take_instructions(int*num_a, int*order, t_list **list_a, int argc)
{
	int		i;
	char	**instructions;	
	char	*line;
	int		size;

	size = (argc - 1) * 10;
	instructions = take_instructions_utils(size, list_a, num_a, order);
	i = 0;
	bzero(instructions, size);
	while (1)
	{
		instructions = ft_remalloc(instructions, size, i);
		if (instructions == NULL)
			error_case(list_a, num_a, order);
		line = get_next_line(0);
		if (line && check_instructions(line) == 0)
			instructions[i++] = line;
		else if (line == NULL)
			return (instructions);
		else
			error_case(list_a, num_a, order);
	}
}

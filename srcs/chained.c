/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:09:25 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/23 14:18:07 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	add_node(t_collect *head, int row, int col, t_game *game)
{
	t_collect	*new_node;
	t_collect	*current;

	new_node = (t_collect *)malloc(sizeof(t_collect));
	if (!new_node)
		return (free_collect(game->collect));
	new_node->loc = (t_point){.row = row, .col = col};
	new_node->visited = 0;
	new_node->next = NULL;
	if (head == NULL)
	{
		game->collect = new_node;
	}
	else
	{
		current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

void	copy_collect(t_collect *head, t_game *game)
{
	while (head != NULL)
	{
		add_node(game->collect, head->loc.row, head->loc.col, game);
		head = head->next;
	}
}

void	set_visited(t_collect *head, int row, int col)
{
	while (head != NULL)
	{
		if (head->loc.row == row && head->loc.col == col)
		{
			head->visited = 1;
			return ;
		}
		head = head->next;
	}
}

int	check_visited(t_collect *head)
{
	while (head != NULL)
	{
		if (head->visited == 0)
			return (1);
		head = head->next;
	}
	return (0);
}

void	free_collect(t_collect *head)
{
	t_collect	*current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
		current = NULL;
	}
}

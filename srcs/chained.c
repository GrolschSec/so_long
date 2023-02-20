/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:09:25 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/20 20:23:24 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	add_node(t_collect *head, int row, int col, int visited) 
{
    t_collect *new_node;
	t_collect *current;
	
	new_node = malloc(sizeof(t_collect));
    new_node->loc = (t_point){ .row = row, .col = col };
	new_node->visited = visited;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    }
	else
	{
		current = head;
		while (current->next != NULL)
			current = current->next;
        current->next = new_node;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 03:17:14 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/12/08 03:48:07 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_pos	begin_pos(char **map)
{
	
	t_pos	res;

	res.y = 0;
	res.x = 0;
	while(map[res.y])
	{
		while (map[res.y][res.x])
		{
			if (map[res.y][res.x] == 'P')

				return (res);
			res.x++;
		}
		res.y++;
	}
	return (res)
}
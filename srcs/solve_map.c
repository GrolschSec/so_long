/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 04:36:18 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/11/24 06:16:37 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_cep	count_cep(char **map)
{
	int		i;
	int		j;
	t_cep	counter;

	i = 1;
	ft_memset(&counter, 0, sizeof(t_cep));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			counter = collectible(map[i][j], counter);
			j++;
		}
		i++;
	}
	return (counter);
}

int	solve_map(char **map, t_cep counter)
{
	return (0);
}

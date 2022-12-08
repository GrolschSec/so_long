/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 04:36:18 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/12/08 03:57:54 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_cep(char **map)
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
	if (counter.c >= 1 && counter.p == 1 && counter.e == 1)
		return (counter.c);
	return (-1);
}

int	**make_tab(int c)
{
	int	**tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int *) * c);
	if (!tab)
		return (NULL);
	while (i < c)
	{
		tab[i] = malloc(sizeof(int) * 2);
		if (!tab[i])
			return (free_tab_int(tab), NULL);
		tab[i][0] = 0;
		tab[i][1] = 0;
	}
	return (tab);
}

void	free_tab_int(int **tab, int c)
{
	int	i;

	i = 0;
	while (i < c)
		free(tab[i++]);
	return (free(tab));
}

int	solve(int collectible, char **map)
{
	int 	**tab;
	int 	res;

	tab = make_tab(collectible);
	if (!tab)
		return (free_tab_int(tab, collectible), -1);
	res = solve_map(map, tab, collectible, begin_pos(map));
	return (free_tab_int(tab, collectible), res);
}

int	solve_map(char **map, int **tab, int c, t_pos pos)
{
	int	count;

	
	if (map[pos.y][pos.x] == 'E')
		return (0);
	else if (map[pos.y][pos.x] == '1')
		return (-1);
	else if (map[pos.y][pos.x] == 'C')
		add_pos_c(pos);
	left = direction(pos);
	up = direction(pos);
	bottom = direction(pos);
	right = direction(pos);
	if (left == 0 || right == 0 || up == 0 || bottom == 0)
		return (0);
	return (-1);
}

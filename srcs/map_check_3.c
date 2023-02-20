/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:55 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/20 14:05:04 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_map_objects(char **map, char c)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == c)
				count++;
		i++;
	}
	return (count);
}

int	verify_map_objects(char **map)
{
	int	p;
	int	e;
	int	c;

	p = count_map_objects(map, 'P');
	if (p != 1)
		return (1);
	e = count_map_objects(map, 'E');
	if (e != 1)
		return (1);
	c = count_map_objects(map, 'C');
	if (c < 1)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:37:17 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/10/12 17:27:17 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clean_malloc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	filename_checker(char *filename)
{
	char	**filename_splited;

	filename_splited = ft_split(filename, '.');
	if (!filename_splited[1])
		return (clean_malloc(filename_splited), 2);
	if (ft_strncmp((const char *)filename_splited[1], "ber", 3) != 0)
		return (clean_malloc(filename_splited), 2);
	return (clean_malloc(filename_splited), 0);
}

int	map_checker(int fd)
{	
	if (fd < 0)
		return (close(fd), 3);
	return (0);
}

int	error(int n)
{
	if (n == 1)
		return (ft_putstr_fd("Usage: ./so_long <map.ber>", 1), 1);
	else if (n == 2)
		return (ft_putstr_fd("Error, map file need to be a '.ber'.", 1), 2);
	else if (n == 3)
		return (ft_putstr_fd("Error, map file is not conform.", 1), 3);
	return (ft_putstr_fd("Error, map file is not conform.", 1), -1);
	
}

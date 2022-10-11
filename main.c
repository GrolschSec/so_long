/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:32:45 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/10/11 22:29:30 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker(int fc)
{	
	//first check if the fd is greater than if not error
	//then parse the file and check that is it conform
	// if not conform call the error function
	return ;
}

void	so_long(int fd)
{
	return ; 
}

int	main(int argc, char **argv)
{
	int	fd;
	
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long <map.ber>", 1);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (map_checker(fd) != 0)
		return (-1);
	so_long(fd);
	return (0);
}

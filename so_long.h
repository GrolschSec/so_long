/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:32:48 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/10/12 13:38:02 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "ft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		error(int n);
int		filename_checker(char *filename);
int		map_checker(int fd);
void	clean_malloc(char **tab);
void	so_long(int fd);
#endif

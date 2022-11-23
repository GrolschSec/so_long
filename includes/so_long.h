/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:32:48 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/10/12 19:20:40 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../ft/libft.h"
# include "../gnl/get_next_line.h"


int		filename_checker(char *filename);
char	**map_checker(int fd);
char	**load_map(int fd);
void	clean_malloc(char **tab);
#endif

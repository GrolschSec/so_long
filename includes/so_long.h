/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:24:11 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/20 13:00:53 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../ft/libft.h"
# include "../gnl/get_next_line.h"

// map_check_1.c
int		filename_check(char *filename);
char	**load_map(char	*filename);
void	ft_free_tab(char **tab);
int		validate_map(char **map);
// map_check_2.c
int		is_rectangular(char **map);
int		verify_map_chars(char **map);
int		verify_map_walls(char **map);
char	*map_to_str(int fd);
char	**read_map(int fd);
// map_check_3.c
int		count_map_objects(char **map, char c);
int		verify_map_objects(char **map);
#endif

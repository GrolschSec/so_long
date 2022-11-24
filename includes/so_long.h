/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:32:48 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/11/24 06:10:34 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../ft/libft.h"
# include "../gnl/get_next_line.h"

//Structure
typedef struct s_cep {
	int	c;
	int	e;
	int	p;
}		t_cep;
// main.c
// map.c
int		filename_checker(char *filename);
char	**map_checker(int fd);
char	**load_map(int fd);
// map2.c
int		char_authorized(char c);
int		map_conditions(char *line, size_t y, size_t i);
size_t	len_tab(char **map);
t_cep	collectible(char c, t_cep counter);
void	clean_malloc(char **tab);
// solve_map.c
t_cep	count_cep(char **map);
int		solve_map(char **map, t_cep counter);
#endif

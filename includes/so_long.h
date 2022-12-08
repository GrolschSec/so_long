/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:32:48 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/12/08 03:47:46 by rlouvrie         ###   ########.fr       */
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

typedef struct s_pos {
	int	x;
	int	y;
}		t_pos;

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
int		check_cep(char **map);
int		solve_map(char **map, int **tab, int c, t_pos pos);
int		**make_tab(int c);
void	free_tab_int(int **tab, int c);
int		solve(int collectible, char **map);
// solve_map2.c
t_pos	begin_pos(char **map);
#endif

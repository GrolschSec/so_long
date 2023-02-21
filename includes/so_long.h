/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:24:11 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/21 22:17:27 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../ft/libft.h"
# include "../gnl/get_next_line.h"
// Structs
typedef struct s_point
{
	int	row;
	int	col;
}				t_point;

typedef struct s_collect
{
	t_point				loc;
	int					visited;
	struct s_collect	*next;
}						t_collect;

typedef struct s_game
{
	char		**map;
	int			rows;
	int			cols;
	int			collectible;
	t_collect	*collect;
	t_point		start;
	t_point		end;
}				t_game;
// main.c
void			so_long(t_game *game);
// map_check_1.c
int				filename_check(char *filename);
char			**load_map(char	*filename);
void			ft_free_tab(char **tab);
void			free_game(t_game *game);
t_game			*validate_map(char **game);
// map_check_2.c
int				is_rectangular(t_game *game);
int				verify_map_chars(t_game *game);
int				verify_map_walls(t_game *game);
char			*map_to_str(int fd);
char			**read_map(int fd);
// map_check_3.c
int				count_map_objects(t_game *game, char c);
int				verify_map_objects(t_game *game);
void			fill_game_objects(t_game *game, int row, int col, char c);
// map_check_4.c
int				solve_map(t_game *game);
void			is_valid_path(t_game *game, int row, int col);
int				copy_map(t_game *game, t_game *copy_game);
t_game			*copy_game(t_game *game);
// chained.c
void			add_node(t_collect *head, int row, int col, t_game *game);
void			copy_collect(t_collect *head, t_game *game);
void			set_visited(t_collect *head, int row, int col);
int				check_visited(t_collect *head);
#endif

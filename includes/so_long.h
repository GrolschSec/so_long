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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define ESC 65307
# define X_KEY_EVENT_MASK (1L<<0)

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;
int		error(int n);
int		filename_checker(char *filename);
int		map_checker(int fd);
int		window_key_events(int keycode, t_vars *vars);
void	clean_malloc(char **tab);
void	so_long(int fd);
#endif

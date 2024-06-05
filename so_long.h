/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:10:46 by naotegui          #+#    #+#             */
/*   Updated: 2024/06/05 13:52:01 by naotegui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../libft_gnl/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WALL "textures/bloodwall.xpm"
# define FLOOR "textures/walkstone.xpm"
# define PLAYER "textures/zombie.xpm"
# define EXIT "textures/exit.xpm"
# define ITEM "textures/brain.xpm"
# define Q 113
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct s_map
{
	char		**map;
	size_t		x;
	int			y;
	char		*path;
	int			zombie;
	int			count;
}				t_map;

typedef struct s_zombie
{
	int			x;
	int			y;
	int			brains;
	int			c_collect;
	int			moves;
	bool		exit;
}				t_zombie;

typedef struct s_image
{
	void		*collect;
	void		*zombie;
	void		*bloodwall;
	void		*walkstone;
	void		*exit;
}				t_image;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_image		img;
	t_player	zombie;
}				t_game;

void			check_map_extension(char *argv1, t_game *game);
void			map_lenght(t_game *game);
void			take_map(t_game *game);
void			ft_error(char *message);
void			read_map(t_game *game);
void			check_four_walls(t_game *game);
void			check_map_elements(t_game *game);
void			search_player(t_game *game);
void			check_map_status_update(t_game *game);
void			check_map_status_errors(t_game *game);
void			place_pictures(t_game *game);
int				close_game_window(t_game *game);
int				keyboard_keys(int keycode, t_game *game);
void			ft_free(t_game *game);
void			put_player_exit(t_game *game, int x, int y);
void			put_zombie(t_game *game, int x, int y);
void			put_exit(t_game *game, int x, int y);
void			put_brains(t_game *game, int x, int y);
void			put_bloodwall(t_game *game, int x, int y);
void			put_walkstone(t_game *game, int x, int y);

#endif

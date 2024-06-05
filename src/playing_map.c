/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:04:40 by naotegui          #+#    #+#             */
/*   Updated: 2024/06/05 16:02:29 by naotegui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_movement(t_game *game, int my, int mx)
{
	if (game->map.map[game->zombie.y][game->zombie.x] != 'D')
		game->map.map[game->zombie.y][game->zombie.x] = '0';
	else
		game->map.map[game->zombie.y][game->zombie.x] = 'E';
	game->map.map[game->zombie.y + my][game->zombie.x + mx] = 'P';
	game->zombie.y += my;
	game->zombie.x += mx;
	obtain_pictures(game);
	ft_printf("Zombie movements %d\n", game->zombie.moves++);
}

void	get_brains(t_game *game, int my, int mx)
{
	game->zombie.brains--;
	if (game->map.map[game->zombie.y][game->zombie.x] != 'D')
		game->map.map[game->zombie.y][game->zombie.x] = '0';
	else
		game->map.map[game->zombie.y][game->zombie.x] = 'E';
	game->map.map[game->zombie.y + my][game->zombie.x + mx] = 'P';
	game->zombie.y += my;
	game->zombie.x += mx;
	obtain_pictures(game);
	ft_printf("Zombie movements %d\n", game->zombie.moves++);
}

void	checking_moves(t_game *game, int my, int mx)
{
	int	zy;
	int	zx;

	zy = game->zombie.y;
	zx = game->zombie.x;
	if (game->map.map[zy + my][zx + mx] == '1')
		return ;
	if (game->map.map[zy + my][zx + mx] == '0')
		return (player_movement(game, my, mx));
	if (game->map.map[zy + my][zx + mx] == 'C')
		return (get_brains(game, my, mx));
	if (game->map.map[zy + my][zx + mx] == 'E' && game->zombie.brains == 0)
		return ((void)(close_game_window(game)));
	else
		game->map.map[zy][zx] = '0';
	if (game->map.map[zy + my][zx + mx] == 'E')
	{
		game->map.map[game->zombie.y + my][game->zombie.x + mx] = 'D';
		game->zombie.y += my;
		game->zombie.x += mx;
	}
	obtain_pictures(game);
	ft_printf("Zombie movements %d\n", game->zombie.moves++);
}

int	keyboard_keys(int keycode, t_game *game)
{
	if (keycode == Q || keycode == ESC)
		close_game_window(game);
	else if (keycode == W)
		checking_moves(game, -1, 0);
	else if (keycode == S)
		checking_moves(game, 1, 0);
	else if (keycode == A)
		checking_moves(game, 0, -1);
	else if (keycode == D)
		checking_moves(game, 0, 1);
	return (0);
}

void	search_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				game->zombie.y = y;
				game->zombie.x = x;
				game->map.map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

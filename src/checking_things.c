/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_things.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:46:38 by naotegui          #+#    #+#             */
/*   Updated: 2024/05/30 15:58:33 by naotegui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_four_walls(t_game *game)
{
	int	x;
	int	y;

	x = game->map.x;
	y = game->map.y;
	while (x--)
	{
		if (game->map.map[0][x] != '1' || game->map.map[y - 1][x] != '1')
			ft_error("Sorry an error found\n Walls are missing");
	}
	while (y--)
	{
		if (game->map.map[y][0] != '1' || game->map.map[y][x - 1] != '1')
			ft_error("Sorry an error found\n Walls are missing");
	}
}

void	check_map_content(t_game *game, int x, int y)
{
	if (game->map.map[y][x] != '1' && game->map.map[y][x] != '0'
		&& game->map.map[y][x] != '\n')
		ft_error("Ups, error found\nInvalid map content");
}

void	check_map_elements(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
				game->map.zombie++;
			else if (game->map.map[y][x] == 'C')
				game->zombie.collect++;
			else if (game->map.map[y][x] == 'E')
				game->map.exit++;
			else
				check_map_content(game, x, y);
			x++;
		}
		y++;
	}
	if (game->map.zombie != 1 || game->map.exit != 1
		|| game->zombie.collect < 1 || game->map.exit != 1)
		ft_error("Ups, error found\nInvalid map content");
}

void	check_map_status(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == '1' || game->map.map[y][x] == 'F')
		return ;
	if (game->map.map[y][x] == 'C')
		game->zombie.brains++;
	if (game->map.map[y][x] == 'E')
		game->zombie.exit = true;
	game->map.map[y][x] = 'F';
	check_map_status(game, y + 1, x);
	check_map_status(game, y - 1, x);
	check_map_status(game, y, x + 1);
	check_map_status(game, y, x - 1);
}

void	check_map_status_update(t_game *game)
{
	check_map_status(game, game->zombie.y, game->zombie.x);
}

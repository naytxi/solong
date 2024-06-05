/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:30:08 by naotegui          #+#    #+#             */
/*   Updated: 2024/05/30 16:07:08 by naotegui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_flood_fill(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == '1' || game->map.map[y][x] == 'F')
		return ;
	if (game->map.map[y][x] == 'C')
		game->zombie.brains++;
	if (game->map.map[y][x] == 'E')
		game->zombie.door = true;
	game->map.map[y][x] = 'F';
	ft_flood_fill(game, y + 1, x);
	ft_flood_fill(game, y - 1, x);
	ft_flood_fill(game, y, x + 1);
	ft_flood_fill(game, y, x + 1);
}

void	map_error(t_game *game)
{
	if (game->map.brains != game->zombie.brains || game->zombie.door == false)
		ft_error("UUUUG\n Zombie can't eat");
	ft_free(game);
}

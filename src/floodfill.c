/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:30:08 by naotegui          #+#    #+#             */
/*   Updated: 2024/06/26 14:06:22 by naotegui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == '1' || game->map.map[y][x] == 'F')
		return ;
	if (game->map.map[y][x] == 'C')
		game->zombie.brains++;
	if (game->map.map[y][x] == 'E')
		game->zombie.exit = true;
	game->map.map[y][x] = 'F';
	ft_flood_fill(game, y + 1, x);
	ft_flood_fill(game, y - 1, x);
	ft_flood_fill(game, y, x + 1);
	ft_flood_fill(game, y, x + 1);
}

void	map_error(t_game *game)
{
	if (game->map.count != game->zombie.brains || game->zombie.exit == false)
		ft_error("Error\n Zombie can't eat");
	ft_free(game);
}

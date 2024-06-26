/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bugs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:27:40 by naotegui          #+#    #+#             */
/*   Updated: 2024/06/26 14:06:27 by naotegui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_game *game)
{
	int	y;

	y = -1;
	while (game->map.map[++y])
		free(game->map.map[y]);
	free(game->map.map);
	game->map.map = NULL;
}

void	check_map_status_bugs(t_game *game)
{
	if (game->zombie.c_collect != game->zombie.brains
		|| game->zombie.exit == false)
		ft_error("Error\nZombie can`t eat\n");
	ft_free(game);
}

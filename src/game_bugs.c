/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bugs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:27:40 by naotegui          #+#    #+#             */
/*   Updated: 2024/05/30 16:07:48 by naotegui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	if (game->player.c_collect != game->player.brains
		|| game->player.exit == false)
		ft_error("Map is unplayable\n");
	ft_free(game);
}

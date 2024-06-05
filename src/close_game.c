/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:04:24 by naotegui          #+#    #+#             */
/*   Updated: 2024/06/05 13:54:27 by naotegui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.collect);
	mlx_destroy_image(game->mlx, game->img.walkstone);
	mlx_destroy_image(game->mlx, game->img.zombie);
	ft_free(game);
	exit(EXIT_SUCCESS);
}

void	put_exit_door(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.exit, (x * 64),
		(y * 64));
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.zombie, (x
			* 64), (y * 64));
}

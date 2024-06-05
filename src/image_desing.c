/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_desing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:36:18 by naotegui          #+#    #+#             */
/*   Updated: 2024/05/30 16:09:17 by naotegui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "..\so_long.h"

void	put_walkstone(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.walkstone,
		(x * 64), (y * 64));
}

void	put_bloodwall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.bloodwall,
		(x * 64), (y * 64));
}

void	put_brains(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.brain,
		(x * 64), (y * 64));
}

void	put_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.exit,
		(x * 64), (y * 64));
}

void	put_zombie(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.zombie,
		(x * 64), (y * 64));
}

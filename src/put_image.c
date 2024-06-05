/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:22:05 by naotegui          #+#    #+#             */
/*   Updated: 2024/05/30 15:58:12 by naotegui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "..\so_long.h"

static void	xpm_desing(t_game *game)
{
	int	x;
	int	y;

	game->pictures.zombie = mlx_xpm_file_to_image(game->mlx, ZOMBIE,
			&(x), &(y));
	game->pictures.bloodwall = mlx_xpm_file_to_image(game->mlx, BLOODWALL,
			&(x), &(y));
	game->pictures.walkstone = mlx_xpm_file_to_image(game->mlx, WALKSTONE,
			&(x), &(y));
	game->pictures.exit = mlx_xpm_file_to_image(game->mlx, EXIT,
			&(x), &(y));
	game->pictures.brains = mlx_xpm_file_to_image(game->mlx, BRAIN,
			&(x), &(y));
}

static void	place_pictures(t_game *game, int x, int y)
{
	char	actualposition;

	actualposition = game->map.map[y][x];
	if (actualposition == '1')
	{
		put_bloodwall(game, x, y);
		return ;
	}
	put_walkstone(game, x, y);
	if (actualposition == 'C')
		put_brains(game, x, y);
	if (actualposition == 'E')
		put_exit(game, x, y);
	if (actualposition == 'P')
		put_zombie(game, x, y);
	if (actualposition == 'D')
		put_player_exit(game, x, y);
}

void	obtain_pictures(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	xpm_desing(game);
	while (game->map.map[y] != 0)
	{
		x = 0;
		while (game->map.map[y][x] != 0)
		{
			place_pictures(game, x, y);
			x++;
		}
		y++;
	}
}

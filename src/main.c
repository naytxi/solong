/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:04:37 by naotegui          #+#    #+#             */
/*   Updated: 2024/06/05 14:52:13 by naotegui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *message)
{
	ft_printf("%s", message);
	exit(1);
}

static void	check_number_of_args(int argc)
{
	if (argc != 2)
		ft_error("Error 404\nMissing game or map file\n");
}

void	hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 1, close_game_window, game);
	mlx_hook(game->mlx_win, 2, 1, keyboard_keys, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_number_of_args(argc);
	ft_bzero(&game, sizeof(t_game));
	check_map_extension(argv[1], &game);
	map_lenght(&game);
	take_map(&game);
	check_four_walls(&game);
	check_map_elements(&game);
	search_player(&game);
	check_map_status_update(&game);
	check_map_status_bugs(&game);
	take_map(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map.x * 64, game.map.y * 64,
			"so_long");
	hooks(&game);
	obtain_pictures(&game);
	mlx_loop(game.mlx);
	return (0);
}

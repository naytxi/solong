/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naotegui <naotegui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:04:20 by naotegui          #+#    #+#             */
/*   Updated: 2024/06/26 12:55:56 by naotegui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_extension(char *argv1, t_game *game)
{
	int	i;

	i = ft_strlen(argv1);
	if (ft_strncmp(&argv1[i - 4], ".ber", 4) != 0)
	{
		ft_error("Ups error\nMap file must br a .ber\n");
	}
	game->map.path = argv1;
}

void	map_lenght(t_game *game)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = 0;
	fd = open(game->map.path, O_RDONLY | O_NOFOLLOW);
	if (fd < 0)
		ft_error("Error404\nMap not found\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("Error\nMap is empty (Insert Travolta's file)\n");
	game->map.x = ft_strlen(line) - 1;
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strlen(line) != game->map.x)
			ft_error("Error\nWalls are missing\n");
		game->map.y++;
		temp = line;
		line = get_next_line(fd);
		free(temp);
	}
	close(fd);
}

void	take_map(t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	fd = 0;
	fd = open(game->map.path, O_RDONLY);
	if (fd < 0)
		ft_error("Error 404\nMap not found\n");
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.y + 1));
	if (!game->map.map)
		return ;
	line = get_next_line(fd);
	if (!line)
		ft_error("Error\nMap is empty (Inster Travolta's gif)\n");
	i = 0;
	while (i < game->map.y)
	{
		game->map.map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	game->map.map[i] = NULL;
	close(fd);
}

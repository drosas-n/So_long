/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:10:25 by drosas-n          #+#    #+#             */
/*   Updated: 2024/08/28 18:23:55 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	ft_leaks(void)
{
	system("leaks -q so_long");
} */
/* atexit(ft_leaks); */

static int	check_map(t_game *game, char **argv)
{
	if (check_extension(argv[1]) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (read_map(argv, game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (lines_and_walls(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (other_walls(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (things(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (valid_way(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	if (argc != 2)
		return (ft_printf("Error\nIntroduzca mapa\n"), EXIT_FAILURE);
	init_struct(game);
	if (check_map(game, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game->mlx = mlx_init(game->x * 50, game->y * 50, "Escapa", false);
	if (create_image(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	init_game(game);
	mlx_key_hook(game->mlx, &keyhook, game);
	mlx_close_hook(game->mlx, &close_game, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (free_all(game), EXIT_SUCCESS);
}

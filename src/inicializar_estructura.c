/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicializar_estructura.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:10:04 by drosas-n          #+#    #+#             */
/*   Updated: 2024/08/28 17:10:05 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->y = 0;
	game->x = 0;
	game->i = 0;
	game->z = -1;
	game->j = 0;
	game->c_player = 0;
	game->c_exit = 0;
	game->c_collect = 0;
	game->c_collect_copy = 0;
	game->c_exit_copy = 0;
	game->moves = 0;
}

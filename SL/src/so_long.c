/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:01:02 by bharghaz          #+#    #+#             */
/*   Updated: 2021/12/15 17:01:09 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (valid_file(argc, argv[1]))
	{
		if (!start(&game, argv))
			return (1);
		mlx_key_hook(game.window, &input, (void *)&game);
		mlx_loop_hook(game.mlx, &update, (void *) &game);
		mlx_loop(game.mlx);
		return (0);
	}
	error("no valid map, no game.");
	return (1);
}

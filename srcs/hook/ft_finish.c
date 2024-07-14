/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:12:53 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/14 20:01:18 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_info *data)
{
	ft_free_info(data);
	mlx_destroy_window(data->grafics.mlx, data->grafics.win);
	exit(EXIT_SUCCESS);
}

void	ft_exit_error(t_info *data, char *err)
{
	ft_putstr_fd("\x1b[31mError\x1b[0m\n", 2);
	if (err && *err)
	{
		ft_putstr_fd(err, 2);
		write(2, "\n", 1);
	}
	ft_free_info(data);
	mlx_destroy_window(data->grafics.mlx, data->grafics.win);
	exit(EXIT_FAILURE);
}

void	ft_game_result(t_info *data)
{
	int	i;
	int	j;

	i = (data->grafics.width) * RES / 2.2;
	j = (data->grafics.height) * RES / 4;
	mlx_clear_window(data->grafics.mlx, data->grafics.win);
	if (data->player.alive == 1)
		mlx_string_put(data->grafics.mlx, data->grafics.win, i, j, 0x00FF00,
			"You won!");
	else
		mlx_string_put(data->grafics.mlx, data->grafics.win, i, j, 0xFF0000,
			"You lost!");
	data->running = 0;
}

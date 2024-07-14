/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:59:55 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/14 20:04:28 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_reset_data(t_info *data, char *name)
{
	int	i;

	data->grafics.height = 0;
	data->grafics.width = 0;
	data->player.x = 0;
	data->player.y = 0;
	data->player.alive = 0;
	data->player.coins = 0;
	data->player.step = 0;
	data->finish = 0;
	data->grafics.txt = name;
	data->player.direction = 'S';
	data->has_changed = 1;
	data->running = 1;
	data->grafics.map = NULL;
	data->player.open = 0;
	i = -1;
	while (++i < NUMBERS_SPRITE)
		data->img[i].spsh = ft_calloc(1, sizeof(t_img));
	i = -1;
	while (++i < NUMBERS_SPRITE)
		ft_bzero(data->img[i].frames, sizeof(data->img[i].frames));
	ft_load_img(data);
	ft_successful("Reset Data");
}

void	ft_general_check(t_info *data)
{
	ft_check_outline(data);
	ft_check_format_dotber(data);
	ft_check_map_inputs(data);
	ft_check_map_objects(data);
	ft_check_is_posible(data);
	ft_successful("General Check");
}

int	ft_frame(t_info *data)
{
	if (data->player.coins == 0 && data->finish == 0)
		data->player.open = 1;
	if (data->player.alive == 0 || (data->player.coins == 0
			&& data->finish == 1))
		ft_game_result(data);
	else if (data->has_changed == 1)
	{
		mlx_clear_window(data->grafics.mlx, data->grafics.win);
		ft_draw_map(data);
		data->has_changed = 0;
	}
	if (data->player.step == 112 && data->finish == 0)
	{
		ft_printf("\033[0;31mYou have reached the max of steps\n\033[0m");
		data->player.alive = 0;
		data->finish = 1;
	}
	ft_steps(data);
	return (0);
}

/*
#include <stdio.h>

void	print(t_info *data)
{
	int	i;

	i = 0;
	while(data->map[i] != NULL)
		printf("%s\n", data->map[i++]);
}
*/

void	init(char **argv)
{
	t_info	data;

	data.grafics.mlx = mlx_init(data);
	if (!data.grafics.mlx)
		ft_error("Error: mlx_init() failed");
	ft_reset_data(&data, argv[1]);
	ft_map_size(&data);
	ft_malloc_map(&data);
	ft_general_check(&data);
	if (data.grafics.height * RES > MAC_H || data.grafics.width * RES > MAC_W)
		ft_error("map error: map is too large");
	data.grafics.win = mlx_new_window(data.grafics.mlx, data.grafics.width
			* RES, data.grafics.height * RES, NAME);
	if (!data.grafics.win)
		ft_error("Error: mlx_new_window() failed");
	mlx_hook(data.grafics.win, 17, 0, ft_exit, &data);
	mlx_hook(data.grafics.win, 2, 1L >> 0, ft_press_key, &data);
	mlx_loop_hook(data.grafics.mlx, ft_frame, &data);
	mlx_loop(data.grafics.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:04:41 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/14 20:10:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static int	ft_event_check(t_bonus *data)
{
	if (data->info.player.coins == 0 && data->info.finish == 1)
	{
		ft_game_result(&data->info);
		return (0);
	}
	if (data->info.player.alive == 0 && data->info.finish == 1)
		ft_game_result(&data->info);
	if (data->info.has_changed == 1 && data->info.finish != 1
		&& data->info.player.alive != 0)
	{
		ft_draw_map_bonus(data);
		data->info.has_changed = 0;
	}
	else if (data->info.has_changed == 0 && data->info.finish != 1
		&& data->info.player.alive != 0)
	{
		ft_animation(data);
	}
	return (0);
}

static void	ft_reset_info(t_bonus *data, char *name)
{
	int	i;

	data->info.grafics.txt = name;
	data->info.player.direction = 'S';
	data->info.has_changed = 1;
	data->info.running = 1;
	i = -1;
	while (++i < NUMBERS_SPRITE)
		data->info.img[i].spsh = ft_calloc(1, sizeof(t_img));
	ft_load_img(&data->info);
	ft_spritesheet(&data->info, ENEMY_SPRITESHEET, ENEMY);
	ft_load_frames(&data->info, ENEMY);
	ft_successful("Reset Data");
}

int	ft_frame_bonus(t_bonus *data)
{
	int	i;

	i = 0;
	if (data->info.player.coins == 0 && data->info.finish == 0)
		data->info2.open = 1;
	i = ft_event_check(data);
	ft_steps(&data->info);
	return (i);
}

static void	ft_general_check_bonus(t_bonus *data)
{
	ft_check_outline(&data->info);
	ft_check_format_dotber(&data->info);
	ft_check_map_inputs_bonus(data);
	ft_check_map_objects_bonus(data);
	ft_check_is_posible(&data->info);
	ft_successful("General Check");
}

void	init_bonus(char **argv)
{
	t_bonus	data;

	ft_bzero(&data, sizeof(t_bonus));
	data.info.grafics.mlx = mlx_init();
	if (!data.info.grafics.mlx)
		ft_error("Error: mlx_init() failed");
	ft_reset_info(&data, argv[1]);
	ft_map_size(&data.info);
	ft_malloc_map(&data.info);
	ft_general_check_bonus(&data);
	if (data.info.grafics.height * RES > MAC_H || data.info.grafics.width
		* RES > MAC_W)
		ft_error("map error: map is too large");
	data.info.grafics.win = mlx_new_window(data.info.grafics.mlx,
			data.info.grafics.width * RES, data.info.grafics.height * RES,
			NAME_B);
	if (!data.info.grafics.win)
		ft_error("Error: mlx_new_window() failed");
	mlx_hook(data.info.grafics.win, 17, 0, ft_exit, &data.info);
	mlx_hook(data.info.grafics.win, 2, 1L >> 0, ft_press_key_bonus, &data);
	mlx_loop_hook(data.info.grafics.mlx, ft_frame_bonus, &data);
	mlx_loop(data.info.grafics.mlx);
}

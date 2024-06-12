/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:59:55 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/12 13:55:08 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_reset_data(t_info *data, char *name)
{
	data->lost = 0;
	data->height = 0;
	data->width = 0;
	data->px = 0;
	data->py = 0;
	data->player = 0;
	data->coins = 0;
	data->step = 0;
	data->finish = 0;
	data->txt = name;
	data->direction = 'S';
	data->has_changed = 1;
	data->running = 1;
	data->map = NULL;
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
	if (data->coins == 0 && data->player == 1 && data->finish == 1)
		ft_game_result(data);
	else if (data->has_changed == 1)
	{
		mlx_clear_window(data->mlx, data->win);
		ft_draw_map(data);
		data->has_changed = 0;
	}
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

	data.mlx = mlx_init(data);
	if (!data.mlx)
		ft_error("Error: mlx_init() failed");
	ft_reset_data(&data, argv[1]);
	ft_map_size(&data);
	ft_malloc_map(&data);
	ft_general_check(&data);
	data.win = mlx_new_window(data.mlx, data.width * RES, data.height * RES,
			NAME);
	if (!data.win)
		ft_error("Error: mlx_new_window() failed");
	mlx_hook(data.win, 17, 0, ft_exit, &data);
	mlx_key_hook(data.win, ft_press_key, &data);
	mlx_loop_hook(data.mlx, ft_frame, &data);
	mlx_loop(data.mlx);
}

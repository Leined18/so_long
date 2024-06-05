/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:00:41 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/05 12:32:26 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_calculate_spritesheet_info(t_info *data, int frame_width,
		int frame_height, t_spr sprite)
{
	int	columns;

	if (frame_width == 0 || frame_height == 0)
	{
		data->s_info.total_frames[sprite] = 0;
		data->s_info.rows[sprite] = 0;
	}
	else
	{
		data->s_info.rows[sprite] = data->s_info.height[sprite] / frame_height;
		columns = data->s_info.width[sprite] / frame_width;
		data->s_info.total_frames[sprite] = data->s_info.rows[sprite] * columns;
		data->s_info.frames[sprite] = columns;
	}
}

int	ft_get_s_sheet_img(t_info *data, char *path, t_spr sp)
{
	data->img[sp].spsh->img = mlx_xpm_file_to_image(data->mlx, path,
			&data->s_info.width[sp], &data->s_info.height[sp]);
	if (!data->img[sp].spsh->img)
		return (1);
	data->img[sp].spsh->addr = mlx_get_data_addr(data->img[sp].spsh->img,
			&data->img[sp].spsh->bits_per_pixel,
			&data->img[sp].spsh->line_length,
			&data->img[sp].spsh->endian);
	return (0);
}

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
		int frame_height, int sprite)
{
	int	columns;

	if (frame_width == 0 || frame_height == 0)
	{
		data->s_info[sprite].total_frames = 0;
		data->s_info[sprite].rows = 0;
	}
	else
	{
		data->s_info[sprite].rows = data->s_info[sprite].height / frame_height;
		columns = data->s_info[sprite].width / frame_width;
		data->s_info[sprite].total_frames = data->s_info[sprite].rows * columns;
		data->s_info[sprite].frames = columns;
	}
}

int	ft_get_s_sheet_img(t_info *data, char *path, int sp)
{
	data->img[sp].spsh->img = mlx_xpm_file_to_image(data->grafics.mlx, path,
			&data->s_info[sp].width, &data->s_info[sp].height);
	if (!data->img[sp].spsh->img)
		return (1);
	data->img[sp].spsh->addr = mlx_get_data_addr(data->img[sp].spsh->img,
			&data->img[sp].spsh->bits_per_pixel,
			&data->img[sp].spsh->line_length, &data->img[sp].spsh->endian);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spritesheet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:56:05 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/05 12:49:14 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_spritesheet(t_info *data, char *path, t_spr type)
{
	int	i;

	i = ft_get_s_sheet_img(data, path, type);
	if (!data->s_info.width[type] || !data->s_info.height[type])
		return (1);
	ft_calculate_spritesheet_info(data, RES, RES, type);
	return (i);
}

void	ft_load_frames(t_info *data, int i)
{
	int	r;
	int	f;
	int	count;

	count = 0;
	while (count < data->s_info.total_frames[i])
	{
		r = 0;
		while (r < data->s_info.rows[i])
		{
			f = 0;
			while (f < data->s_info.frames[i])
			{
				data->img[i].frames[r][f] = ft_extract_frame(data, i, f
						* RES, r * RES);
				count++;
				f++;
			}
			r++;
		}
	}
}

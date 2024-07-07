/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spritesheet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:56:05 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/07 23:04:18 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_spritesheet(t_info *data, char *path, int type)
{
	int	i;

	i = ft_get_s_sheet_img(data, path, type);
	if (!data->s_info[type].width || !data->s_info[type].height)
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
	while (count < data->s_info[i].total_frames)
	{
		r = 0;
		while (r < data->s_info[i].rows)
		{
			f = 0;
			while (f < data->s_info[i].frames)
			{
				data->img[i].frames[r][f] = ft_extract_frame(data, i, f * RES, r
						* RES);
				count++;
				f++;
			}
			r++;
		}
	}
}

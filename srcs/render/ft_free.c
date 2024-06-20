/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:09:59 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/05 13:05:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_map(t_info *data)
{
	int	i;

	i = -1;
	while (++i < data->grafics.height)
		if (data->grafics.map[i])
			freedom((void **)&data->grafics.map[i]);
	if (data->grafics.map)
		freedom((void **)&data->grafics.map);
}

static void	ft_free_sprites(t_info *data)
{
	int	i;

	i = -1;
	while (++i < NUMBERS_SPRITE)
	{
		if (data->img[i].spsh && data->img[i].spsh->img)
		{
			mlx_destroy_image(data->grafics.mlx, data->img[i].spsh->img);
			freedom((void **)&data->img[i].spsh);
		}
	}
}

static void	ft_free_frames(t_info *data)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < NUMBERS_SPRITE)
	{
		j = -1;
		while (++j < data->s_info[i].rows)
		{
			k = -1;
			while (++k < data->s_info[i].frames)
			{
				if (data->img[i].frames[j][k])
				{
					if (data->img[i].frames[j][k]->img)
						mlx_destroy_image(data->grafics.mlx,
							data->img[i].frames[j][k]->img);
					freedom((void **)&data->img[i].frames[j][k]);
				}
			}
		}
	}
}

void	ft_free_info(t_info *data)
{
	if (data)
	{
		ft_free_map(data);
		ft_free_sprites(data);
		ft_free_frames(data);
	}
	exit(EXIT_SUCCESS);
}

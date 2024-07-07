/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:59:29 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/07 22:57:18 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_all_spritesheets(t_info *data)
{
	int	result;

	result = 0;
	result += ft_spritesheet(data, COLLECT_SPRITESHEET, COLLECT);
	result += ft_spritesheet(data, FIELD_SPRITESHEET, FIELD);
	result += ft_spritesheet(data, EXIT_SPRITESHEET, EXIT);
	result += ft_spritesheet(data, PLAYER_SPRITESHEET, PLAYER);
	result += ft_spritesheet(data, WALL_SPRITESHEET, WALL);
	result += ft_spritesheet(data, WINNER_SPRITESHEET, WINNER);
	return (result);
}

void	ft_load_img(t_info *data)
{
	int	i;

	if (load_all_spritesheets(data))
		ft_exit_error(data, "Failed to load spritesheet");
	i = -1;
	while (++i < NUMBERS_SPRITE)
		ft_load_frames(data, i);
}

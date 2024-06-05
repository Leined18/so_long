/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:12:53 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/05 12:14:52 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_info *data)
{
	ft_free_info(data);
	mlx_destroy_window(data->mlx, data->win);
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
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_FAILURE);
}

void	ft_game_result(t_info *data)
{
	int	i;
	int	j;

	i = (data->width) * RES / 2.2;
	j = (data->hight) * RES / 4;
	mlx_clear_window(data->mlx, data->win);
	mlx_string_put(data->mlx, data->win, i, j, 0x00FF00, "You won!");
	data->running = 0;
}

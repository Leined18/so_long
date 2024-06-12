/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:56:53 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/05 13:05:21 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_size(t_info *data)
{
	char	*line;
	int		fd;

	fd = open(data->txt, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_error("Map not read");
	data->width = ft_strlen(line) - 1;
	data->height = 0;
	while (line)
	{
		if (((int)ft_strlen(line) - 1) != (data->width))
			ft_error("Map not valid");
		data->height++;
		freedom((void **)&line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_malloc_map(t_info *data)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(data->txt, O_RDONLY);
	i = 0;
	data->map = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
		ft_error("not Malloc");
	while (i < data->height)
	{
		line = get_next_line(fd);
		if (!line)
			ft_error("not Malloc");
		data->map[i] = ft_strdup(line);
		if (!data->map[i])
			ft_error("not Malloc");
		data->map[i][data->width] = '\0';
		i++;
		freedom((void **)&line);
	}
	data->map[i] = NULL;
	close(fd);
}

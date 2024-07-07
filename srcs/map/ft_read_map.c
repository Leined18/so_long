/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:56:53 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/07 22:57:48 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_size(t_info *data)
{
	char	*line;
	int		fd;

	fd = open(data->grafics.txt, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_error("Map not read");
	data->grafics.width = ft_strlen(line) - 1;
	data->grafics.height = 0;
	while (line)
	{
		if (((int)ft_strlen(line) - 1) != (data->grafics.width))
			ft_error("Map not valid");
		data->grafics.height++;
		freedom((void **)&line);
		line = get_next_line(fd);
	}
	if (data->grafics.height == 0)
		ft_error("Map not valid");
	close(fd);
}

void	ft_malloc_map(t_info *data)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(data->grafics.txt, O_RDONLY);
	i = 0;
	data->grafics.map = (char **)malloc(sizeof(char *) * (data->grafics.height
				+ 1));
	if (!data->grafics.map)
		ft_error("not Malloc");
	while (i < data->grafics.height)
	{
		line = get_next_line(fd);
		if (!line)
			ft_error("not Malloc");
		data->grafics.map[i] = ft_strdup(line);
		if (!data->grafics.map[i])
			ft_error("not Malloc");
		data->grafics.map[i][data->grafics.width] = '\0';
		i++;
		freedom((void **)&line);
	}
	data->grafics.map[i] = NULL;
	close(fd);
}

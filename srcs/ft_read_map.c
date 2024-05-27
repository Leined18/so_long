
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
	data->hight = 0;
	while (line)
	{
		if (((int)ft_strlen(line) - 1) != (data->width))
			ft_error("Map not valid");
		data->hight++;
		freedom((void **)&line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_malloc_map(t_info *data)
{
	char *line;
	int fd;
	int i;

	fd = open(data->txt, O_RDONLY);
	i = 0;
	data->map = (char **)malloc(sizeof(char *) * (data->hight + 1));
	if (!data->map)
		ft_error("not Malloc");
	while (i < data->hight)
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
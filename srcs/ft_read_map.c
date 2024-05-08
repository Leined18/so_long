
# include "so_long.h"

static void	ft_bad_malloc(void)
{
	ft_error("Map not malloc");
	exit (EXIT_FAILURE);
}

void	ft_map_size(t_info_map *data)
{
	char	*line;
	int		fd;

	fd = open(data->txt, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		ft_error("Map not read");
		exit (EXIT_FAILURE);
	}
	data->width = ft_strlen(line) - 1;
	data->hight = 0;
	while (line)
	{
		if ((int)ft_strlen(line) - 1 != data->width)
		{
			ft_error("Map not valid");
			exit (EXIT_FAILURE);
		}
		data->hight++;
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
}

void	ft_malloc_map(t_info_map *data)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(data->txt, O_RDONLY);
	i = 0;
	data->map = (char **)malloc(sizeof (char *) * (data->hight + 1));
	if (!data->map)
		ft_bad_malloc();
	while (i < data->hight)
	{
		line = get_next_line(fd);
		if (!line)
			ft_bad_malloc();
		data->map[i] = ft_strdup(line);
		if (!data->map[i])
			ft_bad_malloc();
		data->map[i][data->width] = '\0';
		i++;
		free(line);
	}
	data->map[i] = NULL;
	close(fd);
}
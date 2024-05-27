#include "so_long.h"

void	ft_free(t_info *data)
{
	int	i;
	int	j;
	int	k;

	// Free the map
	i = 0;
	while (i < data->hight)
	{
		freedom((void **)&data->map[i]);
		i++;
	}
	freedom((void **)&data->map);

	// Free spritesheets and images
	i = 0;
	while (i < NUMBERS_SPRITE)
	{
		if (data->images[i].spritesheet->img)
		{
			mlx_destroy_image(data->mlx, data->images[i].spritesheet->img);
			freedom((void **)&data->images[i].spritesheet);
		}
		i++;
	}

	// Free frames
	i = 0;
    while (i < data->s_info.total_frames[i])
    {
        j = 0;
        while (j < data->s_info.rows[i])
        {
            k = 0;
            while (k < data->s_info.frames[i])
            {
				if (data->images[i].frames[j][k]->img)
					mlx_destroy_image(data->mlx, data->images[i].frames[j][k]->img);
				freedom((void **)&data->images[i].frames[j][k]);
                k++;
            }
			freedom((void **)&data->images[i].frames[j]);
            j++;
        }
		i++;
    }
}

void	ft_free_info(t_info *data)
{
	if (data)
	{
		ft_free(data);
		if (data->mlx && data->win)
		{
			mlx_destroy_window(data->mlx, data->win);
		}
	}
	exit(EXIT_SUCCESS);
}

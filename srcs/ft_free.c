#include "so_long.h"

void	ft_free(t_info *data)
{
	int	i;
	int	j;
	int	k;

	if (!data)
		return;

	// Liberar el mapa
	i = 0;
	while (i < data->hight)
	{
		if (data->map[i])
			freedom((void **)&data->map[i]);
		i++;
	}
	if (data->map)
		freedom((void **)&data->map);

	// Liberar spritesheet
	i = 0;
	while (i < NUMBERS_SPRITE)
	{
		if (data->images[i].spritesheet && data->images[i].spritesheet->img)
		{
			mlx_destroy_image(data->mlx, data->images[i].spritesheet->img);
			freedom((void **)&data->images[i].spritesheet);
		}
		i++;
	}
	i = 0;
	while (i < NUMBERS_SPRITE)
	{
	    j = 0;
	    while (j < data->s_info.rows[i])
	    {
	        k = 0;
	        while (k < data->s_info.frames[i])
	        {
	            if (data->images[i].frames[j][k])
	            {
	                if (data->images[i].frames[j][k]->img)
	                    mlx_destroy_image(data->mlx, data->images[i].frames[j][k]->img);
	                freedom((void **)&data->images[i].frames[j][k]);
	            }
	            k++;
	        }
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
	}
	exit(EXIT_SUCCESS);
}

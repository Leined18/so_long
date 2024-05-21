#include "so_long.h"

void ft_free_sprites(t_info *data)
{
	int i;
	int j;

	i = 0;
	while (i < NUMBERS_SPRITE)
	{
		j = 0;
		while (j < N_D)
		{
			free(data->images->sprites[i][j]);
			j++;
		}
		i++;
	}
}
void ft_free_data(t_info *data)
{
	free(data->images->p_up);
	free(data->images->p_down);
	free(data->images->p_right);
	free(data->images->p_left);
	free(data->images->wall);
	free(data->images->empty);
	free(data->images->exit);
	free(data->images->collect);
	free(data->images->winner);
	free(data->images);
	free(data->txt);
	free(data->map);
}


void ft_free_info(t_info *data)
{
	// Liberar la memoria de las imágenes
	ft_free_sprites(data);
	ft_free_data(data);
	// Finalmente, liberar la memoria de la estructura en sí
	free(data);
}
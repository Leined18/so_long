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
			free(data->images.sprites[i][j]);
			j++;
		}
		i++;
	}
}
void ft_free_data(t_info *data)
{
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
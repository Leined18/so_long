#include "so_long.h"

void	ft_free_sprites(void *****sprite, void ***spritesheet, t_info *data)
{
	int					i;
	t_info	*temp;

	i = 0;
	temp = data;
	int j, k;
	while (i++ < NUMBERS_SPRITE)
	{
		j = 0;
		while (j++ < temp->spritesheetInfo.rows)
		{
			k = 0;
			while (k++ < temp->spritesheetInfo.frames)
				free((sprite)[i][j][k]);
			free((*sprite)[i][j]);
		}
		free((*sprite)[i]);
		temp = temp->next;
	}
	free(*sprite);
	i = 0;
	while (i++ < NUMBERS_SPRITE)
		free((*spritesheet)[i]);
	free(*spritesheet);
}

void	ft_free_data(t_info *data)
{
	free(data->txt);
	free(data->map);
}

void	ft_free_info(t_info *data)
{
	t_info	*temp;

	temp = data;
	ft_free_sprites(&temp->images.sprites, &temp->images.spritesheet, temp);
	ft_free_data(temp);
	// Finalmente, liberar la memoria de la estructura en sí
	free(temp);
}

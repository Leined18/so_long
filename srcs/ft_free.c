#include "so_long.h"

void	ft_free_sprites(void *****sprite, void ***spritesheet, t_info *data, sprite_type type)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = -1;
	while (++i < NUMBERS_SPRITE)
	{
		j = -1;
		while (++j < data->spritesheetInfo.rows[type])
		{
			k = -1;
			while (++k < data->spritesheetInfo.frames[type])
				free((*sprite)[i][j][k]);
			free((*sprite)[i][j]);
		}
		free((*sprite)[i]);
	}
	free(*sprite);
	i = -1;
	while (++i < NUMBERS_SPRITE)
		free((*spritesheet)[i]);
	free(*spritesheet);
}

void	ft_free_data(t_info *data, sprite_type type)
{
	data->txt = 0;
	data->map = 0;
	data->spritesheetInfo.total_frames[type] = 0;
	data->spritesheetInfo.frames[type] = 0;
	data->spritesheetInfo.rows[type] = 0;
	data->spritesheetInfo.width[type] = 0;
	data->spritesheetInfo.height[type] = 0;

	free(data->txt);
	free(data->map);
	free(data);
}

void	ft_free_info(t_info *data, sprite_type type)
{
	ft_free_sprites(&data->images.sprites, &data->images.spritesheet, data, type);
	ft_free_data(data, type);
	free(data);
}

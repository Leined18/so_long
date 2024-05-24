#include "so_long.h"

void    ft_free_sprites(void ****sprite, void **spritesheet, t_info *data, sprite_type type)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < NUMBERS_SPRITE)
	{
		j = -1;
		while (++j < data->spritesheetInfo.rows[type])
		{
			k = -1;
			while (++k < data->spritesheetInfo.frames[type])
				free(sprite[i][j][k]);
			free((*sprite)[i][j]);
		}
		free((*sprite)[i]);
	}
	free(sprite);
	i = -1;
	while (++i < NUMBERS_SPRITE)
		free((spritesheet)[i]);
	free(spritesheet);
}

void	ft_free_info(t_info *data, sprite_type type)
{
	ft_free_sprites(data->images.sprites, data->images.spritesheet, data, type);
	free(data);
}

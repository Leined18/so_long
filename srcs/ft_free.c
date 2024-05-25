#include "so_long.h"

/*static void    ft_free_sprites(void ****sprite, void **spritesheet, t_info *data, sprite_type type)
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
}*/

void	ft_free_info(t_info *data)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < NUMBERS_SPRITE)
	{
		j = -1;
		while (++j < data->spritesheetInfo.rows[i])
		{
			k = -1;
			while (++k < data->spritesheetInfo.frames[i])
				free(data->images.sprites[i][j][k]);
			free(data->images.sprites[i][j]);
		}
		free(data->images.sprites[i]);
	}
	i = -1;
	while (++i < NUMBERS_SPRITE)
		free(data->images.spritesheet[i]);
}

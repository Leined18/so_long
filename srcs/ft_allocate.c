#include "so_long.h"

void	init_sprites(t_info *data)
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
			{
				if (data->images.sprites[i][j][k]) {
					data->images.sprites[i][j][k]->width = RES;
					data->images.sprites[i][j][k]->height = RES;
					data->images.sprites[i][j][k]->addr = 0;
					data->images.sprites[i][j][k]->bits_per_pixel = 0;
					data->images.sprites[i][j][k]->line_length = 0;
					data->images.sprites[i][j][k]->endian = 0;
				}
			}
		}
	}
}

void	ft_allocate_memory_for_sprites(t_img ****sprite, t_info *temp,
		sprite_type type, int j)
{
	int	k;

	k = -1;
	while (++k < temp->spritesheetInfo.frames[type])
	{
		(*sprite)[j][k] = ft_calloc(1, sizeof(t_img));
		if (!(*sprite)[j][k])
		{
			while (k-- > 0)
				free((*sprite)[j][k]);
			free((*sprite)[j]);
			ft_error("Error allocating memory for the fourth level");
		}
	}
}

void	ft_allocate_single_sprite(t_img ****sprite, t_info *temp,
		sprite_type type)
{
	int	j;

	*sprite = ft_calloc(temp->spritesheetInfo.rows[type], sizeof(t_img ***));
	if (!*sprite)
		ft_error("Error allocating memory for the second level");
	j = -1;
	while (++j < temp->spritesheetInfo.rows[type])
	{
		(*sprite)[j] = ft_calloc(temp->spritesheetInfo.frames[type],
				sizeof(t_img **));
		if (!(*sprite)[j])
		{
			while (j-- > 0) // Free the previously allocated memory
				free((*sprite)[j]);
			free(*sprite); // Free the first level
			ft_error("Error allocating memory for the third level");
		}
		ft_allocate_memory_for_sprites(sprite, temp, type, j);
	}
}

void	ft_allocate_sprites(t_info *data)
{
	int i;
	sprite_type type;

	data->images.sprites = ft_calloc(NUMBERS_SPRITE, sizeof(t_img ****));
	if (!data->images.sprites)
		ft_error("Error reservando memoria para el primer nivel");
	data->images.spritesheet = ft_calloc(NUMBERS_SPRITE, sizeof(t_img **));
	if (!data->images.spritesheet)
	{
		free(data->images.sprites); // Free the first level
		ft_error("Error allocating memory for the second level");
	}
	i = 0;
	while (i < NUMBERS_SPRITE)
	{
		type = i;
		ft_allocate_single_sprite(&data->images.sprites[i], data, type);
		i++;
	}
	if (data->images.sprites) {
		init_sprites(data);
	}
}

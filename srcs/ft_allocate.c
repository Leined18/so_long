// Allocation of memory for the sprites
#include "so_long.h"

static void	init_img(t_info *data, sprite_type sprite)
{

	data->images.img[sprite] = ft_calloc(1, sizeof(t_img));
	if (!data->images.img[sprite])
		ft_error("Error allocating memory");
	data->images.spritesheet_img[sprite] = ft_calloc(1, sizeof(t_img));
	if (!data->images.spritesheet_img[sprite])
		ft_error("Error allocating memory");
	data->images.spritesheet_img[sprite]->addr = NULL;
	data->images.spritesheet_img[sprite]->img = NULL;
	data->images.spritesheet_img[sprite]->width = 0;
	data->images.spritesheet_img[sprite]->height = 0;
	data->images.spritesheet_img[sprite]->bits_per_pixel = 0;
	data->images.spritesheet_img[sprite]->line_length = 0;
	data->images.spritesheet_img[sprite]->endian = 0;
	data->images.img[sprite]->addr = NULL;
	data->images.img[sprite]->img = NULL;
	data->images.img[sprite]->width = 0;
	data->images.img[sprite]->height = 0;
	data->images.img[sprite]->bits_per_pixel = 0;
	data->images.img[sprite]->line_length = 0;
	data->images.img[sprite]->endian = 0;
}

void	ft_allocate_sprites(t_info *data)
{
	int r[NUMBERS_SPRITE];
	int c[NUMBERS_SPRITE];
	int i;
	int sp;

	i = -1;
	while (++i < NUMBERS_SPRITE)
	{
		r[i] = data->spritesheetInfo.rows[i];
		c[i] = data->spritesheetInfo.frames[i];
	}
	data->images.sprites = ft_calloc(NUMBERS_SPRITE, sizeof(void ***));
	sp = -1;
	while (++sp < NUMBERS_SPRITE)
	{
		data->images.sprites[sp] = ft_calloc(r[sp], sizeof(void **));
		i = -1;
		while (++i < r[sp])
			data->images.sprites[sp][i] = ft_calloc(c[sp], sizeof(void *));
	}
	ft_successful("sprites allocated successfully");
	sp = -1;
	while (++sp < NUMBERS_SPRITE)
		init_img(data, sp);
}
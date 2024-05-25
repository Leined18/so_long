// Allocation of memory for the sprites
#include "so_long.h"


static void	init_img2(t_info *data, sprite_type sprite)
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

static void	init_img(t_img *img)
{
	img = ft_calloc(1, sizeof(t_img));
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->endian = 0;
	img->height = 0;
	img->img = NULL;
	img->line_length = 0;
	img->width = 0;
	img->next = NULL;
}

void	ft_allocate_sprites(t_info *data)
{
	sprite_type	sp;
	int frame;
	int rows;


	sp = -1;
	frame = -1;
	rows = -1;

	while (++sp < NUMBERS_SPRITE )
	{
		while (++rows < N_D)
		{
			while (++frame < N_FPD)
				data->images.sprites[sp][rows][frame] = ft_calloc(1, sizeof(t_img));
		}
	}

	sp = -1;
	while (++sp < NUMBERS_SPRITE)
		init_img2(data, sp);
}

/// aqui se inicializa una lista de imagenes que luego se añadira con lstaddback
void	list()
{
	t_img data_img;
	t_img new;
	t_img *head;
	init_img(&data_img);
	init_img(&new);
	head = &data_img;
	data_img.next = &new;

	head->next = &new;
	while (head != NULL)
	{
		printf("head: %p\n", head);
		head = head->next;
	}
}
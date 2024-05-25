// Allocation of memory for the sprites
#include "so_long.h"

static void init_img(t_img *img, int sp)
{
    img = ft_calloc(1, sizeof(t_img));
    img->addr = NULL;
    img->bits_per_pixel = 0;
    img->endian = 0;
    img->height = 0;
    img->img = NULL;
    img->line_length = 0;
    img->frameNumber = sp;
    img->width = 0;
    img->next = NULL;
}

void ft_allocate_sprites(t_info *data) {
    int sp;
    int img_index;

    
    img_index = -1;
    while (++img_index < NUMBERS_SPRITE) {
        sp = -1;
        data->images[img_index].spritesheet = ft_calloc(1, sizeof(t_img));
        while (++sp < 100)
            init_img(data->images[img_index].frames[sp], sp);
    }
}
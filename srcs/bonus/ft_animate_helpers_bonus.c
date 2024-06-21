#include "so_long_bonus.h"

void ft_animate(t_info *data, t_info2 *info2)
{
    static int delay = DELAY * 3;

    info2->anim->count++;
    if (info2->anim->count >= delay)
    {
        info2->anim->count = 0;
        info2->anim->frame++;
        if (data->img[info2->sprite]
            .frames[info2->direction][info2->anim->frame] == NULL)
            info2->anim->frame = 0;
    }
    data->img_ptr = data->img[info2->sprite]
        .frames[info2->direction][info2->anim->frame]->img;
    mlx_put_image_to_window(data->grafics.mlx,
        data->grafics.win, data->img_ptr, info2->x * RES, info2->y * RES);
}

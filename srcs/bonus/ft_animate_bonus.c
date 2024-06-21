#include "so_long_bonus.h"

void ft_animation(t_bonus *data)
{
    int y;
    int x;
    char tile;

    y = 0;
    while (data->info.grafics.map[y])
    {
        x = 0;
        while (data->info.grafics.map[y][x])
        {
            tile = data->info.grafics.map[y][x];
            if (tile == '0')
                mlx_put_image_to_window(data->info.grafics.mlx,
                    data->info.grafics.win, data->info.img[FIELD]
                    .frames[0][0]->img, x * RES, y * RES);
            else
                handle_tile(data, tile, x, y);
            x++;
        }
        y++;
    }
}

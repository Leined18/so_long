# include "so_long.h"

void ft_animate_sprites(sprite_type sprite , direction direction, t_info *data)
{
    int i;
    
    i = 0;
    while (data->has_changed == 1) // mientras el jugador se mueva
    {
        while (i < N_FPD)
        {
            mlx_clear_window(data->mlx, data->win);
            mlx_put_image_to_window(data->mlx, data->win, data->images.sprites[sprite][direction][i],
                data->px, data->py); // Utiliza las coordenadas XY especificadas
            usleep(DELAY);
            i++;
        }
        i = 0; // Reiniciar el índice para la animación continua
    }
}
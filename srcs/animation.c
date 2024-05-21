#include "so_long.h"

void *extract_frame(void *mlx, void *spritesheet, int x, int y, int width, int height);

void copy_pixels(char *src_data, char *dest_data, int x, int y, int width,
                int height, int size_line)
{
    int i;
    int j;
    int src_idx;
    int dest_idx;

    j = 0;
    while (j < height)
    {
        i = 0;
        while (i < width)
        {
            src_idx = ((y + j) * size_line) + ((x + i) * 4);
            dest_idx = ((j * width) + i) * 4;
            dest_data[dest_idx] = src_data[src_idx];
            dest_data[dest_idx + 1] = src_data[src_idx + 1];
            dest_data[dest_idx + 2] = src_data[src_idx + 2];
            dest_data[dest_idx + 3] = src_data[src_idx + 3];
            i++;
        }
        j++;
    }
}

void *extract_frame(void *mlx, void *spritesheet, int x, int y, int width, int height)
{
    void *sprite;
    int bpp;
    int size_line;
    int endian;
    char *data;
    char *sprite_data;

    data = mlx_get_data_addr(spritesheet, &bpp, &size_line, &endian);
    if (!data)
        ft_error("Error obteniendo data address del spritesheet");

    sprite = mlx_new_image(mlx, width, height);
    if (!sprite)
        ft_error("Error creando nueva imagen para el sprite");

    sprite_data = mlx_get_data_addr(sprite, &bpp, &size_line, &endian);
    if (!sprite_data)
        ft_error("Error obteniendo data address del sprite");

    copy_pixels(data, sprite_data, x, y, width, height, size_line);
    return (sprite);
}

void ft_animate_sprites(Sprites sprite , Direction direction, t_info *data)
{
    int i;
    
    i = 0;
    while (data->has_changed == 1) // mientras el jugador se mueva
    {
        while (i < N_FPD)
        {
            mlx_clear_window(data->mlx, data->win);
            mlx_put_image_to_window(data->mlx, data->win, data->images->sprites[sprite][direction][i],
                data->x, data->y); // Utiliza las coordenadas XY especificadas
            usleep(DELAY);
            i++;
        }
        i = 0; // Reiniciar el índice para la animación continua
    }
}

void put_frames(t_info *data, Sprites s ,int frame_width, int frame_height)
{
    int i;
    int j;

    i = 0;
    while (i < N_D)
    {
        j = 0;
        while (j < N_FPD)
        {
            data->images->sprites[s][i][j] = extract_frame(data->mlx, data->images->spritesheet[s],
                j * frame_width, i * frame_height, frame_width, frame_height);
            if (!data->images->sprites[s][i][j])
                ft_error("Error extrayendo frame");
            j++;
        }
        i++;
    }
}


void    ft_load_spritesheet(t_info *data, Sprites sprite, char *sheet_path)
{
    int img_width, img_height;

    data->images->spritesheet[sprite] = mlx_xpm_file_to_image(data->mlx, sheet_path, &img_width, &img_height);
    if (!data->images->spritesheet[sprite])
        ft_error("Error cargando el spritesheet");
    put_frames(data, sprite, F_W, F_H);
}

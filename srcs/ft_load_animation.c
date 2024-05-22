#include "so_long.h"

static void copy_pixels(char *src_data, char *dest_data, int x, int y, int width,
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

static void *extract_frame(void *mlx, void *spritesheet, int x, int y, int width, int height)
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

void put_frames(t_info *data, sprite_type s , int rows, int frames, int frame_width, int frame_height)
{
    int i;
    int j;

    i = 0;
    while (i < rows)
    {
        j = 0;
        while (j < frames)
        {
            data->images.sprites[s][i][j] = extract_frame(data->mlx, data->images.spritesheet[s],
                j * frame_width, i * frame_height, frame_width, frame_height);
            if (!data->images.sprites[s][i][j])
                ft_error("Error extrayendo frame");
            j++;
        }
        i++;
    }

}


void    ft_load_spritesheet(t_info *data, sprite_type sprite, char *spritesheet_path)
{
    int img_width;
    int img_height;

    data->images.spritesheet[sprite] = mlx_xpm_file_to_image(data->mlx, spritesheet_path, &img_width, &img_height);
    if (!data->images.spritesheet[sprite])
        ft_error("Error cargando el spritesheet");
    if (img_width != F_W * N_FPD || img_height != F_H * N_D)
        ft_error("Error en las dimensiones del spritesheet");
    if (sprite == PLAYER_SPRITE)
        put_frames(data, sprite, N_D, N_FPD, F_W, F_H);
    if (sprite == COLLECT_SPRITE)
        put_frames(data, sprite, 1, 4, F_W, F_H);
    if (sprite == FIELD_SPRITE)
        put_frames(data, sprite, 4, 1 ,F_W, F_H);
    if (sprite == EXIT_SPRITE)
        put_frames(data, sprite, 1, 4, F_W, F_H);
}

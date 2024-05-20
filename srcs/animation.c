// Description: Este archivo contiene la función animate_sprites que se encarga de animar un sprite en una ventana de mlx.
#include "so_long.h"

void animate_sprites(void *mlx, void *win, void **sprites, int sprite_count, int delay)
{
    int i = 0;
    while (1)
    {
        mlx_clear_window(mlx, win);
        mlx_put_image_to_window(mlx, win, sprites[i], 100, 100);
        usleep(delay);
        i = (i + 1) % sprite_count;
    }
}

int main()
{
    void *mlx;
    void *win;
    void *sprites[4];
    int img_width, img_height;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "My Game");

    sprites[0] = mlx_xpm_file_to_image(mlx, PLAYER_RIGHT, &img_width, &img_height);
    sprites[1] = mlx_xpm_file_to_image(mlx, PLAYER_UP, &img_width, &img_height);
    sprites[2] = mlx_xpm_file_to_image(mlx, PLAYER_LEFT, &img_width, &img_height);
    sprites[3] = mlx_xpm_file_to_image(mlx, PLAYER_DOWN, &img_width, &img_height);
    // Añade más sprites según sea necesario

    animate_sprites(mlx, win, sprites, 4, DELAY); // 100000 microsegundos = 0.1 segundos

    mlx_loop(mlx);

    return 0;
}
#include "so_long_bonus.h"

static void set_player_direction(t_bonus *data)
{
    if (data->info.player.direction == 'N')
        data->info_bonus.direction = N;
    else if (data->info.player.direction == 'S')
        data->info_bonus.direction = S;
    else if (data->info.player.direction == 'E')
        data->info_bonus.direction = E;
    else if (data->info.player.direction == 'W')
        data->info_bonus.direction = W;
}

static void put_stand_player_img(t_bonus *data, int x, int y)
{
    data->info_bonus.anim = &data->info_bonus.player_anim;
    set_player_direction(data);
    data->info_bonus.sprite = PLAYER;
    ft_animate(&data->info, &data->info_bonus);
    data->info.player.x = x;
    data->info.player.y = y;
}

static void set_anim_params(t_bonus *data, char tile)
{
    if (tile == 'C')
    {
        data->info_bonus.sprite = COLLECT;
        data->info_bonus.anim = &data->info_bonus.collect_anim;
    }
    else if (tile == '1')
    {
        data->info_bonus.sprite = WALL;
        data->info_bonus.anim = &data->info_bonus.wall_anim;
    }
    else if (tile == 'E')
    {
        data->info_bonus.sprite = EXIT;
        data->info_bonus.anim = &data->info_bonus.exit_anim;
    }
    else if (tile == 'X')
    {
        data->info_bonus.sprite = ENEMY;
        data->info_bonus.anim = &data->info_bonus.enemy_anim;
    }
}

void handle_tile(t_bonus *data, char tile, int x, int y)
{
    data->info_bonus.x = x;
    data->info_bonus.y = y;
    if (tile == 'P')
        put_stand_player_img(data, x, y);
    else if (tile != '0')
    {
        set_anim_params(data, tile);
        ft_animate(&data->info, &data->info_bonus);
    }
}

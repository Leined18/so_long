/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:14:42 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/12 12:28:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void ft_animate(t_info *data, t_info2 *info2)
{
    int delay;

    delay = DELAY * 3;
    info2->anim->count++;
    if (info2->anim->count >= delay)
    {
        info2->anim->count = 0;
        info2->anim->frame++;
        if (data->img[info2->sprite].frames[info2->direction][info2->anim->frame] == NULL)
            info2->anim->frame = 0;
    }
    data->img_ptr = data->img[info2->sprite].frames[info2->direction][info2->anim->frame]->img;
    mlx_put_image_to_window(data->grafics.mlx, data->grafics.win, data->img_ptr, info2->x * RES, info2->y * RES);
}

static void put_stand_player_img(t_bonus *data, int x, int y)
{
    data->info_bonus.x = x;
    data->info_bonus.y = y;
    data->info_bonus.anim = &data->info_bonus.player_anim;

    if (data->info.player.direction == 'N')
        data->info_bonus.direction = N;
    else if (data->info.player.direction == 'S')
        data->info_bonus.direction = S;
    else if (data->info.player.direction == 'E')
        data->info_bonus.direction = E;
    else if (data->info.player.direction == 'W')
        data->info_bonus.direction = W;

    data->info_bonus.sprite = PLAYER;
    ft_animate(&data->info, &data->info_bonus);
    data->info.player.x = x;
    data->info.player.y = y;
}

static void handle_tile(t_bonus *data, char tile, int x, int y)
{
    data->info_bonus.x = x;
    data->info_bonus.y = y;
    switch (tile)
    {
        case 'P':
            put_stand_player_img(data, x, y);
            break;
        case 'C':
            data->info_bonus.sprite = COLLECT;
            data->info_bonus.anim = &data->info_bonus.collect_anim;
            ft_animate(&data->info, &data->info_bonus);
            break;
        case '1':
            data->info_bonus.sprite = WALL;
            data->info_bonus.anim = &data->info_bonus.wall_anim;
            ft_animate(&data->info, &data->info_bonus);
            break;
        case 'E':
            data->info_bonus.sprite = EXIT;
            data->info_bonus.anim = &data->info_bonus.exit_anim;
            ft_animate(&data->info, &data->info_bonus);
            break;
    }
}

static void process_row(t_bonus *data, int y)
{
    int x = 0;
    while (data->info.grafics.map[y][x])
    {
        char tile = data->info.grafics.map[y][x];
        handle_tile(data, tile, x, y);
        x++;
    }
}

void ft_animation(t_bonus *data)
{
    int y = 0;
    while (data->info.grafics.map[y])
    {
        process_row(data, y);
		data->info_bonus.direction = 0;
        y++;
    }
}

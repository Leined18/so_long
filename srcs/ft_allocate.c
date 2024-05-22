# include "so_long.h"

void    allocate_single_sprite(void ****sprite, t_info *temp)
{
    int j;
    
    *sprite = malloc(temp->spritesheetInfo.rows * sizeof(void *));
    if (!*sprite)
        ft_error("Error reservando memoria para el segundo nivel");
    j = 0;
    while (j < temp->spritesheetInfo.rows)
    {
        (*sprite)[j] = malloc(temp->spritesheetInfo.frames * sizeof(void *));
        if (!(*sprite)[j])
            ft_error("Error reservando memoria para el tercer nivel");
        j++;
    }
}

void    ft_allocate_sprites(void *****sprite, void ***spritesheet, t_info *data)
{
    int i;
    t_info *temp = data;

    *sprite = malloc(NUMBERS_SPRITE * sizeof(void **));
    if (!*sprite)
        ft_error("Error reservando memoria para el primer nivel");
    *spritesheet = malloc(NUMBERS_SPRITE * sizeof(void *));
    if (!*spritesheet)
        ft_error("Error reservando memoria para spritesheet");
    i = 0;
    while (i < NUMBERS_SPRITE)
    {
        allocate_single_sprite(&(*sprite)[i], temp);
        i++;
        temp = temp->next;
    }
}
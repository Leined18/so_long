#include "so_long.h"

void free_info(t_info *data) {
    // Liberar la memoria de los campos de la estructura t_info aquí
    free(data->images->p_up);
    free(data->images->p_down);
    free(data->images->p_right);
    free(data->images->p_left);
    free(data->images->wall);
    free(data->images->empty);
    free(data->images->exit);
    free(data->images->collect);
    free(data->images->winner);
    free(data->images);
    // Finalmente, liberar la memoria de la estructura en sí
    free(data);
}

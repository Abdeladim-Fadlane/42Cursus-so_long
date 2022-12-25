/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:56:59 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/24 17:00:36 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
void    destroy_win(t_object *object)
{
    mlx_destroy_window(object->mlx, object->win);
    exit(1);
}
void erase_player(t_object *object)
{
    int img_w;
    int img_h;
    object->ptr = mlx_xpm_file_to_image(object->mlx, "./textures/bg.xpm", &img_w, &img_h);
    mlx_put_image_to_window(object->mlx, object->win, object->ptr, object->player.x * 40, object->player.y * 40);
}

void put_player(t_object *object)
{
    int img_w;
    int img_h;
    object->ptr = mlx_xpm_file_to_image(object->mlx, object->imgpath, &img_w, &img_h);
    mlx_put_image_to_window(object->mlx, object->win, object->ptr, object->player.x * 40, object->player.y * 40);
}
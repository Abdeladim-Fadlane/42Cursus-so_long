/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:57:45 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/21 21:42:35 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
void    ft_right(t_object *object)
{
    int		img_w;
	int		img_h;
   

    if (object->map[object->player.y][object->player.x+1]!= '1')
    {
        if(object->map[object->player.y ][object->player.x+1] == '0' || object->map[object->player.y ][object->player.x+1] == 'P')
        {
            object->ptr = mlx_xpm_file_to_image(object->mlx, "./textures/bg.xpm", &img_w, &img_h);
            mlx_put_image_to_window(object->mlx, object->win, object->ptr, object->player.x * 40, object->player.y * 40);

            object->player.x++;

            object->ptr = mlx_xpm_file_to_image(object->mlx, "./textures/player.xpm", &img_w, &img_h);
            mlx_put_image_to_window(object->mlx, object->win, object->ptr, object->player.x * 40, object->player.y * 40);

            object->map[object->player.y][object->player.x+1] = '0';
        }
    }
}
void    ft_left(t_object *object)
{
    int		img_w;
	int		img_h;
   
     if (object->map[object->player.y][object->player.x-1]!= '1')
    {
        if(object->map[object->player.y ][object->player.x-1] == '0' || object->map[object->player.y ][object->player.x+1] == 'P')
        {
            object->ptr = mlx_xpm_file_to_image(object->mlx, "./textures/bg.xpm", &img_w, &img_h);
            mlx_put_image_to_window(object->mlx, object->win, object->ptr, object->player.x *40, object->player.y * 40);

            object->player.x--;

            object->ptr = mlx_xpm_file_to_image(object->mlx, "./textures/playerleft.xpm", &img_w, &img_h);
            mlx_put_image_to_window(object->mlx, object->win, object->ptr, object->player.x * 40, object->player.y * 40);

            object->map[object->player.y][object->player.x-1] = '0';
        }
    }
}
void    ft_up(t_object *object)
{
    int		img_w;
	int		img_h;
   
    if (object->map[object->player.y+1][object->player.x]!= '1')
    {
        if(object->map[object->player.y +1][object->player.x] == '0' || object->map[object->player.y][object->player.x] == 'P')
        {
            object->ptr = mlx_xpm_file_to_image(object->mlx, "./textures/bg.xpm", &img_w, &img_h);
            mlx_put_image_to_window(object->mlx, object->win, object->ptr, object->player.x * 40, object->player.y * 40);

            object->player.y++;

            object->ptr = mlx_xpm_file_to_image(object->mlx, "./textures/player.xpm", &img_w, &img_h);
            mlx_put_image_to_window(object->mlx, object->win, object->ptr, object->player.x * 40, object->player.y * 40);

            object->map[object->player.y + 1][object->player.x] = '0';
        }
    }
    
}
void    ft_down(t_object *object)
{
    int		img_w;
	int		img_h;
   
    if (object->map[object->player.y-1][object->player.x]!= '1')
    {
        if(object->map[object->player.y-1][object->player.x] == '0' || object->map[object->player.y +1][object->player.x] == 'P')
        {
            object->ptr = mlx_xpm_file_to_image(object->mlx, "./textures/bg.xpm", &img_w, &img_h);
            mlx_put_image_to_window(object->mlx, object->win, object->ptr, object->player.x *40, object->player.y * 40);

            object->player.y--;

            object->ptr = mlx_xpm_file_to_image(object->mlx, "./textures/player.xpm", &img_w, &img_h);
            mlx_put_image_to_window(object->mlx, object->win, object->ptr, object->player.x * 40, object->player.y * 40);

            object->map[object->player.y -1][object->player.x] = '0';
        }
    }
    
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:56:59 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/26 11:57:17 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	myfunc(t_object *object)
{
	erase_player(object);
	put_player(object);
	--object->coins;
	ft_printf("You move : %d steps\n", ++object->player.move);
	object->map[object->player.y][object->player.x] = 'P';
}

void	myfunction(t_object *object)
{
	put_player(object);
	ft_printf("You move : %d steps\n", ++object->player.move);
	object->map[object->player.y][object->player.x] = 'P';
}

void	destroy_win(t_object *object)
{
	mlx_destroy_window(object->mlx, object->win);
	exit(1);
}

void	erase_player(t_object *object)
{
	int	img_w;
	int	img_h;

	object->ptr = mlx_xpm_file_to_image(object->mlx,
			"./textures/bg.xpm", &img_w, &img_h);
	mlx_put_image_to_window(object->mlx, object->win, object->ptr,
		object->player.x * 40, object->player.y * 40);
}

void	put_player(t_object *object)
{
	int	img_w;
	int	img_h;

	object->ptr = mlx_xpm_file_to_image(object->mlx,
			object->imgpath, &img_w, &img_h);
	mlx_put_image_to_window(object->mlx, object->win, object->ptr,
		object->player.x * 40, object->player.y * 40);
}

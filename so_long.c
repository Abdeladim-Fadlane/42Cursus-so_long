/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:31:46 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/02 14:50:47 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static	int	key_hook(int keycode, t_object *object)
{
	if (keycode == 2 || keycode == 124)
		ft_right(object);
	else if (keycode == 0 || keycode == 123)
		ft_left(object);
	else if (keycode == 13 || keycode == 126)
		ft_up(object);
	else if (keycode == 1 || keycode == 125)
		ft_down(object);
	if (keycode == 53)
	{
		mlx_destroy_window(object->mlx, object->win);
		exit(1);
	}
	return (0);
}

static	void	put_img(t_object *image, int i, int j)
{
	if (image->map[i][j] == '1')
		image->imgpath = "./textures/wall.xpm";
	else if (image->map[i][j] == '0' )
		image->imgpath = "./textures/bg.xpm";
	else if (image->map[i][j] == 'C')
		image->imgpath = "./textures/collection.xpm";
	else if (image->map[i][j] == 'P')
	{
		image->imgpath = "./textures/player.xpm";
		image->player.y = i;
		image->player.x = j;
	}
	else if (image->map[i][j] == 'E')
		image->imgpath = "./textures/door.xpm";
	if (image->map[i][j] == 'E' || image->map[i][j] == 'P' ||
		image->map[i][j] == 'C')
	{
		image->ptr = mlx_xpm_file_to_image(image->mlx, "./textures/bg.xpm",
				&image->player.img_height, &image->player.img_height);
		mlx_put_image_to_window(image->mlx, image->win,
			image->ptr, image->x, image->y);
	}
	add_floor(image);
}

static	void	putimage(t_object *image)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	image->x = 0;
	image->y = 0;
	while (image->map[i])
	{
		image->x = 0;
		j = 0;
		while (image->map[i][j])
		{
			put_img(image, i, j);
			image->x += 40;
			j++;
		}
		i++;
		image->y += 40;
	}
}

int	main(int ac, char **av)
{
	t_object	object;
	t_struct	map;

	if (ac <= 1)
	{
		perror("Error");
		exit(0);
	}
	check_path(av[1]);
	map.map = get_map(av[1]);
	object.map = get_map(av[1]);
	initialize(&object);
	floodfill(&map);
	if (object.map != NULL)
	{
		object.mlx = mlx_init();
		object.win = mlx_new_window(object.mlx, object.win_w * 40,
				object.win_h * 40, "So-Long");
		putimage(&object);
		mlx_hook(object.win, 2, 0, key_hook, &object);
		mlx_hook(object.win, 17, 0, ft_close, &object);
		mlx_loop(object.mlx);
	}
}

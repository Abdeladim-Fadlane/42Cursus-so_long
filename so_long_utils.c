/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:13:48 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/29 13:58:17 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_close(t_object *object)
{
	mlx_destroy_window(object->mlx, object->win);
	exit(1);
}

void	initialize(t_object *object)
{
	checkelement(object->map, object);
	check_map(object->map);
	object->win_w = ft_strlen(object->map[0]);
	object->win_h = get_lenght(object->map);
}

char	**get_map(char *buff)
{
	char	*line;
	char	*all_lines;
	int		fd;

	fd = open(buff, O_RDONLY);
	if (fd < 0)
	{
		perror("invalid fd !");
		exit(1);
	}
	line = "";
	all_lines = ft_strdup("");
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	free(line);
	return (ft_split(all_lines, '\n'));
}

int	get_lenght(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	add_floor(t_object *image)
{
	image->ptr = mlx_xpm_file_to_image(image->mlx, image->imgpath,
			&image->player.img_width, &image->player.img_height);
	mlx_put_image_to_window(image->mlx, image->win, image->ptr,
		image->x, image->y);
}

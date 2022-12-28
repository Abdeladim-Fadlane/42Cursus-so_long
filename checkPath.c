/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkPath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:50:15 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/28 17:36:05 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

static	void	get_position(t_struct *object)
{
	int	x;
	int	y;

	x = 0;
	while (object->map[x])
	{
		y = 0;
		while (object->map[x][y])
		{
			if (object->map[x][y] == 'P')
			{
				object->x = x;
				object->y = y;
			}
			y++;
		}
		x++;
	}
}

static	void	check_exit(t_struct *object, int x, int y)
{
	if (y < 0 || y >= object->win_y || x < 0 || x >= object->win_x
		|| object->map[x][y] == 'E' || object->map[x][y] == '1')
		return ;
	object->map[x][y] = '*';
	check_exit(object, x - 1, y);
	check_exit(object, x + 1, y);
	check_exit(object, x, y - 1);
	check_exit(object, x, y + 1);
}

static	void	check_coins(t_struct *object, int x, int y)
{
	if (y < 0 || y >= object->win_y || x < 0 || x >= object->win_x
		|| object->map[x][y] == '1')
		return ;
	object->map[x][y] = '1';
	check_coins(object, x - 1, y);
	check_coins(object, x + 1, y);
	check_coins(object, x, y - 1);
	check_coins(object, x, y + 1);
}

void	floodfill(t_struct *map)
{
	int	j;
	int	i;

	i = 0;
	get_position(map);
	map->win_y = ft_strlen(map->map[0]);
	map->win_x = get_lenght(map->map);
	check_coins(map, map->x, map->y);
	check_exit(map, map->x, map->y);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C' || map->map[i][j] == 'E')
			{
				ft_printf("invalid map");
				exit(0);
			}
			j++;
		}
		i++;
	}
	return ;
}

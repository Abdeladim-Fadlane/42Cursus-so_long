/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:57:45 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/26 11:40:28 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_right(t_object *object)
{
	object->imgpath = "./textures/player.xpm";
	if (object->map[object->player.y][object->player.x + 1]
		== 'E' && object->coins == 0)
		destroy_win(object);
	else if (object->map[object->player.y][object->player.x + 1] != '1')
	{
		if (object->map[object->player.y][object->player.x + 1] == '0' ||
			object->map[object->player.y][object->player.x + 1] == 'P')
		{
			erase_player(object);
			object->player.x++;
			myfunction(object);
			object->map[object->player.y][object->player.x - 1] = '0';
		}
		else if (object->map[object->player.y][object->player.x + 1] == 'C')
		{
			erase_player(object);
			object->player.x++;
			myfunc(object);
			object->map[object->player.y][object->player.x - 1] = '0';
		}
	}
}

void	ft_left(t_object *object)
{
	object->imgpath = "./textures/playerleft.xpm";
	if (object->map[object->player.y][object->player.x - 1]
		== 'E' && object->coins == 0)
		destroy_win(object);
	else if (object->map[object->player.y][object->player.x - 1] != '1')
	{
		if (object->map[object->player.y][object->player.x - 1] == '0' ||
			object->map[object->player.y][object->player.x - 1] == 'P')
		{
			erase_player(object);
			object->player.x--;
			myfunction(object);
			object->map[object->player.y][object->player.x + 1] = '0';
		}
		else if (object->map[object->player.y][object->player.x - 1] == 'C' )
		{
			erase_player(object);
			object->player.x--;
			myfunc(object);
			object->map[object->player.y][object->player.x + 1] = '0';
		}
	}
}

void	ft_up(t_object *object)
{
	object->imgpath = "./textures/player.xpm";
	if (object->map[object->player.y - 1][object->player.x]
		== 'E' && object->coins == 0)
		destroy_win(object);
	else if (object->map[object->player.y - 1][object->player.x] != '1')
	{
		if (object->map[object->player.y - 1][object->player.x] == '0' ||
			object->map[object->player.y - 1][object->player.x] == 'P')
		{
			erase_player(object);
			object->player.y--;
			myfunction(object);
			object->map[object->player.y + 1][object->player.x] = '0';
		}
		else if (object->map[object->player.y - 1][object->player.x] == 'C' )
		{
			erase_player(object);
			object->player.y--;
			myfunc(object);
			object->map[object->player.y + 1][object->player.x] = '0';
		}
	}
}

void	ft_down(t_object *object)
{
	object->imgpath = "./textures/player.xpm";
	if (object->map[object->player.y + 1][object->player.x]
		== 'E' && object->coins == 0)
		destroy_win(object);
	else if (object->map[object->player.y + 1][object->player.x] != '1')
	{
		if (object->map[object->player.y + 1][object->player.x] == '0' ||
			object->map[object->player.y + 1][object->player.x] == 'P')
		{
			erase_player(object);
			object->player.y++;
			myfunction(object);
			object->map[object->player.y - 1][object->player.x] = '0';
		}
		else if (object->map[object->player.y + 1][object->player.x] == 'C')
		{
			erase_player(object);
			object->player.y++;
			myfunc(object);
			object->map[object->player.y - 1][object->player.x] = '0';
		}
	}
}

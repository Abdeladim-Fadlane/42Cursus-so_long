/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:57:45 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/25 12:04:28 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void ft_right(t_object *object)
{
    object->imgpath ="./textures/player.xpm";
    if (object->map[object->player.y][object->player.x + 1] == 'E' && object->coins == 0)
        destroy_win(object);
    else if (object->map[object->player.y][object->player.x+1] != '1')
    {
        if(object->map[object->player.y][object->player.x + 1] == '0' || 
             object->map[object->player.y ][object->player.x + 1] == 'P')
        {
            erase_player(object);
            object->player.x++;
            put_player(object);
            object->map[object->player.y][object->player.x] = 'P';
            object->map[object->player.y][object->player.x - 1] = '0';
            printf("You move : %d steps\n",++object->player.move); 
        }
        else if(object->map[object->player.y][object->player.x + 1] == 'C')
        {
            erase_player(object);
            object->player.x++;
            erase_player(object);
            put_player(object);
            --object->coins;
            object->map[object->player.y][object->player.x] = 'P';
            object->map[object->player.y][object->player.x - 1] = '0';
            printf("You move : %d steps\n",++object->player.move);
        } 
    }
}

void    ft_left(t_object *object)
{
    object->imgpath ="./textures/playerleft.xpm";
    if (object->map[object->player.y][object->player.x - 1] == 'E' && object->coins == 0)
        destroy_win(object);
    else if (object->map[object->player.y][object->player.x - 1] != '1')
    {
        if(object->map[object->player.y ][object->player.x - 1] == '0' || 
            object->map[object->player.y ][object->player.x - 1] == 'P')
        {
            erase_player(object);
            object->player.x--;
            put_player(object);
            object->map[object->player.y][object->player.x] = 'P';
            object->map[object->player.y][object->player.x + 1] = '0';
            printf("You move : %d steps\n",++object->player.move);
        }
        else if (object->map[object->player.y][object->player.x - 1] == 'C' )
        {
            erase_player(object);
            object->player.x--;
            erase_player(object);
            put_player(object);
            --object->coins;
            object->map[object->player.y][object->player.x] = 'P';
            object->map[object->player.y][object->player.x + 1] = '0';
            printf("You move : %d steps\n",++object->player.move);
        }
    }
}

void    ft_up(t_object *object)
{
    object->imgpath ="./textures/player.xpm";
   
    if (object->map[object->player.y - 1][object->player.x ] == 'E' && object->coins == 0)
        destroy_win(object);
    else if (object->map[object->player.y- 1][object->player.x] != '1')
    {
        if(object->map[object->player.y - 1][object->player.x] == '0' || 
            object->map[object->player.y - 1][object->player.x ] == 'P')
        {
            erase_player(object);
            object->player.y--;
            put_player(object);
            object->map[object->player.y][object->player.x] = 'P';
            object->map[object->player.y + 1][object->player.x ] = '0';
            printf("You move : %d steps\n",++object->player.move);
        }
        else if (object->map[object->player.y- 1][object->player.x] == 'C' )
        {
            erase_player(object);
            object->player.y--;
            erase_player(object);
            put_player(object);
            --object->coins;
            object->map[object->player.y][object->player.x] = 'P';
            object->map[object->player.y + 1][object->player.x] = '0';
            printf("You move : %d steps\n",++object->player.move);
        }
       
    }
}
void    ft_down(t_object *object)
{
    object->imgpath ="./textures/player.xpm";
  
    if (object->map[object->player.y + 1][object->player.x ] == 'E'&& object->coins == 0)
        destroy_win(object);
    else if (object->map[object->player.y + 1][object->player.x] != '1')
    {
        if(object->map[object->player.y + 1][object->player.x] == '0' || 
             object->map[object->player.y + 1][object->player.x] == 'P')
        {
            erase_player(object);
            object->player.y++;
            put_player(object);
            object->map[object->player.y][object->player.x] = 'P';
            object->map[object->player.y - 1][object->player.x ] = '0';
            printf("You move : %d steps\n",++object->player.move);
        }
        else if (object->map[object->player.y+1][object->player.x ] == 'C')
        {
            erase_player(object);
            object->player.y++;
            erase_player(object);
            put_player(object);
            --object->coins;
            object->map[object->player.y][object->player.x] = 'P';
            object->map[object->player.y - 1][object->player.x ] = '0';
            printf("You move : %d steps\n",++object->player.move);
        }
       
    }
}


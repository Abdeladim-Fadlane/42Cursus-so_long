/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:34:52 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/24 17:00:47 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include<string.h> 
#include "get_next_line.h"
#include <mlx.h>

typedef struct player
{
    int x;
    int y;
	int move;
	
} t_player;

typedef struct object {

	int 			win_w;
	int 			win_h;
	void			*mlx;
	void			*win;
	int				x;
	int				y;
	char			*imgpath;
	void			 *ptr;
	char			**map;
	int coins;
	t_player player;
}t_object;



char	**ft_split(char *s, char c);
char	*get_next_line(int fd);
void    check_map(char **av);
void	check_path(char *file_line);
void 	check_map(char **av);
void 	checkElement(char **arr,t_object *coin);
void	ft_right(t_object *object);
void    ft_left(t_object *object);
void    ft_up(t_object *object);
void    ft_down(t_object *object);
void put_player(t_object *object);
void erase_player(t_object *object);
void    destroy_win(t_object *object);
#endif
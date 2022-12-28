/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:34:52 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/28 17:42:49 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include<string.h> 
# include "get_next_line.h"
# include <mlx.h>
# include "ft_printf.h"

typedef struct player
{
	int			img_width;
	int			img_height;
	int			x;
	int			y;
	int			move;

}	t_player;

typedef struct object
{
	int				win_w;
	int				win_h;
	void			*mlx;	
	void			*win;
	int				x;
	int				y;
	char			*imgpath;	
	void			*ptr;
	char			**map;
	int				coins;
	t_player		player;

}	t_object;

typedef struct path
{
	int		x;
	int		y;
	int		win_y;
	int		win_x;
	char	**map;

}	t_struct;

char	**ft_split(char *s, char c);
char	*get_next_line(int fd);
void	check_map(char **av);
void	check_path(char *file_line);
void	check_map(char **av);
void	checkelement(char **arr, t_object *coin);
void	ft_right(t_object *object);
void	ft_left(t_object *object);
void	ft_up(t_object *object);
void	ft_down(t_object *object);
void	put_player(t_object *object);
void	erase_player(t_object *object);
void	destroy_win(t_object *object);
void	floodfill(t_struct *map);
char	**get_map(char *buff);		
void	add_floor(t_object *image);
int		get_lenght(char **map);
int		ft_printf(const char *s, ...);
void	myfunction(t_object *object);
void	myfunc(t_object *object);
#endif
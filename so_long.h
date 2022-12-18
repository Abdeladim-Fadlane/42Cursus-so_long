/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:34:52 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/18 13:38:33 by afadlane         ###   ########.fr       */
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
typedef struct object {
    int		img_width ;
    int		img_height ;
	void			*mlx;
    void			*img;
	void			*win;
	int				x;
	int				y;
	char			**map;
}t_object;
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
void    check_map(char **av);
void	check_path(char *file_line);
#endif
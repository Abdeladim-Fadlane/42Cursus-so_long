/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:31:46 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/18 14:57:37 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"so_long.h"

static char	**get_map(char *buff);
void    putImage(t_object image);

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int main(int ac ,char **av)
{
    (void)av;
    t_object object;
    if(ac <= 1)
    { 
        perror("\033[1;31mERROR \033[0m");
        exit(0);
    }
    check_path(av[1]);
    object.map = get_map(av[1]); 

    int win_w = strlen(object.map[0]);
    int win_h = get_height(object.map);
    if(object.map != NULL)
    {
		object.mlx = mlx_init();
		object.win = mlx_new_window(object.mlx,win_w * 50, win_h * 50,"So-Long");
        putImage(object);
    }
    mlx_loop(object.mlx);
}
void    putImage(t_object image)
{
    int x = 0;
    int y = 0;
    int img_height;
    int img_width;
    int i = 0;
    int j = 0;
    while(image.map[i])
    { 
        x = 0;
        j = 0;
        while(image.map[i][j])
        {
            if(image.map[i][j] == '1')
            {
                void *wall = mlx_xpm_file_to_image(image.mlx, "./textures/wall.xpm", &img_width,&img_height);
                mlx_put_image_to_window(image.mlx, image.win, wall,x,y);
            }
            else if(image.map[i][j] == '0' )
            {
                void *img = mlx_xpm_file_to_image(image.mlx, "./textures/bg.xpm",&img_width,&img_height); 
                mlx_put_image_to_window(image.mlx, image.win, img, x, y);
            }
            else if(image.map[i][j] == 'C')
            {
                void *img = mlx_xpm_file_to_image(image.mlx, "./textures/bg.xpm",&img_width,&img_height); 
                mlx_put_image_to_window(image.mlx, image.win, img, x, y);
                void *coll = mlx_xpm_file_to_image(image.mlx, "./textures/collection.xpm",&img_width,&img_height);
                mlx_put_image_to_window(image.mlx, image.win, coll, x,y);
            }
            else if(image.map[i][j] == 'P')
            {
                void *img = mlx_xpm_file_to_image(image.mlx, "./textures/bg.xpm",&img_width,&img_height); 
                mlx_put_image_to_window(image.mlx, image.win, img, x, y);
                void *player = mlx_xpm_file_to_image(image.mlx, "./textures/player.xpm", &img_width,&img_height);
                mlx_put_image_to_window(image.mlx, image.win, player, x,y);
            }
            else if(image.map[i][j] == 'E')
            {
                void *img = mlx_xpm_file_to_image(image.mlx, "./textures/bg.xpm",&img_width,&img_height); 
                mlx_put_image_to_window(image.mlx, image.win, img, x, y);
                void *exit = mlx_xpm_file_to_image(image.mlx, "./textures/door.xpm", &img_width,&img_height);
                mlx_put_image_to_window(image.mlx, image.win, exit, x,y);
            }
            x+=50;
            j++;
        }
        i++;
        y+= 50;
    } 
}
static char	**get_map(char *buff)
{
	char	*line;
	char	*all_lines;

    int fd = open(buff,O_RDONLY);
    if(fd < 0)
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
	close(fd);
	return (ft_split(all_lines, '\n'));
}
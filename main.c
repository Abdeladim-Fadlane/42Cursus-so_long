/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:20:18 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/20 17:52:07 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include<stdlib.h> 
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
   
      if (keycode == 53)  // check if the key pressed was the Esc key (keycode 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0); 
	    // close the window
       // exit the program
    }
	return (0); 
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
    
	mlx_loop(vars.mlx);
}

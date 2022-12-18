/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:47:15 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/18 13:20:20 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
static void checkIsValid(char **av)
{

}
static void check_wall(char **av)
{
	int i = 0, x = 0, y = 0;
	while (av[x])
	{
		while (av[x][y])
			y++;
		x++;
	}
	if(x >= y){perror("Error maps is not rectengle ! \n");}
	while(av[0][i] != '\0')
	{
		if(av[0][i] != '1')
		{
			perror("Error maps invalid you forget wall ! \n");
			break;
		}
		i++;
	}
	i = 0;
	while(av[x-1][i])
	{
		if(av[x-1][i] != '1')
		{
			perror("Error maps invalid you forget wall ! \n");
			break;
		}
		i++;
	}
	i = 1;
	while(av[i])
	{
		if(av[i][0] != '1')
		{
			perror("Error maps invalid you forget wall ! \n");
			break;
		}
		i++;
	}
	i = 0;
	while(av[i])
	{
		if(av[i][y-1] != '1')
		{
			perror("Error maps invalid you forget wall ! \n");
			break;
			exit(0);
		}
		i++;
	}
}
// void check_player(char **av)
// {
// 	int x = 0 ;
// 	int y = 0;
// 	while (av[x])
// 	{
// 		while (av[x][y])
// 			y++;
// 		x++;
// 	}
// 	int i = 0;
// 	while(av[i])
// 	{
// 		if(av[x ][y])
// 	}

// }
void check_map(char **av)
{
	check_wall(av);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:47:15 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/19 15:23:24 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static int check_wall1(char **av)
{
	int i = 0, x = 0, y = 0;
	while (av[x])
	{
		while (av[x][y])
			y++;
		x++;
	}
	if(x >= y)
		return 0;
	while(av[0][i] != '\0')
	{
		if(av[0][i] != '1')
			return (0);
		i++;
	}
	while(av[x-1][i])
	{
		if(av[x-1][i] != '1')
			return (0);
		i++;
	}
	return 1;
}
static int check_wall(char **av)
{
	int i = 0, x = 0, y = 0;
	while (av[x])
	{
		while (av[x][y])
			y++;
		x++;
	}
	
	i = 1;
	while(av[i])
	{
		if(av[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while(av[i])
	{
		if(av[i][y-1] != '1')
			return (0);
		i++;
	}
	return 1;
}


void check_map(char **av)
{
	int k = check_wall(av);
	int j = check_wall1(av);
	if(k && j )
		return ;
	printf("invalid map!");
	exit(1);
}
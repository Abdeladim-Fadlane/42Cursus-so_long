/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:47:15 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/29 13:45:52 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static	int	check_wall1(char **av, int x, int y)
{
	int	i;

	i = 0;
	if (x >= y)
	{
		ft_printf("Error invalid map!\nMap should be rectangle");
		exit(1);
	}
	while (av[0][i] != '\0')
	{
		if (av[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (av[x - 1][i])
	{
		if (av[x - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static	int	check_wall(char **av, int y)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (av[i])
	{
		if (av[i][y - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_map(char **av)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (av[x])
	{
		while (av[x][y])
			y++;
		x++;
	}
	if ((check_wall(av, y)) && (check_wall1(av, x, y)))
		return ;
	ft_printf("Error invalid map!\nckeck wall");
	exit(1);
}

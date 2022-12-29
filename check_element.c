/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkelement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:16:46 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/29 13:46:51 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	check_player(char **arr, int i, int j)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (x < i)
	{
		y = 0;
		while (y < j)
		{
			if (arr[x][y] == 'P')
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

int	check_exit(char **arr, int i, int j)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (x < i)
	{
		y = 0;
		while (y < j)
		{
			if (arr[x][y] == 'E')
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

static	int	check_collection(char **arr, int i, int j)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (x < i)
	{
		y = 0;
		while (y < j)
		{
			if (arr[x][y] == 'C')
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

static	int	check_antielement(char **arr, int i, int j)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < i)
	{
		y = 0;
		while (y < j)
		{
			if (arr[x][y] != 'C' && arr[x][y] != 'P' && arr[x][y] != 'E'
					&& arr[x][y] != '1' && arr[x][y] != '0')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	checkelement(char **arr, t_object *coin)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		while (arr[i][j])
			j++;
		i++;
	}
	if ((check_player(arr, i, j) != 1) || (check_exit(arr, i, j) != 1)
		|| (check_collection(arr, i, j) == 0)
		|| (check_antielement(arr, i, j) == 0))
	{
		ft_printf("Error invalid map!\nsomthing was wrong!");
		exit(1);
	}
	coin->coins = check_collection(arr, i, j);
	return ;
}

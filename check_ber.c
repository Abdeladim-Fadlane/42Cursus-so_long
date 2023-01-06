/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:23:33 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/02 14:52:04 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static int	find(char *str, char *find)
{
	int	i;

	i = 0;
	while (find[i])
	{
		if (find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	check_path(char *path)
{
	while (*path)
	{
		if (*path == '.')
		{
			if (find(path, ".ber"))
				return ;
		}
		path++;
	}
	perror("Error!");
	exit(1);
}

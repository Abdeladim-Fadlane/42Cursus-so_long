/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkPath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:23:33 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/18 14:57:15 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
static int	find(char *str, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] != str[i])
			return (0);
		i++;
	}
	if (str[i])
		return (1);
	return (0);
}
void	check_path(char *file_line)
{
	while (*file_line)
	{
		if (*file_line == '.')
		{
			if (find(file_line, ".ber"))
				return ;
		}
		file_line++;
	}
	printf("path is not valid");
	exit(1);
}
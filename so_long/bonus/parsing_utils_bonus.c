/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:53:55 by ynachat           #+#    #+#             */
/*   Updated: 2024/05/27 12:47:35 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_file_map(char *map_name)
{
	int		i;
	char	*ber;

	i = ft_strlen(map_name);
	ber = ".ber";
	if (i < 4 || ft_strcmp(map_name + i - 4, ber) != 0)
		print_error();
}

void	print_error(void)
{
	ft_putstr_fd("Error", 2);
	ft_putstr_fd("Invalid map!!", 2);
	exit(1);
}

void	check_last_line(t_vars *v, char *line)
{
	if (line[v->len - 1] == '\n')
		(free(line), print_error());
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == 'E' || map[y][x] == 'N')
		map[y][x] = '1';
	if (map[y][x] == '1' || map[y][x] == '.')
		return ;
	map[y][x] = '.';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	check_flood(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'C'
				|| map[i][j] == 'E' || map[i][j] == 'N')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

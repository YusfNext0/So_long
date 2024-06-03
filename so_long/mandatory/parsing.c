/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:56:00 by ynachat           #+#    #+#             */
/*   Updated: 2024/05/27 13:58:00 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_epc(char **map, t_vars *v)
{
	int	i;
	int	j;

	(1) && (i = -1, j = -1, v->e = 0, v->c = 0, v->p = 0,
		v->xp = 0, v->yp = 0, v->h = 0, v->w = ft_strlen(map[0]));
	while (map[++i])
	{
		v->re = ft_strlen(map[i]);
		if (v->re != v->w)
			return (0);
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
				&& map[i][j] != 'P' && map[i][j] != 'C')
				return (0);
			(map[i][j] == 'E') && (v->e++);
			(map[i][j] == 'P') && (v->p++, v->xp = j, v->yp = i);
			(map[i][j] == 'C') && (v->c++);
		}
		v->h++;
	}
	if (v->e != 1 || v->p != 1 || v->c < 1)
		return (0);
	return (1);
}

static int	check_valid_map(char **lmap, t_vars *v)
{
	int	i;

	(1) && (i = -1);
	while (lmap[0][++i])
	{
		if (lmap[0][i] != '1')
			return (0);
	}
	i = -1;
	while (lmap[++i])
	{
		if (lmap[i][0] != '1' || lmap[i][v->w - 1] != '1')
			return (0);
	}
	if (ft_strcmp(lmap[0], lmap[v->h - 1]) != 0)
		return (0);
	if (lmap[v->h - 1][v->w - 1] == '\n')
		return (0);
	return (1);
}

static char	**ft_dup_map(char **map)
{
	int		i;
	char	**new_map;

	i = 0;
	if (!map || !*map)
		return (NULL);
	while (map[i])
		i++;
	new_map = malloc((i + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map && map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
			(free_mat(new_map), free_mat(map), print_error());
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

static void	get_map_lines(char *name_map, t_vars *v)
{
	int		fd;
	char	*ptr;
	char	*line;

	(1) && (fd = 0, line = NULL, fd = open(name_map, O_RDONLY));
	if (fd == -1)
		print_error();
	ptr = get_next_line(fd);
	if (!ptr)
		print_error();
	while (ptr)
	{
		if (ptr[0] == '\n')
			(free(ptr), free(line), print_error());
		line = ft_strjoin(line, ptr);
		if (!line)
			(free(ptr), print_error());
		(1) && (free(ptr), ptr = get_next_line(fd));
	}
	(1) && (close(fd), v->len = ft_strlen(line));
	check_last_line(v, line);
	v->map = ft_split(line, '\n');
	if (!v->map)
		(free(line), print_error());
	free(line);
}

void	parsing(char *map_name, t_vars *v)
{
	char	**map_flood;

	v->nb_mov_p = 0;
	check_file_map(map_name);
	get_map_lines(map_name, v);
	if (count_epc(v->map, v) == 0)
		(free_mat(v->map), print_error());
	if (check_valid_map(v->map, v) == 0)
		(free_mat(v->map), print_error());
	map_flood = ft_dup_map(v->map);
	if (!map_flood)
		(free_mat(v->map), print_error());
	flood_fill(map_flood, v->xp, v->yp);
	if (check_flood(map_flood) == 0)
		(free_mat(v->map), free_mat(map_flood), print_error());
	free_mat(map_flood);
}

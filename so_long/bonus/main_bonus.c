/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:31:07 by ynachat           #+#    #+#             */
/*   Updated: 2024/06/02 18:14:48 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_exit(t_vars *v, int key)
{
	if ((!v->c) && ((key == 126 && v->up == 'E')
			|| (key == 125 && v->down == 'E')
			|| (key == 124 && v->right == 'E')
			|| (key == 123 && v->left == 'E')))
	{
		free_mat(v->map);
		mlx_clear_window(v->mlx, v->win);
		mlx_destroy_window(v->mlx, v->win);
		(write (1, "YOU WIN\n", 9), exit(0));
	}
	if ((key == 126 && v->up == 'N')
		|| (key == 125 && v->down == 'N')
		|| (key == 124 && v->right == 'N')
		|| (key == 123 && v->left == 'N'))
	{
		free_mat(v->map);
		mlx_clear_window(v->mlx, v->win);
		mlx_destroy_window(v->mlx, v->win);
		(write (1, "YOU LOSE !!!\n", 14), exit(0));
	}
}

static void	moving(t_vars *v, int key)
{
	char	*itoa;

	v->map[v->yp][v->xp] = '0';
	ft_put_img(v, WALL_BLACK, v->xp, v->yp);
	if (key == 126)
		ft_put_img(v, PACMAN_U, v->xp, --v->yp);
	else if (key == 125)
		ft_put_img(v, PACMAN_D, v->xp, ++v->yp);
	else if (key == 124)
		ft_put_img(v, PACMAN_R, ++v->xp, v->yp);
	else if (key == 123)
		ft_put_img(v, PACMAN_L, --v->xp, v->yp);
	if (v->map[v->yp][v->xp] == 'C')
		v->c--;
	v->map[v->yp][v->xp] = 'P';
	itoa = ft_itoa(++v->nb_mov_p);
	display_moves_win(v, itoa);
	free(itoa);
}

static int	moving_player(int key, t_vars *v)
{
	v->up = v->map[v->yp - 1][v->xp];
	v->down = v->map[v->yp + 1][v->xp];
	v->left = v->map[v->yp][v->xp - 1];
	v->right = v->map[v->yp][v->xp + 1];
	if (key == 53)
	{
		free_mat(v->map);
		mlx_clear_window(v->mlx, v->win);
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	if (key == 126 && !ft_strchr("1EN", v->up))
		moving(v, key);
	else if (key == 125 && !ft_strchr("1EN", v->down))
		moving(v, key);
	else if (key == 124 && !ft_strchr("1EN", v->right))
		moving(v, key);
	else if (key == 123 && !ft_strchr("1EN", v->left))
		moving(v, key);
	check_exit(v, key);
	return (1);
}

static int	display_map(t_vars *v)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (v->map[++i])
	{
		j = -1;
		while (v->map[i][++j])
		{
			if (v->map[i][j] == '1')
				ft_put_img(v, WALL, j, i);
			else if (v->map[i][j] == '0')
				ft_put_img(v, WALL_BLACK, j, i);
			else if (v->map[i][j] == 'P')
				ft_put_img(v, PACMAN_R, j, i);
			else if (v->map[i][j] == 'E')
				ft_put_img(v, DOOR, j, i);
			else if (v->map[i][j] == 'N')
				ft_put_img(v, GHOST_D, j, i);
		}
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	if (ac != 2)
		exit(1);
	parsing(av[1], &vars);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (free_mat(vars.map), free(vars.mlx), 0);
	vars.win = mlx_new_window(vars.mlx, vars.w * 32, vars.h * 32,
			"./so_long_bonus");
	if (!vars.win)
		return (free_mat(vars.map), free(vars.mlx), 0);
	check_xpm_files_2(&vars);
	display_map(&vars);
	mlx_string_put(vars.mlx, vars.win, 8, 5, 0xffffff, "0");
	mlx_loop_hook(vars.mlx, effects, &vars);
	mlx_hook(vars.win, 2, 0L, moving_player, &vars);
	mlx_hook(vars.win, 17, 0, close_cros, &vars);
	mlx_loop(vars.mlx);
}

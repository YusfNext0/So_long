/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:33:24 by ynachat           #+#    #+#             */
/*   Updated: 2024/06/02 18:24:51 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_cros(t_vars *v)
{
	free_mat(v->map);
	mlx_clear_window(v->mlx, v->win);
	mlx_destroy_window(v->mlx, v->win);
	exit(0);
}

void	display_moves_win(t_vars *v, char *itoa)
{
	if (!itoa)
	{
		free_mat(v->map);
		mlx_clear_window(v->mlx, v->win);
		mlx_destroy_window(v->mlx, v->win);
		exit(1);
	}
	mlx_string_put(v->mlx, v->win, 8, 5, 0xffffff, itoa);
	ft_put_img(v, WALL, 0, 0);
	ft_put_img(v, WALL, 1, 0);
	mlx_string_put(v->mlx, v->win, 8, 5, 0xffffff, itoa);
}

static void	check_xpm_files(t_vars *v, char *path)
{
	void	*ptr_img;

	ptr_img = mlx_xpm_file_to_image(v->mlx, path, &v->w, &v->h);
	if (!ptr_img)
	{
		free_mat(v->map);
		mlx_clear_window(v->mlx, v->win);
		mlx_destroy_window(v->mlx, v->win);
		ft_putstr_fd("Error", 2);
		ft_putstr_fd("Invalid file path!!", 2);
		exit(1);
	}
}

void	check_xpm_files_2(t_vars *v)
{
	check_xpm_files(v, WALL);
	check_xpm_files(v, WALL_BLACK);
	check_xpm_files(v, PACMAN_R);
	check_xpm_files(v, PACMAN_L);
	check_xpm_files(v, PACMAN_U);
	check_xpm_files(v, PACMAN_D);
	check_xpm_files(v, FOOD);
	check_xpm_files(v, FOOD_S);
	check_xpm_files(v, GHOST_U);
	check_xpm_files(v, GHOST_D);
	check_xpm_files(v, GHOST_R);
	check_xpm_files(v, GHOST_L);
	check_xpm_files(v, DOOR);
}

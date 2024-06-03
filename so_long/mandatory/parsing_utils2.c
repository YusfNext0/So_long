/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:33:24 by ynachat           #+#    #+#             */
/*   Updated: 2024/06/02 15:38:02 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_cros(t_vars *v)
{
	free_mat(v->map);
	mlx_clear_window(v->mlx, v->win);
	mlx_destroy_window(v->mlx, v->win);
	exit(0);
}

void	print_error(void)
{
	ft_putstr_fd("Error", 2);
	ft_putstr_fd("Invalid map!!", 2);
	exit(1);
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
	check_xpm_files(v, DOOR);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:15:45 by ynachat           #+#    #+#             */
/*   Updated: 2024/06/02 16:11:21 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_img(t_vars *v, char *path, int x, int y)
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
	mlx_put_image_to_window(v->mlx, v->win, ptr_img, x * 32, y * 32);
	mlx_destroy_image(v->mlx, ptr_img);
}

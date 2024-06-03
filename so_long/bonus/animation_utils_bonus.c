/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:56:08 by ynachat           #+#    #+#             */
/*   Updated: 2024/06/02 18:36:41 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_animation_food(t_vars *v, char *food)
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
			if (v->map[i][j] == 'C')
			{
				ft_put_img(v, WALL_BLACK, j, i);
				ft_put_img(v, food, j, i);
			}
		}
	}
}

static void	moving(t_vars *v, char move, int gx, int gy)
{
	v->map[gy][gx] = '0';
	ft_put_img(v, WALL_BLACK, gx, gy);
	if (move == 'u')
		ft_put_img(v, GHOST_U, gx, --gy);
	else if (move == 'd')
		ft_put_img(v, GHOST_D, gx, ++gy);
	else if (move == 'r')
		ft_put_img(v, GHOST_R, ++gx, gy);
	else if (move == 'l')
		ft_put_img(v, GHOST_L, --gx, gy);
	if (v->map[gy][gx] == 'P')
	{
		free_mat(v->map);
		mlx_clear_window(v->mlx, v->win);
		mlx_destroy_window(v->mlx, v->win);
		ft_putstr_fd("YOU LOSE !!!", 1);
		exit(0);
	}
	v->map[gy][gx] = 'N';
}

static void	animation_ghosts(t_vars *v)
{
	int			i;
	int			j;
	int			ra;

	i = -1;
	while (v->map[++i])
	{
		j = -1;
		while (v->map[i][++j])
		{
			if (v->map[i][j] == 'N')
			{
				ra = rand() % 4;
				if (ra == 0 && !ft_strchr("1CEN", v->map[i - 1][j]))
					moving(v, 'u', j, i);
				else if (ra == 1 && !ft_strchr("1CEN", v->map[i + 1][j]))
					moving(v, 'd', j, i);
				else if (ra == 2 && !ft_strchr("1CEN", v->map[i][j + 1]))
					moving(v, 'r', j, i);
				else if (ra == 3 && !ft_strchr("1CEN", v->map[i][j - 1]))
					moving(v, 'l', j, i);
				break ;
			}
		}
	}
}

int	effects(t_vars *v)
{
	static int	nb;
	static int	gb;
	static int	set;

	if (nb % 999 == 0 && v->c != 0)
	{
		if (++set == 1)
			set_animation_food(v, FOOD);
		else if (set == 2)
		{
			set_animation_food(v, FOOD_S);
			set = 0;
		}
		nb = 0;
	}
	if (gb % 2999 == 0)
	{
		animation_ghosts(v);
		gb = 0;
	}
	return (gb++, nb++);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:14:43 by ynachat           #+#    #+#             */
/*   Updated: 2024/06/02 15:35:46 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define WALL "textures/Other/Walls/wall.xpm"
# define WALL_BLACK "textures/Other/Walls/black.xpm"
# define PACMAN_R "textures/PacMan/pac_semi_right.xpm"
# define PACMAN_L "textures/PacMan/pac_semi_left.xpm"
# define PACMAN_U "textures/PacMan/pac_semi_up.xpm"
# define PACMAN_D "textures/PacMan/pac_semi_down.xpm"
# define FOOD "textures/Other/Foods/pacdot_powerup.xpm"
# define FOOD_S "textures/Other/Foods/pacdot_food.xpm"
# define GHOST_U "textures/Ghost/Yallow/ghost_up1.xpm"
# define GHOST_D "textures/Ghost/Blue/ghost_down1.xpm"
# define GHOST_R "textures/Ghost/Green/ghost_right1.xpm"
# define GHOST_L "textures/Ghost/Red/ghost_left1.xpm"
# define DOOR "textures/Other/Door/portal.xpm"

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			e;
	int			p;
	int			c;
	int			n;
	int			w;
	int			h;
	int			xp;
	int			yp;
	int			len;
	char		up;
	char		down;
	char		left;
	char		right;
	int			nb_mov_p;
	char		**map;
}				t_vars;

char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		close_cros(t_vars *v);
void	check_file_map(char *map_name);
int		ft_strcmp(const char *s1, const char *s2);
void	free_mat(char **mtr);
void	parsing(char *map_name, t_vars *v);
void	flood_fill(char **map, int y, int x);
int		check_flood(char **map);
void	print_error(void);
void	ft_put_img(t_vars *v, char *path, int x, int y);
void	display_moves_win(t_vars *v, char *itoa);
void	check_last_line(t_vars *v, char *line);
int		effects(t_vars *v);
void	check_xpm_files_2(t_vars *v);

#endif

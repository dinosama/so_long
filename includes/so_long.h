/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:21:22 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/27 17:35:06 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <errno.h>

typedef struct s_pos
{
	int				x;
	int				y;
	char			texture;
}					t_pos;

typedef struct s_imgx
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}					t_imgx;

typedef struct s_map
{
	t_imgx		img;
	char		**map;
	int			xmax;
	int			ymax;
	t_imgx		wall;
	t_imgx		floor;
	t_imgx		hero;
	t_imgx		coin;
	t_imgx		exit;
}					t_map;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	int				rgb;
	t_imgx			img;
	t_map			map;
	t_pos			player;
}					t_vars;

// BACKGROUND MANAGEMENT
int		get_rainbow_color(int color);
void	render_background(t_vars *vars, int color);
void	render_background_game(t_vars *vars, int color);
// PIXEL PRINTING MANAGEMENT
int		encode_rgb(__uint8_t op, __uint8_t red, \
__uint8_t green, __uint8_t blue);
void	img_pix_put(t_imgx *img, int x, int y, int color);
int		get_pixel(t_imgx img, int x, int y);
void	put_tile(t_vars *vars, t_imgx img, int xstart, int ystart);
// MAP PARSING
int		parse_map(t_vars *vars, char *file);
// ERROR MANAGEMENT
int		check_filename(char *str);
int		ft_error(t_vars *vars, int error, int y);
int		check_map(t_vars *vars);
// TEXTURE LOADING
t_imgx	load_image(void *mlx, char *path);
int		parse_texture(t_vars *vars);
// INPUT HANDLER
int		handle_keypress(int key, t_vars *vars);
int		check_coins(t_vars *vars);
char	move_player_leftright(char texture, t_vars *vars, int key);
char	move_player_updown(char texture, t_vars *vars, int key);
// STRUCTURE INIT
void    initimg(t_imgx* mm);
void    initpos(t_pos *pp);
void    initmap(t_map *ma);
void    initvars(t_vars *va);
// OTHERS
char	*read_file(int fd);
char	*ft_strjoint(char *s1, char *s2);
void	ft_putcharuni(int c);
int		key_is_ok(int key);
int		ft_get_nl(char *str);

#endif
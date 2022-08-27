/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:17:27 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/02/04 14:17:29 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include "mlx.h"

# define MAX_INT 2147483647
# define BUFFER_SIZE 90

void				*g_mlx_ptr;
void				*g_win_ptr;
char				**g_map;
int					g_width;
int					g_height;
char				**g_line;
int					g_y_len;
int					g_x;
int					g_y;
int					g_k;
int					g_remaind;
int					g_none;
int					g_wall;
int					g_swiitch;
double				g_x_player;
double				g_y_player;
double				g_rotationangle;
int					g_j;
double				g_rotation;
double				g_rot;
int					g_a;
int					g_b;
int					g_c;
int					*g_data;
void				*g_image;
int					g_y_remainder;
int					g_x_remainder;
double				g_xintercept;
double				g_yintercept;
double				g_ystep;
double				g_xstep;
int					g_remain_argc;
double				g_nexthorix;
double				g_nexthoriy;
double				g_wallhorihit;
double				g_wallverthit;
double				g_horizwallhitx;
double				g_horizwallhity;
double				g_vertwallhitx;
double				g_vrtwallhity;
int					g_color_c;
int					g_color_f;
double				g_wallhitx;
double				g_wallhity;
int					g_rayfacingdown;
int					g_rayfacingup;
int					g_rayfacingright;
int					g_rayfacingleft;
double				g_horzhitdistance;
double				g_verthitdistance;
double				g_distance;
double				g_washitvertical;
int					g_up;
int					g_down;
int					g_left;
int					g_right;
int					g_a;
int					g_d;
double				g_correctwalldistance;
double				g_distanceprojectionplan;
double				g_wallstripheight;
unsigned int		g_darkcolor;
int					g_tab[20];
void				*g_img1;
unsigned int		*g_textu0;
unsigned int		*g_textu1;
unsigned int		*g_textu2;
unsigned int		*g_textu3;
unsigned int		*g_textu4;
double				g_xofsset;
double				g_yoffset;
int					g_mhah;
double				g_pourcent;
int					g_f;
int					g_rightleftupdown;
int					g_n;
int					g_sprite;
int					g_sprite_indicator;
int					g_center_x;
int					g_center_y;
char				**g_check;
int					g_sprite_number;
int					g_dontenteragain;

typedef struct		s_sprite
{
	double			g_mhah;
	double			xcentre;
	double			ycentre;
	double			g_distance;
	double			g_rotation;
	double			g_x;
	double			g_y;
	double			xoff;
}					t_sprite;
t_sprite			g_sprites[1000];
t_sprite			g_sprites_temp;

typedef struct		s_spritefinder
{
	double			g_point_x;
	double			g_point_y;
	double			g_point_distance_x;
	double			g_point_distance_y;
	double			new_angle;
	double			x_offset;
	double			g_angle_sghira;
	double			angle_kbira;
	double			g_angle_wanted;
	double			g_angle_jdida;
	double			g_center_x;
	double			g_center_y;
}					t_spritefinder;
t_spritefinder		g_finder;

int					g_sprite_count;

typedef struct		s_mapcount
{
	int				mapx;
	int				strx;
	int				linex;
	int				lenghtx;
}					t_mapcount;
t_mapcount			g_mapcount[1000];

int					g_inde;

typedef struct		s_direction
{
	int				we;
	int				ea;
	int				su;
	int				no;
	int				r;
	int				s;
	int				f;
	int				c;
}					t_direction;
t_direction			g_direction;

typedef struct		s_screenmap
{
	char			*header;
	short int		bit_count;
	unsigned int	g_width;
	unsigned int	g_height;
	int				width_in_byte;
	unsigned int	image_size;
	unsigned int	size_header;
	unsigned int	offset_bits;
	int				file_size;
	short int		planes;
	int				fd;
	char			*img;
}					t_screenmap;
t_screenmap			g_screenmap;

char				*g_chorfi;
char				*g_mapo;
int					g_t;
int					g_empty_line;
int					g_fd;
int					g_indexo;
double				g_angle_wanted;
double				g_angle_sghira;
double				g_point_x;
double				g_point_y;
double				g_point_distance_x;
double				g_point_distance_y;
double				g_angle_jdida;
int					g_count;
int					g_calcul_parameter;
int					g_counter;
int					g_split;
int					g_indicator;
int					g_dp;
char				**g_pointer;

int					get_next_line(int fd, char **line);
int					ft_strdel(char **tmp, char **str, int num, int ret);
int					ft_isnewline(char *buff);
char				*ft_strcpy(char *dest, char *src);
int					ft_backslash(char ***line, char **str, char **buff, int i);
int					ft_str(char ***line, char **str, char **buff);
int					ft_read(char ***line, char **buff, char **str, int fd);
char				*ft_stock(char *line, char *buff, int i);
int					ft_strlen(char *str);
void				ft_morba3();
int					main();
void				fd_tab(int fd);
char				*ft_itoa(int n);
char				**ft_split(char const *str, char c);
char				*ft_substr(char *s, unsigned int start, size_t len);
void				ft_switch_space();
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_check_screen(char *argv);
void				screenshot(void);
void				ft_check_zero();
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
char				*ft_strchr(char *str, int c);
void				ft_bzero(void *s, size_t len);
void				ft_free_l3alam1();
void				ft_free_l3alam2();
void				ft_return();
char				*ft_strdup(char *src);
char				*ft_strjoin(char *s1, char *s2);
void				ft_putstr(char *str);
int					ft_atoi_h(const char *str);
int					ft_atoi_w(const char *str);
int					ft_atoi(const char *str);
void				ft_check_arg(char **argv, int argc);
void				ft_calcul_lenght();
void				ft_variable_init_calcul_lengh(char **argv);
void				ft_map_traitement(char **argv);
void				ft_graphic_variable(int argc);
void				direction_global();
void				ft_header(void);
int					*get_color(int coloor);
void				create_image(void);
void				screenshot(void);
void				ft_check();
void				ft_check_no();
void				ft_check_r();
void				ft_check_we();
void				ft_check_so();
void				ft_check_ea();
void				ft_check_s();
void				ft_check_c();
void				ft_check_f();
void				ft_check_resolution();
void				ft_return();
void				ft_map_traitement1(int lenght, int fd);
int					check_valid(char *g_check);
void				ft_check_weird();
void				bubblesort(int g_inde);
void				fd_tab2();
void				ft_check_virg();
void				ft_check_errormap(int p);
void				ft_check_zero();
void				ft_check_zero1(int g_j, int i);
int					ft_valid_map();
int					ft_first_line();
void				ft_check_sprite(int g_j, int i);
void				ft_mouvement_up();
void				ft_mouvement_down();
void				ft_mouvement_left();
void				ft_mouvement_right();
void				ft_all_mouvement();
void				ft_find_intersec();
void				ft_yx_intercept();
void				ft_find_intercept1();
void				ft_yx_intercept1();
int					ft_cast_ray();
void				render_map3d(int i);
int					deal_key(void);
void				ft_info_render(int i);
void				render_sprite(int i);
void				ft_collect_info_sprite();
void				ft_render_sprite(int g_j, int i, int start);
void				render_column1(int i);
void				ft_render_walls(int g_j, int i, int start);
void				render_colomn(int i);
void				ft_render_map(int i);
void				ft_free_l3alam(char **g_tab);
int					mlx_key_press(int key);
int					key_release(int key);
int					ft_exit();
unsigned int		check_opacity(unsigned int hexcolor);
unsigned int		convert_rgb(int r, int g, int b);
unsigned int		*ft_texture(char *file, unsigned int *texture);
int					wall_collision();
int					wall_checker();
void				ft_design_morba3_2(int g_j, int i, int y_copy);
int					design_morba3(int i, int g_j);
void				ft_morba3_2(int color, int i, int g_j);
void				ft_morba3_3(int color, int i, int g_j);
int					ray_direction();
double				distance_between_horver(int x1, int y1, int x2, int y2);
void				ft_intial_variable();
int					loop_key();
int					ft_last_line();
double				ft_normalize_angle(double angle);
void				sorting(void);
void				ft_directions(int g_j, int i);
void				ft_nizar_calcul();
void				ft_exit1();
void				ft_check_c1(void);
void				ft_check_f1(void);
void				ft_tab_1(int lenght, char **str);
void				ft_check_errormap1(void);
void				ft_sprite_exist1(void);
void				ft_sprite_exist(void);
double				rad(double x);
double				deg(double x);
void				ft_is_digit(const char *str, int i);
void				ft_is_digit1(const char *str, int i);
int					ft_strcmp(char *s1, char *s2);


#endif

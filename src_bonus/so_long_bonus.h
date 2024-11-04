/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:31:40 by mosokina          #+#    #+#             */
/*   Updated: 2024/11/04 14:28:31 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"

# define GAME_NAME 		"SO_LONG PROJECT: pick up all flowers and go home!"
# define IMG_W 			32
# define IMG_H 			32
# define EX_XPM 		"./textures/house_locked.xpm"
# define EX_OPEN_XPM 	"./textures/house_open.xpm"
# define FLOWER_XPM 	"./textures/flower.xpm"
# define PL_UP_XPM 		"./textures/player_up.xpm"
# define PL_DOWN_XPM 	"./textures/player_down.xpm"
# define PL_LFT_XPM 	"./textures/player_left.xpm"
# define PL_RGHT_XPM 	"./textures/player_right.xpm"
# define BCKGR_XPM 		"./textures/grass.xpm"
# define WALL_XPM 		"./textures/tree.xpm"
/*bonus part*/
# define WF_UP_XPM		"./textures/wolf_up.xpm"
# define WF_DOWN_XPM 	"./textures/wolf_down.xpm"
# define WF_LFT_XPM 	"./textures/wolf_left.xpm"
# define WF_RGHT_XPM 	"./textures/wolf_right.xpm"

# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1 

# define KEY_UP  		65362
# define KEY_LEFT  		65361
# define KEY_RIGHT 		65363
# define KEY_DOWN  		65364
# define KEY_ESC  		65307

# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

# define WHITE	0xFFFFFF

typedef enum e_bool
{
	false,
	true
}		t_bool;

typedef struct s_elem
{
	int	x;
	int	y;
	int	nb;
}			t_elem;

typedef struct s_map
{
	char	**map_arr;
	int		rows;
	int		clmns;
	t_elem	pl;
	t_elem	flws;
	t_elem	ex;
	t_elem	wf;
}				t_map;

typedef struct s_img
{
	void	*ex_img;
	void	*open_img;
	void	*flws_img;
	void	*pl_up_img;
	void	*pl_down_img;
	void	*pl_lft_img;
	void	*pl_rght_img;
	void	*bckgr_img;
	void	*wall_img;
/*bonus part*/
	void	*wf_up_img;
	void	*wf_down_img;
	void	*wf_lft_img;
	void	*wf_rght_img;
}				t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_bool	map_alloc;
	t_img	imgs;
	int		mv_count;
	char	wf_pos;
}				t_data;

void	check_args(int argc, char **argv);
void	init_data(t_data *data);

/*check is map valid  and parse map*/
void	check_valid_map(char *map_path, t_data *data);
void	map_parse(int fd_ber, t_data *data);
void	check_empty_file(char *temp_map, t_data *data);
void	check_empty_line(char *temp_map, t_data *data);
void	check_rectangle(t_data *data, t_map *map);
void	check_walls(t_data *data, t_map *map);
void	check_map_content(t_data *data, t_map *map);
void	check_map_symb(t_data *data, t_map *map, int j, int i);
void	count_map_content(t_data *data, t_map *map);

/*check path to strites*/
void	check_path(t_map map, t_data *data);
char	**dup_map(t_map map);
void	flood_fill(char **temp_map, t_map map, int x, int y);
void	check_path_help(char **temp_map, t_data *data);

/*sprites*/
void	init_sprites(t_data *data);
void	*init_new_img(t_data *data, char *xpm_path);
void	put_background(t_data *data);
void	put_sprites(t_data *data);

/*movement functions*/
void	movement(t_data *data, char pos);
int		key_hook(int keycode, t_data *data);
void	turn_player(t_data *data, char pos);
void	*init_new_pos(t_data *data, char pos, int *new_x, int *new_y);
void	move_player(t_data *data, int new_x, int new_y, void *img_ptr);

/*end of game functions*/
int		error_msg(char *msg, t_data *data);
void	free_all_alloc_memory(t_data *data);
void	free_map(t_data *data);
void	destroy_images(t_data *data);
int		game_destroy(t_data *data);
int		victory(t_data *data);

/*other support functions*/
void	free_str_arr(char **str_arr);
char	*ft_strappend(char **s1, const char *s2);
int		ft_count_c(char *s, char c);

/*bonus_functions*/
void	put_counter(t_data *data, int colour);
void	wf_movement(t_data *data);
void	change_wf_pos(t_data *data);
void	change_wf_pos_2(t_data *data, int x, int y);
void	put_wf(t_data *data);
void	move_wf(t_data *data);
void	is_emeny_close(t_data *data);
int		game_over(t_data *data);
void	destroy_images_wf(t_data *data);
void	put_sprites_2(t_data *data, int y);

#endif

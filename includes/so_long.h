/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:31:40 by mosokina          #+#    #+#             */
/*   Updated: 2024/09/13 13:07:27 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
#include <fcntl.h>
// # include <X11/X.h>
// # include <X11/keysym.h>
# include "../libft/libft.h"


# define GAME_NAME "MY GAME"
# define IMG_W 32
# define IMG_H 32

typedef enum e_bool
{
	false,
	true
} t_bool;


typedef struct s_map
{
	char	**map_arr;
	int		row;
	int		columns;
	int		coins;
	int		player;
	int 	g_exit;
}				t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	// int		p_x;
	// int		p_y;
	// int		counter;
	t_map	map;
	t_bool	map_alloc;
	// t_img	*img;
}				t_data;

void	check_args(int argc, char **argv, t_data *data);
void	is_map_valide(char *map_path, t_data *data);
void	map_parse(int fd_ber, t_data *data);
void	check_empty_line(char *temp_map, t_data *data);
void	check_rectangle(t_data *data);
int		check_walls(t_data *data);
int		check_map_content(t_data *data);

// void	set_win_size(t_data *data, char *map_path);
int		error_msg(char *msg, t_data *data);
void	ft_free_map(t_data *data);
int		perr_msg(char *msg);
int		error_map(char *msg, int fd_ber);
char	*ft_strappend(char **s1, const char *s2);

#endif

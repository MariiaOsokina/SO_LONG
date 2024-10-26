/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:08:09 by mosokina          #+#    #+#             */
/*   Updated: 2024/10/26 01:18:14 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		game_destroy(data);
	else if (keycode == KEY_W || keycode == KEY_UP)
		movement(data, 'y', UP);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		movement(data, 'y', DOWN);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		movement(data, 'x', LEFT);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		movement(data, 'x', RIGHT);
	return (0);
}

void movement(t_data *data, char pos, int dir)
{
	int new_x;
	int new_y;
	void *img_ptr;

	turn_player(data, pos, dir);
	img_ptr = init_new_pos(data, pos, dir, &new_x, &new_y);
	if (data->map.map_arr[new_y][new_x] == '1')
		ft_printf("Don't go to the forest!\n");
	else if (data->map.map_arr[new_y][new_x] == 'E' && data->map.flws.nb != 0)
		ft_printf("Collect all the flowers before going home!\n");
	else if (data->map.map_arr[new_y][new_x] == 'E' && data->map.flws.nb == 0)
		victory(data);
	else
		move_player(data, new_x, new_y, img_ptr);
}

void move_player(t_data *data, int new_x, int new_y, void *img_ptr)
{		
		if (data->map.map_arr[new_y][new_x] == 'C')
		{
			data->map.flws.nb -= 1;
			if (data->map.flws.nb == 0)
			{
				ft_printf ("The door is opened! Go home!\n");
				mlx_put_image_to_window(data->mlx, data->win, data->imgs.open_img, (data->map.ex.x * IMG_W), (data->map.ex.y * IMG_H));
			}
		}
		data->map.map_arr[data->map.pl.y][data->map.pl.x] = '0';
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.bckgr_img, (data->map.pl.x * IMG_W), (data->map.pl.y * IMG_H));
		data->map.pl.x = new_x;
		data->map.pl.y = new_y;
		data->map.map_arr[data->map.pl.y][data->map.pl.x] = 'P';
		mlx_put_image_to_window(data->mlx, data->win, img_ptr, (new_x * IMG_W), (new_y * IMG_H));
		data->mv_count += 1;
		ft_printf("Scores: %d\n", data->mv_count);
}

void *init_new_pos(t_data *data, char pos, int dir, int *new_x, int *new_y)
{
	*new_x = data->map.pl.x;
	*new_y = data->map.pl.y;
	if (pos == 'y')
	{
		*new_y += dir;
		if (dir == UP)
			return (data->imgs.pl_up_img);
		else if (dir == DOWN)
			return (data->imgs.pl_down_img);
	}
	if (pos == 'x')
	{
		*new_x += dir;
		if (dir == LEFT)
			return (data->imgs.pl_lft_img);
		else if (dir == RIGHT)
			return (data->imgs.pl_rght_img);
	}
	return(data->imgs.pl_down_img);
}

void turn_player(t_data *data, char pos, int dir)
{
	if (pos == 'y' && dir == UP)
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.pl_up_img, (data->map.pl.x * IMG_W), (data->map.pl.y * IMG_H));
	if (pos == 'y' && dir == DOWN)
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.pl_down_img, (data->map.pl.x * IMG_W), (data->map.pl.y * IMG_H));
	if (pos == 'x' && dir == LEFT)
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.pl_lft_img, (data->map.pl.x * IMG_W), (data->map.pl.y * IMG_H));
	if (pos == 'x' && dir == RIGHT)
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.pl_rght_img, (data->map.pl.x * IMG_W), (data->map.pl.y * IMG_H));
}

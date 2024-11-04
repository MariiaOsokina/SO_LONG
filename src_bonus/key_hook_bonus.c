/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:08:09 by mosokina          #+#    #+#             */
/*   Updated: 2024/11/04 14:03:39 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		game_destroy(data);
	else if (keycode == KEY_W || keycode == KEY_UP)
		movement(data, 'u');
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		movement(data, 'd');
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		movement(data, 'l');
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		movement(data, 'r');
	put_counter(data, WHITE);
	wf_movement(data);
	return (0);
}

void	movement(t_data *data, char pos)
{
	int		new_x;
	int		new_y;
	void	*img_ptr;

	is_emeny_close(data);
	turn_player(data, pos);
	img_ptr = init_new_pos(data, pos, &new_x, &new_y);
	if (data->map.map_arr[new_y][new_x] == 'X')
		game_over(data);
	if (data->map.map_arr[new_y][new_x] == '1')
		ft_printf("Don't go to the forest!\n");
	else if (data->map.map_arr[new_y][new_x] == 'E' && data->map.flws.nb != 0)
		ft_printf("Collect all the flowers before going home!\n");
	else if (data->map.map_arr[new_y][new_x] == 'E' && data->map.flws.nb == 0)
		victory(data);
	else
		move_player(data, new_x, new_y, img_ptr);
}

void	move_player(t_data *data, int new_x, int new_y, void *img_ptr)
{
	if (data->map.map_arr[new_y][new_x] == 'C')
	{
		data->map.flws.nb -= 1;
		if (data->map.flws.nb == 0)
		{
			ft_printf ("The door is opened! Go home!\n");
			mlx_put_image_to_window(data->mlx, data->win, data->imgs.open_img,
				(data->map.ex.x * IMG_W), (data->map.ex.y * IMG_H));
		}
	}
	data->map.map_arr[data->map.pl.y][data->map.pl.x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->imgs.bckgr_img,
		(data->map.pl.x * IMG_W), (data->map.pl.y * IMG_H));
	data->map.pl.x = new_x;
	data->map.pl.y = new_y;
	data->map.map_arr[data->map.pl.y][data->map.pl.x] = 'P';
	mlx_put_image_to_window(data->mlx, data->win, img_ptr, (new_x * IMG_W),
		(new_y * IMG_H));
	data->mv_count += 1;
}

void	*init_new_pos(t_data *data, char pos, int *new_x, int *new_y)
{
	*new_x = data->map.pl.x;
	*new_y = data->map.pl.y;
	if (pos == 'u')
	{
		*new_y -= 1;
		return (data->imgs.pl_up_img);
	}
	else if (pos == 'd')
	{
		*new_y += 1;
		return (data->imgs.pl_down_img);
	}
	else if (pos == 'l')
	{
		*new_x -= 1;
		return (data->imgs.pl_lft_img);
	}
	else if (pos == 'r')
	{
		*new_x += 1;
		return (data->imgs.pl_rght_img);
	}
	return (data->imgs.pl_down_img);
}

void	turn_player(t_data *data, char pos)
{
	if (pos == 'u')
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.pl_up_img,
			(data->map.pl.x * IMG_W), (data->map.pl.y * IMG_H));
	if (pos == 'd')
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.pl_down_img,
			(data->map.pl.x * IMG_W), (data->map.pl.y * IMG_H));
	if (pos == 'l')
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.pl_lft_img,
			(data->map.pl.x * IMG_W), (data->map.pl.y * IMG_H));
	if (pos == 'r')
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.pl_rght_img,
			(data->map.pl.x * IMG_W), (data->map.pl.y * IMG_H));
}

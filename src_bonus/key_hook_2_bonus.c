/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:10:20 by mosokina          #+#    #+#             */
/*   Updated: 2024/10/26 01:17:26 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void wf_movement(t_data *data)
{
	is_emeny_close(data);
	change_wf_pos(data);
	put_wf(data);
	move_wf(data);
	is_emeny_close(data);
}

void change_wf_pos(t_data *data)
{
	int x;
	int	y;

	x = data->map.wf.x;
	y = data->map.wf.y;
	if (data->wf_pos == 'd' && data->map.map_arr[y + 1][x] != '0')
	{
		if (data->map.map_arr[y][x - 1] == '0')
			data->wf_pos = 'l';
		else if (data->map.map_arr[y - 1][x] == '0')
			data->wf_pos = 'u';
		else if (data->map.map_arr[y][x + 1] == '0')
			data->wf_pos = 'r';
	}
	else if (data->wf_pos == 'l' && data->map.map_arr[y][x - 1] != '0')
	{
		if (data->map.map_arr[y - 1][x] == '0')
			data->wf_pos = 'u';
		else if (data->map.map_arr[y][x + 1] == '0')
			data->wf_pos = 'r';
		else if (data->map.map_arr[y + 1][x] == '0')
			data->wf_pos = 'd';
	}
	change_wf_pos_2(data, x, y);
}

void change_wf_pos_2(t_data *data, int x, int y)
{
	if (data->wf_pos == 'u' && data->map.map_arr[y - 1][x] != '0')
	{
		if (data->map.map_arr[y][x + 1] == '0')
			data->wf_pos = 'r';
		else if (data->map.map_arr[y + 1][x] == '0')
			data->wf_pos = 'd';
		else if (data->map.map_arr[y][x - 1] == '0')
			data->wf_pos = 'l';
	}
	else if (data->wf_pos == 'r' && data->map.map_arr[y][x + 1] != '0')
	{
		if (data->map.map_arr[y + 1][x] == '0')
			data->wf_pos = 'd';
		else if (data->map.map_arr[y][x - 1] == '0')
			data->wf_pos = 'l';
		else if (data->map.map_arr[y - 1][x] == '0')
			data->wf_pos = 'u';
	}
}

void put_wf(t_data *data)
{
	if (data->wf_pos == 'u')
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.wf_up_img, (data->map.wf.x * IMG_W), (data->map.wf.y * IMG_H));
	else if (data->wf_pos == 'd')
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.wf_down_img, (data->map.wf.x * IMG_W), (data->map.wf.y * IMG_H));
	else if (data->wf_pos == 'l')
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.wf_lft_img, (data->map.wf.x * IMG_W), (data->map.wf.y * IMG_H));
	else if (data->wf_pos == 'r')
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.wf_rght_img, (data->map.wf.x * IMG_W), (data->map.wf.y * IMG_H));
}

void move_wf(t_data *data)
{		

		data->map.map_arr[data->map.wf.y][data->map.wf.x] = '0';
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.bckgr_img, (data->map.wf.x * IMG_W), (data->map.wf.y * IMG_H));
		if (data->wf_pos == 'd')
			data->map.wf.y += 1;
		else if (data->wf_pos == 'u')
			data->map.wf.y -= 1;
		else if (data->wf_pos == 'l')
			data->map.wf.x -= 1;
		else if (data->wf_pos == 'r')
			data->map.wf.x += 1;
		data->map.map_arr[data->map.wf.y][data->map.wf.x] = 'X';
		put_wf(data);
}


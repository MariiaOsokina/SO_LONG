/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_sprites_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:22:01 by mosokina          #+#    #+#             */
/*   Updated: 2024/11/04 14:23:31 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_sprites(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->map.rows)
	{
		put_sprites_2(data, y);
		y += 1;
	}
	put_counter(data, WHITE);
}

void	put_sprites_2(t_data *data, int y)
{
	int	x;

	x = 0;
	while (x < data->map.clmns)
	{
		if (data->map.map_arr[y][x] == '1')
			mlx_put_image_to_window(data->mlx, data->win,
				data->imgs.wall_img, (x * IMG_W), (y * IMG_H));
		if (data->map.map_arr[y][x] == 'E')
			mlx_put_image_to_window(data->mlx, data->win,
				data->imgs.ex_img, (x * IMG_W), (y * IMG_H));
		if (data->map.map_arr[y][x] == 'P')
			mlx_put_image_to_window(data->mlx, data->win,
				data->imgs.pl_down_img, (x * IMG_W), (y * IMG_H));
		if (data->map.map_arr[y][x] == 'C')
			mlx_put_image_to_window(data->mlx, data->win,
				data->imgs.flws_img, (x * IMG_W), (y * IMG_H));
		if (data->map.map_arr[y][x] == 'X')
			mlx_put_image_to_window(data->mlx, data->win,
				data->imgs.wf_down_img, (x * IMG_W), (y * IMG_H));
		x += 1;
	}
}

void	put_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.clmns)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->imgs.bckgr_img, (x * IMG_W), (y * IMG_H));
			x += 1;
		}
		y += 1;
	}
	put_counter(data, WHITE);
}

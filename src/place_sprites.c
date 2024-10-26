/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:22:01 by mosokina          #+#    #+#             */
/*   Updated: 2024/10/26 00:16:54 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sprites(t_data *data)
{
	int x;
	int y;

	y = 0;
	while(y < data->map.rows)
	{
		x = 0;
		while (x < data->map.clmns)
		{
			if (data->map.map_arr[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->imgs.wall_img, (x * IMG_W), (y * IMG_H));
			if (data->map.map_arr[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->imgs.ex_img, (x * IMG_W), (y * IMG_H));
			if (data->map.map_arr[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->imgs.pl_down_img, (x * IMG_W), (y * IMG_H));
			if (data->map.map_arr[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->imgs.flws_img, (x * IMG_W), (y * IMG_H));
			x += 1;
		}
		y += 1;
	}
}

void	put_background(t_data *data)
{
	int x;
	int y;

	y = 0;
	while(y < data->map.rows)
	{
		x = 0;
		while (x < data->map.clmns)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->imgs.bckgr_img, (x * IMG_W), (y * IMG_H));
			x += 1;
		}
		y += 1;
	}
}


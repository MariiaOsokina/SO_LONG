/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:15:48 by mosokina          #+#    #+#             */
/*   Updated: 2024/10/26 01:16:29 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	is_emeny_close(t_data *data)
{
	int x;
	int	y;

	x = data->map.wf.x;
	y = data->map.wf.y;
	if (data->map.map_arr[y + 1][x] == 'P')
		game_over(data);
	else if (data->map.map_arr[y - 1][x] == 'P')
		game_over(data);
	else if (data->map.map_arr[y][x - 1] == 'P')
		game_over(data);
	else if (data->map.map_arr[y][x + 1] == 'P')
		game_over(data);
	else
		return ;
}

void put_counter(t_data *data, int colour)
{
		char	*score;
	
		score = ft_itoa(data->mv_count);
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.wall_img, ((data->map.clmns / 2 - 1) * IMG_W), (data->map.rows * IMG_H) - IMG_H);
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.wall_img, ((data->map.clmns / 2) * IMG_W), (data->map.rows * IMG_H) - IMG_H);
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.wall_img, ((data->map.clmns / 2 + 1) * IMG_W), (data->map.rows * IMG_H) - IMG_H);
		mlx_string_put(data->mlx, data->win, (data->map.clmns / 2) * IMG_W - 10, (data->map.rows) * IMG_H - 10, colour, "SCORE: ");
		mlx_string_put(data->mlx, data->win, (data->map.clmns / 2) * (IMG_W) + 40, (data->map.rows) * IMG_H -10, colour, score);
		free(score);
}

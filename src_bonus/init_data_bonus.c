/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:07:47 by mosokina          #+#    #+#             */
/*   Updated: 2024/10/26 01:03:54 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map.map_arr = NULL;
	data->map.rows = 0;
	data->map.clmns = 0;
	data->map.pl = (t_elem){0};
	data->map.wf = (t_elem){0};
	data->map.flws = (t_elem){0};
	data->map.ex = (t_elem){0};
	data->map_alloc = false;
	data->imgs = (t_img){0};
	data->mv_count = 0;
	data->map.wf = (t_elem){0};
	data->wf_pos = 'd';
}

void	init_sprites(t_data *data)
{
	data->imgs.ex_img = init_new_img(data, EX_XPM);
	data->imgs.open_img = init_new_img(data, EX_OPEN_XPM);
	data->imgs.flws_img = init_new_img(data, FLOWER_XPM);
	data->imgs.pl_up_img = init_new_img(data, PL_UP_XPM);
	data->imgs.pl_down_img = init_new_img(data, PL_DOWN_XPM);
	data->imgs.pl_lft_img = init_new_img(data, PL_LFT_XPM);
	data->imgs.pl_rght_img = init_new_img(data, PL_RGHT_XPM);
	data->imgs.bckgr_img = init_new_img(data, BCKGR_XPM);
	data->imgs.wall_img = init_new_img(data, WALL_XPM);
	/*bonus part*/
	data->imgs.wf_up_img = init_new_img(data, WF_UP_XPM);
	data->imgs.wf_down_img = init_new_img(data, WF_DOWN_XPM);
	data->imgs.wf_lft_img = init_new_img(data, WF_LFT_XPM);
	data->imgs.wf_rght_img = init_new_img(data, WF_RGHT_XPM);
}

void	*init_new_img(t_data *data, char *xpm_path)
{
	int w;
	int h;
	void *img_ptr;

	w = IMG_W;
	h = IMG_H;
	img_ptr = mlx_xpm_file_to_image(data->mlx, xpm_path, &w, &h);
	if (!img_ptr)
	{
		printf("%s\n", xpm_path);
		error_msg("Img_ptr. Problems with malloc.", data);
	}
	return (img_ptr);
}

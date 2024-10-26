/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:05:32 by mosokina          #+#    #+#             */
/*   Updated: 2024/10/26 00:33:45 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *msg, t_data *data)
{
	free_all_alloc_memory(data);
	ft_printf("Error\n%s", msg);
	exit(EXIT_FAILURE);
}

int	victory(t_data *data)
{
	ft_printf("-----------------------------------------------\n");
	ft_printf("|                H O O R A Y!!!!            |\n");
	ft_printf("|    You found all flowers and go home.     |\n");
	ft_printf("|        YOU WON! GOOD JOB!                 |\n");
	ft_printf("|      Totally you did %d steps!            |\n", data->mv_count);
	ft_printf("-----------------------------------------------\n");
	free_all_alloc_memory(data);
	exit(0);
}

void free_all_alloc_memory(t_data *data)
{
	destroy_images(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->map_alloc == true)
		free_map(data);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.rows)
	{
		free(data->map.map_arr[i]);
		i++;
	}
	free(data->map.map_arr);
	data->map.map_arr = NULL;
}

void	destroy_images(t_data *data)
{
	if (data->imgs.ex_img)
		mlx_destroy_image(data->mlx, data->imgs.ex_img);
	if (data->imgs.open_img)
		mlx_destroy_image(data->mlx, data->imgs.open_img);
	if (data->imgs.flws_img)
		mlx_destroy_image(data->mlx, data->imgs.flws_img);
	if (data->imgs.pl_up_img)
		mlx_destroy_image(data->mlx, data->imgs.pl_up_img);
	if (data->imgs.pl_down_img)
		mlx_destroy_image(data->mlx, data->imgs.pl_down_img);
	if (data->imgs.pl_lft_img)
		mlx_destroy_image(data->mlx, data->imgs.pl_lft_img);
	if (data->imgs.pl_rght_img)
		mlx_destroy_image(data->mlx, data->imgs.pl_rght_img);
	if (data->imgs.bckgr_img)
		mlx_destroy_image(data->mlx, data->imgs.bckgr_img);
	if (data->imgs.wall_img)
		mlx_destroy_image(data->mlx, data->imgs.wall_img);
}

int	game_destroy(t_data *data)
{
	free_all_alloc_memory(data);
	exit (0);
}

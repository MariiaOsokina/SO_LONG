/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_game_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:40:06 by mosokina          #+#    #+#             */
/*   Updated: 2024/11/04 13:46:15 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	victory(t_data *data)
{
	ft_printf("---------------------------------------------\n");
	ft_printf("|                H O O R A Y!!!!          |\n");
	ft_printf("|    You found all flowers and go home.   |\n");
	ft_printf("|        YOU WON! GOOD JOB!               |\n");
	ft_printf("|      Totally you did %d steps!          |\n", data->mv_count);
	ft_printf("---------------------------------------------\n");
	free_all_alloc_memory(data);
	exit(0);
}

int	game_over(t_data *data)
{
	ft_printf("---------------------------------------------\n");
	ft_printf("|              O O O P S ...!!!!          |\n");
	ft_printf("|   You met the wolf and he ate you.      |\n");
	ft_printf("|                YOU LOSE! SORRY!         |\n");
	ft_printf("|      Totally you did %d steps!          |\n", data->mv_count);
	ft_printf("---------------------------------------------\n");
	free_all_alloc_memory(data);
	exit(0);
}

void	destroy_images_wf(t_data *data)
{
	if (data->imgs.wf_down_img)
		mlx_destroy_image(data->mlx, data->imgs.wf_down_img);
	if (data->imgs.wf_lft_img)
		mlx_destroy_image(data->mlx, data->imgs.wf_lft_img);
	if (data->imgs.wf_rght_img)
		mlx_destroy_image(data->mlx, data->imgs.wf_rght_img);
	if (data->imgs.wf_up_img)
		mlx_destroy_image(data->mlx, data->imgs.wf_up_img);
}

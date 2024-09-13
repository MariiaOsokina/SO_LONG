/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:16:58 by mosokina          #+#    #+#             */
/*   Updated: 2024/09/13 11:22:21 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	ft_printf("Pressed key: %d\n", keysym);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	// t_map	map;

	check_input(argc, argv);

	is_map_valide(argv[1]);
	// set_win_size(&data, argv[1]);
	// ft_initilize(&data, &map);
	data.mlx = mlx_init();
	if (!data.mlx)
		error_msg("Error\n Program initialization was failed");
	data.win = mlx_new_window(data.mlx, 400, 100, GAME_NAME);
	// data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, GAME_NAME);
	if (!data.win)
		return (free(data.mlx), 1);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx);
	return (0);
}

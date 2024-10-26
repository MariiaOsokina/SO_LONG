/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:16:58 by mosokina          #+#    #+#             */
/*   Updated: 2024/10/26 00:56:19 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	check_args(argc, argv);
	data = malloc(sizeof(t_data));
	init_data(data);
	check_valid_map(argv[1], data);
	data->mlx = mlx_init();
	if (!data->mlx)
		error_msg("Mlx ptr. Problems with malloc", data);
	init_sprites(data);
	data->win = mlx_new_window(data->mlx, (data->map.clmns * IMG_W), (data->map.rows * IMG_H), GAME_NAME);
	if (!data->win)
		error_msg("Window. Problems with malloc.", data);
	put_background(data);
	put_sprites(data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, game_destroy, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
	free_all_alloc_memory(data);
	return (0);
}

void	check_args(int argc, char **argv)
{
	if (argc > 2)
	{
		ft_printf("Error\n%s", "Too many arguments\n \
		Add just a map in .ber file\n");
		exit(EXIT_FAILURE);
	}		
	if (argc < 2)
	{
		ft_printf("Error\n%s", "Add a path to the map in .ber file\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		ft_printf("Error\n%s", "The map has to be in .ber file\n");
		exit(EXIT_FAILURE);
	}
}

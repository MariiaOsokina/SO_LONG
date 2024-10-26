/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:38:35 by mosokina          #+#    #+#             */
/*   Updated: 2024/10/26 01:00:19 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_rectangle(t_data *data, t_map *map)
{
	int i;
	size_t	fst_line_size;

	fst_line_size = ft_strlen(map->map_arr[0]);
	i = 0;
	while (i < map->rows)
	{
		if ((ft_strlen(map->map_arr[i]) == 1) && (map->map_arr[i][0] == '\n'))
			error_msg("The map includes the empty line. \
			\nThe map should be rectanle\n", data);
		if (ft_strlen(map->map_arr[i]) != fst_line_size)
			error_msg("The map should be rectangle\n", data);
		i ++;
	}
	map->clmns = fst_line_size;
}

void	check_walls(t_data *data, t_map *map)
{
	int i;
	int	lst_c_ind;
	int lst_r_ind;

	i = 0;
	lst_c_ind = ft_strlen(map->map_arr[0]) - 1;
	lst_r_ind = map->rows - 1;
	while (i <= lst_c_ind)
	{
		if (map->map_arr[0][i] != '1' || map->map_arr[lst_r_ind][i] != '1')
			error_msg("The map should be surounded by the wall\n", data);
		i ++;
	}
	i = 1;
	while(i < lst_r_ind)
	{
		if (map->map_arr[i][0] != '1' || map->map_arr[i][lst_c_ind] != '1')
			error_msg("The map should be surrounded by the wall\n", data);
		i ++;
	}
}

void	check_map_content(t_data *data, t_map *map)
{
	count_map_content(data, map);
	if (map->pl.nb != 1 || map->ex.nb != 1 || map->wf.nb !=1)
		error_msg("Should be only 1 player, 1 emeny and 1 exit. Please check map\n",\
		data);
	if (map->flws.nb < 1)
		error_msg("No collectables(coins), Please check\n", data);
}

void	count_map_content(t_data *data, t_map *map)
{
	int i;
	int j;

	i = 0;
	while(map->map_arr && map->map_arr[++i])
	{
		j = -1;
		while (map->map_arr[i] && map->map_arr[i][++j])
			check_map_symb(data, map, j, i);
	}
}

void	check_map_symb(t_data *data, t_map *map, int j, int i)
{
	if (map->map_arr[i][j] == 'P')
	{
		map->pl.nb += 1;
		map->pl.x = j;
		map->pl.y = i;
	}
	else if (map->map_arr[i][j] == 'E')
	{
		map->ex.nb += 1;
		map->ex.x = j;
		map->ex.y = i;
	}
	else if (map->map_arr[i][j] == 'X')
	{
		map->wf.nb += 1;
		map->wf.x = j;
		map->wf.y = i;
	}
	else if (map->map_arr[i][j] == 'C')
		map->flws.nb += 1;
	else if (map->map_arr[i][j] != '0' && map->map_arr[i][j] != '1')
		error_msg("Only '0','1','C','P','E, X' are valid\n", data);
}

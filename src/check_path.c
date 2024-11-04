/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:43:46 by mosokina          #+#    #+#             */
/*   Updated: 2024/11/04 12:28:30 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(t_map map, t_data *data)
{
	char	**temp_map;
	int		x;
	int		y;

	x = data->map.pl.x;
	y = data->map.pl.y;
	temp_map = dup_map(map);
	if (!temp_map)
		error_msg("Problems with malloc\n", data);
	flood_fill(temp_map, map, x, y);
	check_path_help(temp_map, data);
	free_str_arr(temp_map);
}

char	**dup_map(t_map map)
{
	char	**test_arr;
	int		i;

	i = 0;
	test_arr = (char **)malloc(sizeof(char *) * (map.rows + 1));
	if (!test_arr)
		return (NULL);
	while (i < map.rows)
	{
		test_arr[i] = ft_strdup(map.map_arr[i]);
		if (!test_arr[i])
			return (NULL);
		i ++;
	}
	test_arr[i] = NULL;
	return (test_arr);
}

void	flood_fill(char **temp_map, t_map map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map.clmns || y >= map.rows)
		return ;
	if (temp_map[y][x] == 'X' || temp_map[y][x] == '1')
		return ;
	temp_map[y][x] = 'X';
	flood_fill (temp_map, map, (x + 1), y);
	flood_fill (temp_map, map, (x - 1), y);
	flood_fill (temp_map, map, x, (y + 1));
	flood_fill (temp_map, map, x, (y - 1));
}

void	check_path_help(char **temp_map, t_data *data)
{
	int		i;

	i = 0;
	while (temp_map[i])
	{
		if (ft_count_c(temp_map[i], 'E') > 0)
		{
			free_str_arr(temp_map);
			error_msg("No way to exit. Map is invalid\n", data);
		}
		if (ft_count_c(temp_map[i], 'C') > 0)
		{
			free_str_arr(temp_map);
			error_msg("No way to coins. Map is invalid\n", data);
		}
		i ++;
	}
}

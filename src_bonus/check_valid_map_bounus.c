/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_bounus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:38:35 by mosokina          #+#    #+#             */
/*   Updated: 2024/11/04 13:38:30 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_valid_map(char *map_path, t_data *data)
{
	int		fd_ber;

	fd_ber = open(map_path, O_RDONLY);
	if (fd_ber == -1)
	{
		free_all_alloc_memory(data);
		perror("Error\nProblems with opening map in .ber\n");
		exit(EXIT_FAILURE);
	}
	map_parse(fd_ber, data);
	check_rectangle(data, &(data->map));
	check_walls(data, &(data->map));
	check_map_content(data, &(data->map));
	check_path(data->map, data);
}

void	map_parse(int fd_ber, t_data *data)
{
	char	*temp_map;
	char	*temp_line;

	temp_map = ft_strdup("");
	while (1)
	{
		temp_line = get_next_line(fd_ber);
		if (temp_line == NULL)
			break ;
		temp_map = ft_strappend(&temp_map, temp_line);
		free (temp_line);
		data->map.rows ++;
	}
	close (fd_ber);
	check_empty_file(temp_map, data);
	check_empty_line(temp_map, data);
	data->map.map_arr = ft_split(temp_map, '\n');
	free(temp_map);
	if (!data->map.map_arr)
		error_msg("Map_arr. Problem with malloc\n", data);
	data->map_alloc = true;
}

void	check_empty_file(char *temp_map, t_data *data)
{
	if (temp_map[0] == 0)
	{
		free(temp_map);
		error_msg("Empty map\n", data);
	}
}

void	check_empty_line(char *temp_map, t_data *data)
{
	int	i;

	i = 1;
	if (temp_map[0] == '\n')
	{
		free(temp_map);
		error_msg("Empty first line in the map\n", data);
	}
	while (temp_map[i])
	{
		if ((temp_map[i - 1] == '\n') && (temp_map[i] == '\n'))
		{
			free(temp_map);
			error_msg("Empty line in the map\n", data);
		}
		i ++;
	}
	if (temp_map[i - 1] == '\n')
	{
		free(temp_map);
		error_msg("Empty last line in the map\n", data);
	}
}

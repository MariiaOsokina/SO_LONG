/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:38:35 by mosokina          #+#    #+#             */
/*   Updated: 2024/09/13 13:07:46 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_args(int argc, char **argv, t_data *data)
{
	if (argc > 2)
		error_msg("Too many arguments\nAdd just a map in .ber file", data);
	if (argc < 2)
		error_msg("Add a path to the map in .ber file", data);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		error_msg("The map has to be in .ber file\n", data);
}

void	is_map_valide(char *map_path, t_data *data)
{
	int		fd_ber;
	char	buffer[1];

	fd_ber = open(map_path, O_RDONLY);
	if (fd_ber == -1)
		perr_msg("Error\nProblems with openning map in .ber\n");
	map_parse(fd_ber, data);
	check_rectangle(data);
	check_walls(data);
	data->map.player = 0;
	data->map.g_exit = 0;
	data->map.coins = 0;
	check_map_content(data);
}

void	map_parse(int fd_ber, t_data *data)
{
	char	*temp_map;
	char	*temp_line;

	data->map.row = 0;
	temp_map = ft_strdup("");
	while (1)
	{
		temp_line = get_next_line(fd_ber);
		if (temp_line == NULL)
			break ;
		temp_map = ft_strappend(&temp_map, temp_line);
		free (temp_line);
		data->map.row ++;
	}
	close (fd_ber);
	check_empty_line(temp_map, data);
	data->map.map_arr = ft_split(temp_map, '\n');
	data->map_alloc = true;
	free(temp_map);
	if (data->map.row == 0)
		error_msg("Empty map\n", data);
}

char	*ft_strappend(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}

void	check_empty_line(char *temp_map, t_data *data)
{
	int i;

	i = 1;
	if (temp_map[0] == '\n')
	{
		free(temp_map);
		error_msg("Empty first line in the map\n", data);
	}
	while(temp_map[i])
	{
		if ((temp_map[i-1] == '\n') && (temp_map[i] == '\n'))
		{
			free(temp_map);
			error_msg("Empty line in the map\n", data);
		}
		i ++;
	}
	if (temp_map[i-1]== '\n')
	{
		free(temp_map);
		error_msg("Empty last line in the map\n", data);
	}
}

void	check_rectangle(t_data *data)
{
	int i;
	int	fst_line_size;

	fst_line_size = ft_strlen(data->map.map_arr[0]);
	i = 0;
	while (i < data->map.row)
	{
		if ((ft_strlen(data->map.map_arr[i]) == 1) && (data->map.map_arr[i][0] == '\n'))
			error_msg("The map includes the empty line.\nThe map should be rectanle\n", data);
		if (ft_strlen(data->map.map_arr[i]) != fst_line_size)
			error_msg("The map should be rectangle\n", data);
		i ++;
	}
}

int	check_walls(t_data *data)
{
	int i;
	int	lst_c_ind;
	int lst_r_ind;

	i = 0;
	lst_c_ind = ft_strlen(data->map.map_arr[0]) - 1;
	lst_r_ind = data->map.row - 1;
	while (i <= lst_c_ind)
	{
		if (data->map.map_arr[0][i] != '1' || data->map.map_arr[lst_r_ind][i] != '1')
			error_msg("The map should be surounded by the wall\n", data);
		i ++;
	}
	i = 1;
	while(i < lst_r_ind)
	{
		if (data->map.map_arr[i][0] != '1' || data->map.map_arr[i][lst_c_ind] != '1')
			error_msg("The map should be surrounded by the wall\n", data);
		i ++;
	}
}

int	check_map_content(t_data *data)
{
	int i;
	int j;

	i = 0;
	while(data->map.map_arr && data->map.map_arr[++i])
	{
		j = -1;
		while (data->map.map_arr[i] && data->map.map_arr[i][++j])
		{
			if (data->map.map_arr[i][j] == 'P')
				data->map.player += 1;
			else if (data->map.map_arr[i][j] == 'E')
				data->map.g_exit += 1;
			else if (data->map.map_arr[i][j] == 'C')
				data->map.coins += 1;
			else if (data->map.map_arr[i][j] != '0' && data->map.map_arr[i][j] != '1')
				error_msg("Only '0','1','C','P','E' are valid\n", data);
		}
	}
	if (data->map.player != 1 || data->map.g_exit != 1)
		error_msg("Only 1 player and 1 exit.  Please check\n", data);
	if (data->map.coins < 1)
		error_msg("No collectables(coins), Please check\n", data);
}

int	ft_count_c(char *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!s)
		return (-1);
	while (s && s[i])
	{
		if (s[i++] == c)
			x++;
	}
	return (x);
}

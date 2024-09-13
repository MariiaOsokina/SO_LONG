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

#include "so_long.h"

void	check_input(int argc, char **argv)
{
	if (argc > 2)
		error_msg("Error\nToo many arguments\nAdd just a map in .ber file");
	if (argc < 2)
		error_msg("Error\nAdd a path to the map in .ber file");
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		error_msg("Error\nThe map has to be in .ber file\n");
}

void	is_map_valide(char *map_path)
{
	int		fd_ber;
	char	buffer[1];
	t_map	*map;
	// char	*err_msg;

/*Problems with file oppening*/
	fd_ber = open(map_path, O_RDONLY);
	if (fd_ber == -1)
		perr_msg("Error\nProblems with openning map in .ber\n");
	ft_printf("FD is %d\n", fd_ber);
	if (read(fd_ber, buffer, 1) == 0)
		error_map("Error\nThe .ber file is empty\n", fd_ber);
	map_parse(fd_ber, &map);
	// if (is_map_rectangle(fd_ber) == 0)
	// 	error_map("Error\nThe map should be rectanle\n", fd_ber);
	// if (is_wall_exit(fd_ber) == 0)
	// 	error_map("Error\nThe map should be closed/surrounded by walls.\n");
}

void	map_parse(int fd_ber, t_map **map)
{
	char	*temp_line;
	char	*temp_map;

	(*map)->row = 0;
	temp_map = ft_strdup("");
	while (1)
	{
		temp_line = get_next_line(fd_ber);
		if (temp_line == NULL)
			break ;
		temp_map = ft_strappend(&temp_map, temp_line);
		free (temp_line);
		(*map)->row ++;
	}
	close (fd_ber);
	(*map)->map_arr = ft_split(temp_map, '\n');
	free(temp_map);
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

// 	// is there 1 player
// 	// is there 1 exit
// 	// is there one or mo collectibles

// int	is_map_rectangle(int fd)
// {
// 	char	*line;
// 	size_t	line_size;

// 	line = get_next_line(fd);
// 	line_size = ft_strlen(line);
// 	while (1)
// 	{
// 		if (line == NULL)
// 			break ;
// 		line = get_next_line(fd);
// 		if (line_size != ft_strlen(line))
// 		{
// 			free(line);
// 			return (0);
// 		}
// 		free(line);
// 	}
// 	return (1);
// }

int	is_wall_exist(int fd)
{
	char	*line;
	size_t	line_size;

	line = get_next_line(fd);
	line_size = ft_strlen(line);
	while (1)
	{
		if (line == NULL)
			break ;
		line = get_next_line(fd);
		if (line_size != ft_strlen(line))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}


// void	set_win_size(t_data *data, char *map_path)
// {
	// int	fd_ber;
	// (void)*data;

	// fd_ber = open(map_path, O_RDONLY);
	// if (fd_ber == -1)
	// 	perr_msg("Error\nProblems with map in .ber\n");
	// ft_printf("FD is %d\n", fd_ber);

	
	// data->size_x = 
	// data->size_y = 
// }

// int	ft_line_lengh(int fd)
// {
	
// }

// int	ft_count_lines(int fd)
// {
	
// }


/* the funstion initialize:
- map to data
- xpm files to imgs;
*/ 

// void    ft_initilize(t_data *data, t_map *map)
// {
// 	data->map = map;
// }




// void    ft_initilize(t_data *data, t_map *map)
// {
// 	data->map = map;
// }
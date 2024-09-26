/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:05:32 by mosokina          #+#    #+#             */
/*   Updated: 2024/09/13 12:06:51 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_msg(char *msg, t_data *data)
{
	if (data->map_alloc == true)
		ft_free_map(data);
	free(data);
	ft_printf("Error\n%s", msg);
	exit(EXIT_FAILURE);
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.row)
	{
		free(data->map.map_arr[i]);
		i++;
	}
	free(data->map.map_arr);
}

int	perr_msg(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int	error_map(char *msg, int fd_ber)
{
	ft_printf(msg);
	close(fd_ber);
	exit(EXIT_FAILURE);
}
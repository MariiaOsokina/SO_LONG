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

#include "so_long.h"

int	error_msg(char *msg)
{
	ft_printf(msg);
	exit(EXIT_FAILURE);
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
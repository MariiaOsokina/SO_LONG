/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_game_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:15:10 by mosokina          #+#    #+#             */
/*   Updated: 2024/11/04 12:27:22 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	victory(t_data *data)
{
	ft_printf("------------------------------------------\n");
	ft_printf("|                H O O R A Y!!!!         |\n");
	ft_printf("|    You found all flowers and go home.  |\n");
	ft_printf("|        YOU WON! GOOD JOB!              |\n");
	ft_printf("|      Totally you did %d steps!         |\n", data->mv_count);
	ft_printf("------------------------------------------\n");
	free_all_alloc_memory(data);
	exit(0);
}

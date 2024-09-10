/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:28:35 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/24 16:39:12 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	graphics_clear(t_data *data, t_color color)
{
	int	i;
	int	size;

	i = -1;
	size = data->conf->window_width * data->conf->window_height;
	while (++i < size)
		data->grph->back->raster[i] = color;
}

void	graphics_present(t_data *data)
{
	t_graphics	*grph;
	void		*tmp;

	grph = data->grph;
	tmp = grph->front;
	grph->front = grph->back;
	grph->back = tmp;
	mlx_put_image_to_window(
		grph->mlx_ptr,
		grph->win_ptr,
		grph->front->ptr,
		0,
		0);
}

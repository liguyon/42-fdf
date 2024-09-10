/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:59:07 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/29 14:34:17 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void	render_sidebar(t_data *data)
{
	int		padding;

	padding = 5;
	draw_rect(data, (t_rect){
		.x = data->conf->window_width / 2 - data->conf->prop_width,
		.y = -data->conf->window_height / 2 + padding + 1,
		.width = data->conf->prop_width - padding,
		.height = data->conf->window_height - padding * 2}, COLOR_PROP_BG);
}

static void	render_color_chart(t_data *data)
{
	t_conf	*c;

	c = data->conf;
	draw_rect(data, (t_rect){620, -420, 20, 20}, c->col[0]);
	draw_rect(data, (t_rect){620, -398, 20, 20}, c->col[1]);
	draw_rect(data, (t_rect){620, -376, 20, 20}, c->col[2]);
	draw_rect(data, (t_rect){620, -354, 20, 20}, c->col[3]);
	draw_rect(data, (t_rect){620, -332, 20, 20}, c->col[4]);
	draw_rect(data, (t_rect){620, -310, 20, 20}, c->col[5]);
	draw_rect(data, (t_rect){620, -288, 20, 20}, c->col[6]);
	draw_rect(data, (t_rect){620, -266, 20, 20}, c->col[7]);
	draw_rect(data, (t_rect){620, -244, 20, 20}, c->col[8]);
}

static void	render_ui_text_chart(t_data *data)
{
	int	i;
	int	len;
	int	pad;

	pad = ft_strlen(data->strs[0]);
	i = 0;
	while (++i < 10)
	{
		len = ft_strlen(data->strs[i]);
		if (len > pad)
			pad = len;
	}
	i = -1;
	pad *= 10;
	while (++i < 9)
	{
		draw_text(data, 655, -415 + i * 22, data->strs[i]);
		draw_text(data, 660 + pad, -415 + i * 22, "-");
		draw_text(data, 680 + pad, -415 + i * 22, data->strs[i + 1]);
	}
}

void	render_ui_text(t_data *data)
{
	draw_text(data, 670, 410, "Controls");
	draw_text(data, 664, 407, "__________");
	draw_text(data, 620, 380, "Mouse Left : Translate");
	draw_text(data, 620, 360, "Mouse Right : Rotate");
	draw_text(data, 620, 340, "Mouse Scroll : Zoom +/-");
	draw_text(data, 620, 320, "1, 2, 3 : Color Palette");
	draw_text(data, 620, 300, "r : Reset Transformations");
	draw_text(data, 620, 280, "p : Change Projection");
	draw_text(data, 620, 260, "l : Lock/Unlock z-scaling");
	draw_text(data, 620, 240, "PgUp/PgDn : Scale Z +/-");
	draw_text(data, 670, 100, "Options");
	draw_text(data, 667, 97, "________");
	if (data->inputs->lock_sz == true)
		draw_text(data, 620, 70, "z-scaling : LOCKED");
	else
		draw_text(data, 620, 70, "z-scaling : UNLOCKED");
	draw_text(data, 670, -210, "Elevation");
	draw_text(data, 664, -213, "___________");
	render_ui_text_chart(data);
}

void	render_ui(t_data *data)
{
	render_sidebar(data);
	render_color_chart(data);
}

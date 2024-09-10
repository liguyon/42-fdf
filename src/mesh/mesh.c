/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:23:55 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/29 14:32:27 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	mesh_vertices_alloc(t_mesh *mesh)
{
	int	i;

	mesh->vertices = calloc_log(1, mesh->height * sizeof(*mesh->vertices));
	if (mesh->vertices == NULL)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < mesh->height)
	{
		mesh->vertices[i] = calloc_log(
				1, mesh->width * sizeof(**mesh->vertices));
		if (mesh->vertices[i] == NULL)
		{
			while (--i >= 0)
				free(mesh->vertices[i]);
			free(mesh->vertices);
			mesh->vertices = NULL;
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	mesh_init(t_data *data, const char *filename)
{
	t_mesh	*mesh;
	int		ret;

	mesh = calloc_log(1, sizeof(*mesh));
	if (mesh == NULL)
		return (EXIT_FAILURE);
	data->mesh = mesh;
	ret = parse(mesh, filename);
	if (ret == EXIT_SUCCESS)
	{
		logger(LOGGER_INFO,
			"loaded mesh [file:'%s' ; vertices:%d ; width:%d ; height:%d]",
			filename, mesh->height * mesh->width, mesh->width, mesh->height);
		mesh_reset_transforms(data);
	}
	return (ret);
}

void	mesh_destroy(t_data *data)
{
	int	i;

	if (data->mesh != NULL)
	{
		if (data->mesh->vertices != NULL)
		{
			i = -1;
			while (++i < data->mesh->height)
				free(data->mesh->vertices[i]);
			free(data->mesh->vertices);
		}
		free(data->mesh);
		data->mesh = NULL;
		logger(LOGGER_INFO, "destroyed mesh");
	}
}

// scale vector is adjusted equally on x, y and z
// so we keep the map's default ratios
void	mesh_reset_transforms(t_data *data)
{
	t_mesh	*mesh;
	float	rx;
	float	ry;
	float	sf;

	mesh = data->mesh;
	rx = mesh->width / data->conf->vp_width;
	ry = mesh->height / data->conf->window_height;
	if (rx > ry)
		sf = 0.9f * (float)data->conf->vp_width / (float)mesh->width;
	else
		sf = 0.9f * (float)data->conf->window_height / (float)mesh->height;
	mesh->s = (t_vec3){sf, sf, sf};
	if (data->conf->proj == proj_iso)
		mesh->r = (t_vec3){90.0f - 35.0f, 45.0f, 21.0f};
	else
		mesh->r = (t_vec3){0.0f, 0.0f, 0.0f};
	mesh->t = (t_vec3){-data->conf->prop_width / 2, 0.0f, 0.0f};
	data->mesh->adjust_sz = true;
}

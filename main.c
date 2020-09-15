/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:35:22 by jbodson           #+#    #+#             */
/*   Updated: 2020/09/15 18:12:36 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int ft_intersection(t_ray r, t_sphere s)
{
	double a;
	double b;
	double c;
	double delta;
	double t1;
	double t2;

	r.direction = normalize(r.direction);
	a = 1;
	b = 2 * dotvector(r.direction, ft_minvector(r.origin, s.O));
	c = getNorm2(ft_minvector(r.origin, s.O)) - s.R * s.R;
	delta = b * b - 4 * a * c;
	t1 = (-b - sqrt(delta)) / (2 * a);
	t2 = (-b + sqrt(delta)) / (2 * a);
	if (t2 > 0)
		return 1;
	else 
		return 0;
	
}

int main()
{
	void *mlx;
	void *win;
	int w;
	int h;
	int r;
	int i;
	int j;
	int b;
	int g;
	double fov;
	int has_inter;
	t_sphere s;
	t_vector v;
	t_ray	rayon;

	b = 160;
	r = 80;
	g = 0;
	w = 600;
	h = 905;
	fov = 60 * PI/180;
	i = 0;
	j = 0;
	v.x = 0;
	v.y = 0;
	v.z = 60;
	s.O = v;
	s.R = 40;
	int *img;
	img = malloc(4 * w * h * 3);
	mlx = mlx_init();
	win = mlx_new_window(mlx, w, h, "mlx 42");
	while (i < h)
	{
		while (j < w)
		{ 
			rayon.origin.x = 0;
			rayon.origin.y = 0;
			rayon.origin.z = 0;
			rayon.direction.x = j - w / 2;
			rayon.direction.y = i - h / 2;
			rayon.direction.z = -w / (2 * tan(fov / 2));
			has_inter = ft_intersection(rayon, s);
			if (has_inter == 1)
			{
				img[(i*w + j) * 3] = r;
				img[(i*w + j) * 3 + 1] = g;
				img[(i*w + j) * 3 + 2] = b;
			}
			else
			{
				img[(i*w + j) * 3] = 0;
				img[(i*w + j) * 3 + 1] = 150;
				img[(i*w + j) * 3 + 2] = 100;
			}
			mlx_pixel_put(mlx, win, j, h - 1 - i, img[(i*w + j) * 3 + 2] + img[(i*w + j) * 3 + 1] * 256 + img[(i*w + j) * 3] * 256 * 256);
			j++;
		}
		i++;
		j = 0;
	}
	mlx_loop(mlx);
}
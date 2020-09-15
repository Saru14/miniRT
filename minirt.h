/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:30:46 by jbodson           #+#    #+#             */
/*   Updated: 2020/09/15 17:18:10 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINIRT_H
#define	MINIRT_H

# include "mlx.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#define PI 3,1415926535897932

typedef struct		s_pixels
{
	double r;
	double g;
	double b;
}					t_pixels;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_ray
{
	t_vector		origin;
	t_vector		direction;
}					t_ray;

typedef struct 		s_sphere
{
	t_vector		O;
	double			R;
}					t_sphere;


t_vector	ft_addvector(t_vector v1, t_vector v2);
t_vector	ft_minvector(t_vector v1, t_vector v2);
t_vector	ft_multvectors(t_vector v1, t_vector v2);
t_vector	ft_multvector(t_vector v1, double i);
t_vector	ft_divvector(t_vector v1, double i);
t_vector	ft_divvectors(t_vector v1, t_vector v2);
t_vector	ft_sqrtvector(t_vector v1, double i);
double		dotvector(t_vector v1, t_vector v2);
int			ft_intersection( const t_ray r, const t_sphere s);
double		getNorm2(t_vector v1);
t_vector 	normalize(t_vector v1);

#endif
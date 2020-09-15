/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:27:29 by jbodson           #+#    #+#             */
/*   Updated: 2020/09/14 18:50:59 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	ft_addvector(t_vector v1, t_vector v2)
{
	t_vector	new;

	new.x = v1.x + v2.x;
	new.y = v1.y + v2.y;
	new.z = v1.z + v2.z;
	return (new);
}

t_vector	ft_minvector(t_vector v1, t_vector v2)
{
	t_vector	new;

	new.x = v1.x - v2.x;
	new.y = v1.y - v2.y;
	new.z = v1.z - v2.z;
	return (new);
}

t_vector	ft_multvectors(t_vector v1, t_vector v2)
{
	t_vector	new;
	new.x = v1.x * v2.x;
	new.y = v1.y * v2.y;
	new.z = v1.z * v2.z;
	return (new);
}

t_vector	ft_multvector(t_vector v1, double i)
{
	t_vector	new;
	new.x = v1.x * i;
	new.y = v1.y * i;
	new.z = v1.z * i;
	return (new);
}

t_vector	ft_divvector(t_vector v1, double i)
{
	t_vector	new;
	new.x = v1.x / i;
	new.y = v1.y / i;
	new.z = v1.z / i;
	return (new);
}

t_vector	ft_divvectors(t_vector v1, t_vector v2)
{
	t_vector	new;
	new.x = v1.x / v2.x;
	new.y = v1.y / v2.y;
	new.z = v1.z / v2.z;
	return (new);
}

double dotvector(t_vector v1, t_vector v2)
{
	double i;

	i = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (i);
}

double getNorm2(t_vector v1)
{
	double i;

	i = v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
	return (i);
}

t_vector normalize(t_vector v1)
{
	double norm;
	t_vector v2;

	norm = sqrt(getNorm2(v1));
	v2.x = v1.x / norm;
	v2.y = v1.y / norm;
	v2.z = v1.z / norm;
	return (v2);
}


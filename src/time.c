/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 23:33:07 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/22 00:06:51 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "wolf3d.h"

void		w3d_frametime(void )
{
	struct timespec		t;
	static clock_t		ti = 0;
	double				timer;

	if (ti)
		timer = (double)(clock() - ti) / CLOCKS_PER_SEC;
	else
		timer = 0.0;
	ft_printf("FPS : %5.3f\e[13D", timer);
	timer = (1.0 / 30.0) - timer;
	if (timer > 0.0)
	{
		t = (struct timespec){.tv_sec = 0,
			.tv_nsec = (long)(timer * 999999989L)};
		nanosleep(&t, NULL);
	}
	ti = clock();
}

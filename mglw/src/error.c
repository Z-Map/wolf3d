/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 01:54:35 by map               #+#    #+#             */
/*   Updated: 2016/12/21 15:31:15 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern/system.h"

void				mglw_seterror(int error, const char* msg)
{
	static mglw_sys	*sys = NULL;

	if (!error)
	{
		sys = (mglw_sys *)(size_t)msg;
		return ;
	}
	if (sys)
		sys->error = error;
	printf("miniGLwin Error n°%i : %s\n", error, msg);
}

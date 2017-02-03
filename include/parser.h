/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:26:17 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/03 16:07:41 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "wolf3d.h"

typedef struct		s_parsedata
{
	int				error;
	int				flags;
	t_blit			*blist[16];
	size_t			len[16];
}					t_pdata;

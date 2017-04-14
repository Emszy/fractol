/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_and_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 04/14/2017 15:43 by ebucheit             #+#    #+#             */
/*   Updated: 04/14/2017 15:43 by ebucheit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void init_keys(t_connection *obj)
{
	obj->key.a = 		0;
 	obj->key.b = 		0;
 	obj->key.c = 		0;
 	obj->key.d = 		0;
 	obj->key.e = 		0;
 	obj->key.f = 		0;
 	obj->key.q = 		0;
 	obj->key.r = 		0;
 	obj->key.s = 		0;
 	obj->key.t = 		0;
 	obj->key.u = 		0;
 	obj->key.v = 		0;
 	obj->key.w = 		0;
 	obj->key.x = 		0;
 	obj->key.y = 		0;
 	obj->key.z = 		0;
 	obj->key.space = 	0;
 	obj->key.left =		0;
 	obj->key.right =	0;
 	obj->key.up =		0;
 	obj->key.down =		0;
}

void init_colors2(t_connection *obj)
{
	obj->color_wheel[25] = 	0x0063701f;
	obj->color_wheel[26] = 	0x008da02b;
	obj->color_wheel[27] = 	0x00c5e03c;
	obj->color_wheel[28] = 	0x00d6f731;
	obj->color_wheel[29] = 	0x00a4bf20;
	obj->color_wheel[30] =	0x00cef416;
	obj->color_wheel[31] =	0x00d2fc07;
	obj->color_wheel[32] =	0x00a5c603;
	obj->color_wheel[33] =	0x008cffeb;
	obj->color_wheel[34] =	0x006fcebe;
	obj->color_wheel[35] =	0x0051998c;
	obj->color_wheel[36] =	0x004fad9d;
	obj->color_wheel[37] =	0x003a7f73;
	obj->color_wheel[38] =	0x0060f2d9;
	obj->color_wheel[39] =	0x0051e8ce;
	obj->color_wheel[40] =	0x003aad99;
	obj->color_wheel[41] =	0x002ca38e;
	obj->color_wheel[42] =	0x0039d6b9;
	obj->color_wheel[43] =	0x002af7d1;
	obj->color_wheel[44] =	0x001fb79b;
	obj->color_wheel[45] = 	0x0011b294;
	obj->color_wheel[46] = 	0x0013efc6;
	obj->color_wheel[47] = 	0x0000ffcf;
	obj->color_wheel[48] = 	0x00b92ad6;
	obj->color_wheel[49] = 	0x00d61bfc;
}

void init_colors1(t_connection *obj)
{
	obj->color_wheel[0] = 	0x00ffffff;
	obj->color_wheel[1] = 	0x00bfbdbd;
	obj->color_wheel[2] = 	0x009b9999;
	obj->color_wheel[3] = 	0x00828080;
	obj->color_wheel[4] = 	0x005e5e5e;
	obj->color_wheel[5] = 	0x005b4f4f;
	obj->color_wheel[6] = 	0x005e4646;
	obj->color_wheel[7] = 	0x005b3c3c;
	obj->color_wheel[8] = 	0x00593030;
	obj->color_wheel[9] = 	0x00753e3e;
	obj->color_wheel[10] = 	0x00a55151;
	obj->color_wheel[11] = 	0x00d66868;
	obj->color_wheel[12] = 	0x00f97777;
	obj->color_wheel[13] = 	0x00f95252;
	obj->color_wheel[14] = 	0x00f93e3e;
	obj->color_wheel[15] = 	0x00fc2828;
	obj->color_wheel[16] = 	0x00c61d1d;
	obj->color_wheel[17] = 	0x007a1111;
	obj->color_wheel[18] = 	0x00d61111;
	obj->color_wheel[19] = 	0x00ff0000;
	obj->color_wheel[20] = 	0x00ebff93;
	obj->color_wheel[21] = 	0x00b2c170;
	obj->color_wheel[22] = 	0x007a844b;
	obj->color_wheel[23] = 	0x006f7a39;
	obj->color_wheel[24] = 	0x006b772c;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:15:41 by frromero          #+#    #+#             */
/*   Updated: 2024/08/07 10:48:47 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void par(int i)
{
	int u;
	int d;

	u = i % 10;
	d = i / 10;
	u = u + 48;
	d = d + 48;
	write(1, &d, 1);
	write(1, &u, 1);
}

void ft_print_comb_2(void)
{
	char comma;
	int c;
	int d;
	int b;

	comma = ',';
	b = ' ';
	c = 0;
	d = 0;
	while (c < 99)
	{
		while (d <= 99)
		{
			par(c);
			write(1, &b, 1);
			par(d);
			(c <= 99 && d <= 98) && (write(1, &comma, 1) && write(1, &b, 1));
			d++;
		}
		c++;
		d = 0;
		(c <= 98) && write(1, &comma, 1);
	}
}

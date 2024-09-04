/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:19:47 by frromero          #+#    #+#             */
/*   Updated: 2024/08/17 12:29:15 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_display(int nbr, char *base, unsigned int length)
{
	unsigned int num;

	num = nbr;
	if (nbr < 0)
	{
		num = nbr * -1;
		ft_putchar('-');
	}
	if (num >= length)
		ft_display(num / length, base, length);
	ft_putchar(base[num % length]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	length;

	length = 0;
	while (base[length] != '\0')
		length++;
	ft_display(nbr, base, length);
}

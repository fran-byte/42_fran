/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:57:05 by frromero          #+#    #+#             */
/*   Updated: 2024/08/18 15:25:57 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb > 2147483647)
		return (0);
	i = 0;
	while (i < nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
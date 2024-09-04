/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 00:04:48 by frromero          #+#    #+#             */
/*   Updated: 2024/08/26 13:49:49 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_range(int min, int max)
{
	int	*numbers;
	int i;
	int z;
	int s;

	s = max - min;
	if (!(numbers = (int*)malloc(4 * s < 0 ? (max - min) * -1 : max - min)))
		return (0);
	i = 0;
	z = min;
	while (z < max)
		numbers[i++] = z++;
	return (numbers);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:16:48 by frromero          #+#    #+#             */
/*   Updated: 2024/08/26 13:55:22 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;

	i = -1;
	*range = (int *)malloc(sizeof(**range) * (max - min + 1));
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	while (++i < (max - min))
		range[0][i] = min + i;
	return (i);
}
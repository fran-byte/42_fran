/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 23:33:23 by frromero          #+#    #+#             */
/*   Updated: 2024/08/26 13:55:31 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		z;
	char	*dest;

	i = 0;
	while (src[i] != '\0')
		i++;
	dest = (char*)malloc(i + 1);
	z = 0;
	while (src[z] != '\0')
	{
		dest[z] = src[z];
		z++;
	}
	dest[z] = '\0';
	return (dest);
}
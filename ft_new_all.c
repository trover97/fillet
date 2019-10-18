/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:39:07 by jterrell          #+#    #+#             */
/*   Updated: 2019/10/17 21:43:49 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra	*new_tetra(int w, int h, char l, char **tetrax)
{
	t_tetra	*ptr;

	if (!(ptr = (t_tetra*)malloc(sizeof(t_tetra))))
		return (NULL);
	ptr->h = h;
	ptr->w = w;
	ptr->letter = l;
	ptr->tetra = tetrax;
	return (ptr);
}

t_point	*init_point(int x, int y)
{
	t_point *ptr;

	if (!(ptr = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	ptr->x = x;
	ptr->y = y;
	return (ptr);
}

t_list	*free_ist(t_list **head)
{
	t_list	*mem;
	t_list	*ptr;

	mem = *head;
	while (mem)
	{
		ptr = mem;
		mem = mem->next;
		free(ptr);
	}
	return (NULL);
}

t_map	*free_map(t_map *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:34:16 by jterrell          #+#    #+#             */
/*   Updated: 2019/10/18 14:46:29 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_to_this_map(t_map *map, t_point *xy, t_tetra *tetra, char l)
{
	int		k;
	int		t;

	k = 0;
	while (k < tetra->h)
	{
		t = 0;
		while (t < tetra->w)
		{
			if (tetra->tetra[k][t] == '#')
				map->map[xy->x + k][xy->y + t] = l;
			t++;
		}
		k++;
	}
}

int		check_map(t_map *map, t_tetra *tetra, int i, int j)
{
	int		k;
	int		t;
	t_point *xy;

	k = 0;
	xy = (t_point *)malloc(sizeof(t_point));
	xy->x = i;
	xy->y = j;
	while (k < tetra->h)
	{
		t = 0;
		while (t < tetra->w)
		{
			if (tetra->tetra[k][t] == '#' && map->map[i + k][j + t] != '.')
			{
				ft_memdel((void **)&xy);
				return (0);
			}
			t++;
		}
		k++;
	}
	put_to_this_map(map, xy, tetra, tetra->letter);
	ft_memdel((void **)&xy);
	return (1);
}

void	print_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			ft_putchar(map->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	free_map(map, map->size);
}

void	listdel(t_list *list)
{
	t_list	*list_next;
	t_tetra	*tetra;
	int		i;

	while (list)
	{
		tetra = (t_tetra *)list->content;
		list_next = list->next;
		i = 0;
		while (i < tetra->h)
		{
			free(tetra->tetra[i]);
			i++;
		}
		ft_memdel((void **)&tetra->tetra);
		ft_memdel((void **)&tetra);
		ft_memdel((void **)&list);
		list = list_next;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;

	if (argc != 2)
	{
		ft_putstr("usage: fillit fili_name\n");
		return (1);
	}
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putstr("error\n");
			return (1);
		}
		if (!(list = read_map(fd)))
		{
			ft_putstr("error\n");
			return (1);
		}
		close(fd);
	}
	print_map(try(list));
	listdel(list);
	return (0);
}

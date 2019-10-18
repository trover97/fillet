/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:25:28 by jterrell          #+#    #+#             */
/*   Updated: 2019/10/18 13:25:10 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

# include <stdio.h>

typedef struct	s_tetra
{
	int		h;
	int		w;
	char	letter;
	char	**tetra;
}				t_tetra;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_map
{
	int		size;
	char	**map;
}				t_map;

t_list			*read_map(int fd);
int				check(char *tetra, int size);
int				check1(char *tetra);
t_tetra			*new_tetra(int w, int h, char l, char **tetra);
t_point			*init_point(int x, int y);
t_tetra			*do_map(char *buf, char l);
void			extreme(char *tetra, t_point *max, t_point *min);
t_list			*free_ist(t_list **head);
t_map			*free_map(t_map *map, int size);
void			put_to_this_map(t_map *map, t_point *xy, t_tetra *tetra,
				char l);
int				check_map(t_map *map, t_tetra *tetra, int i, int j);
t_map			*new_map(int size);
t_map			*try(t_list *ist);
void			print_map(t_map *map);
void			listdel(t_list *list);

#endif

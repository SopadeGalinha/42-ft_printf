/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:08:33 by jhgoncal          #+#    #+#             */
/*   Updated: 2023/01/18 20:56:18 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//Testes
#include<stdio.h>
#include<printf.h>
#include<unistd.h>

int	ft_printf(const char *fmt, ...);

int	main(void)
{
	int				i;
	int				d;
	unsigned int	basex;
	unsigned int	baseu;
	void			*p;

	p = (int *)0;
	i = 0;
	d = -0;
	baseu = 4294967295;
	basex = 0;
	printf("Original = :%%: :%c: [%d] [%i] :%p:\n", 'a', d, i, p);
	ft_printf("Mine     = :%%: :%c: [%d] [%i] :%p:\n", 'a', d, i, p);
	write(1, "\n\n", 2);
	printf("Original = u:[%u] x:[%x] X:[%X] s:[%s]\n", baseu, basex, basex,
		"SopadeGalinha Rocks");
	ft_printf("Mine     = u:[%u] x:[%x] X:[%X] s:[%s]\n", baseu, basex, basex,
		"SopadeGalinha Rocks");
}

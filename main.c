/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:55:27 by eholzer           #+#    #+#             */
/*   Updated: 2022/11/15 16:00:24 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	int	len;
	int len2;

	printf("\nft_printf:\n");
	len = ft_printf("bonjour %s, %x", "eric", -42);
	printf("\nft_printf length: %d", len);

	printf("\n----------------------------------------------\n");

	printf("printf:\n");
	len2 = printf("bonjour %s, %x", "eric", 42);
	printf("\nprintf length: %d\n\n", len2);
}

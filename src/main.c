/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:32:37 by cyildiri          #+#    #+#             */
/*   Updated: 2017/05/07 19:44:49 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proxy.h"

int	main(void)
{
	int					server_sock;
	struct sockaddr_in	*addr;
	size_t				*addrlen;

	addr = malloc(sizeof(struct sockaddr_in));
	addrlen = malloc(sizeof(size_t));
	*addrlen = sizeof(*addr);
	server_sock = server_socket_setup(PORT, addr, addrlen);
	printf("listening on port %d!", PORT);
	handle_requests(server_sock, 2048, addr, addrlen);
	return (0);
}

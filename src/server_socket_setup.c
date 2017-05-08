/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_socket_setup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 17:13:29 by cyildiri          #+#    #+#             */
/*   Updated: 2017/05/07 19:44:02 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proxy.h"

int     server_socket_setup(int port)
{
	int					socket;
	struct sockaddr_in	address;
	size_t				addrlen;

	addrlen = sizeof(address);
	if ( socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP) == -1)
	{
        printf("Opening the server socket failed!\n");
    	return (-1);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);
	if ( bind(socket, (struct sockaddr *)&address, addrlen) )
	{
        printf("Binding the server socket failed!\n");
    	return (-1);
	}
	if ( listen(socket, 99) )
	{
		printf("Listening on server socket failed!\n");
		return (-1);
	}
	return (socket)
}

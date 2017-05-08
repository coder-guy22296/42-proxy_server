/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_socket_setup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 17:13:29 by cyildiri          #+#    #+#             */
/*   Updated: 2017/05/07 20:34:57 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proxy.h"
#include <sys/ioctl.h>
#include <fcntl.h>

int     server_socket_setup(int port, struct sockaddr_in *address)
{
	int					server_sock;
	size_t				addrlen;

	addrlen = sizeof(address);
	if ( (server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
	{
        printf("Opening the server socket failed!\n");
    	return (-1);
	}
	address->sin_family = AF_INET;
	address->sin_addr.s_addr = INADDR_ANY;
	address->sin_port = htons(port);
	if ( bind(server_sock, (struct sockaddr *)address, addrlen) == -1)
	{
        printf("Binding the server socket failed!\n");
    	return (-1);
	}
	if ( listen(server_sock, 3) == -1)
	{
		printf("Listening on server socket failed!\n");
		return (-1);
	}
	return (server_sock);
}

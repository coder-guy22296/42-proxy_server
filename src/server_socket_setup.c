/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_socket_setup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 17:13:29 by cyildiri          #+#    #+#             */
/*   Updated: 2017/05/07 21:18:07 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proxy.h"
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>

int		server_socket_setup(int port, struct sockaddr_in *addr,
		size_t *addr_len)
{
	int		server_sock;
	int		opt;

	opt = 0;
	server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
		sizeof(opt)) == -1)
		printf("options error! %d\n", errno);
	addr->sin_family = AF_INET;
	addr->sin_addr.s_addr = INADDR_ANY;
	addr->sin_port = htons(port);
	if (bind(server_sock, (struct sockaddr *)addr, *addr_len) == -1)
	{
		printf("Binding the server socket failed! %d\n", errno);
		return (-1);
	}
	if (listen(server_sock, 3) == -1)
	{
		printf("Listening on server socket failed!\n");
		return (-1);
	}
	return (server_sock);
}

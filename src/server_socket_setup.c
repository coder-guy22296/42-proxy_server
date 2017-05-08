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

int     server_socket_setup(int port)
{
	int					server_sock;
	size_t				addrlen;
	struct sockaddr_in address;
	int 				opt;

	opt = 0;
	addrlen = sizeof(address);
	if ( (server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
	{
        printf("Opening the server socket failed!\n");
    	return (-1);
	}

	if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1)
    {
		printf("options error! %d\n", errno);
    }
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);
	if ( bind(server_sock, (struct sockaddr *)&address, addrlen) == -1)
	{
        printf("Binding the server socket failed!\n");
    	return (-1);
	}
	if ( listen(server_sock, 3) == -1)
	{
		printf("Listening on server socket failed!\n");
		return (-1);
	}

	int     addr_len;
    char    *buffer;
    //char  *request;
    int     bytes_read;
    int     client_sock;
	int		buff_size = 4096;

    client_sock = 0;
    addr_len = addrlen;
    buffer = (char *)malloc(buff_size);
    client_sock = accept(server_sock,
                         (struct sockaddr *)&address,
                         (socklen_t *)&addr_len);
    while (1)
    {
        if ((bytes_read = recv(client_sock, buffer, buff_size, 0)) > 0)
        {
            printf("recieved request:\n%s\n", buffer);
            bzero(buffer, buff_size);
        }
        else
            client_sock = accept(server_sock,
								 (struct sockaddr *)&address,
								 (socklen_t *)&addr_len);
    }

	return (server_sock);
}

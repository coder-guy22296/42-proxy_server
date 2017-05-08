/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_requests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 17:57:23 by cyildiri          #+#    #+#             */
/*   Updated: 2017/05/07 21:12:04 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proxy.h"

void    handle_requests(int server_sock, int buff_size, struct sockaddr_in *addr, size_t *addrlen)
{
  //size_t		addr_len;
	char	*buffer;
	//char	*request;
	int		bytes_read;
	int		client_sock;

	client_sock = 0;
	//addr_len = sizeof(addr);
	buffer = (char *)malloc(buff_size);
	while (1)
	{
		if ((bytes_read = recv(client_sock, buffer, buff_size, 0)) > 0)
		{
			printf("recieved request:\n%s\n", buffer);
			bzero(buffer, buff_size);
		}	
		else
			client_sock = accept(server_sock,
							(struct sockaddr *)addr,
							(socklen_t *)addrlen);
	}
}

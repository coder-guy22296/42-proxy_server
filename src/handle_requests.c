/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_requests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 17:57:23 by cyildiri          #+#    #+#             */
/*   Updated: 2017/05/07 19:43:33 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proxy.h"

void    handle_requests(int server_sock, int buff_size)
{
	char	*buffer;
	char	*request;
	int		bytes_read;
	int		client_sock;

	buffer = (char *)malloc(buff_size)
	while (1)
	{
		if (bytes_read = recv(client_sock, buffer, buff_size, 0) )
		{
			printf("recieved request:\n%s\n", buffer);
			bzero(buffer, buff_size);
		}	
		else
			client_sock = accept(server_sock,
							(struct sockaddr *)&address,
							(socklen_t *)&addrlen);
	}
}

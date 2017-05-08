/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   web_request.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 22:52:02 by cyildiri          #+#    #+#             */
/*   Updated: 2017/05/07 22:52:05 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proxy.h"

char	*web_request(char *header)
{
	int				socket_con;
	int				bytes;
	struct addrinfo	addr;
	struct addrinfo	*res;
	char			*response;

	response = (char *)calloc(4096, sizeof(char *));
	bzero(&addr, sizeof(struct addrinfo));
	addr.ai_family = AF_UNSPEC;
	addr.ai_socktype = SOCK_STREAM;
	getaddrinfo("www.qst0.com", "80", &addr, &res);
	socket_con = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	connect(socket_con, res->ai_addr, res->ai_addrlen);
	send(socket_con, header, strlen(header), 0);
	bytes = recv(socket_con, response, 4096, 0);
	return (response);
}

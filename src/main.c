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

int main()
{
  	int			server_sock;
	//struct sockaddr_in	addr;

	server_sock = server_socket_setup(PORT);
	printf("listening on port %d!", PORT);
	//handle_requests(server_sock, 2048, &addr);
	return (0);
}

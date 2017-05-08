/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proxy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:48:28 by cyildiri          #+#    #+#             */
/*   Updated: 2017/05/07 17:12:08 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROXY_H
# define PROXY_H
# define PORT 4242

/*
**	does all the neccessary setup for the server socket before we can accept
**	connections
**	@param	port	the port to run the server on
**	@return	the server socket's file descriptor
*/
int		server_socket_setup(int port);

/*
**  forwards all requests to the url in the request to this proxy server
**  @param	server_socket_setup	server socket file descriptor
**	@param	buff_size	size of the buffer used for reading from the socket
**  @return the server	socket's file descriptor
*/
void	handle_requests(int server_sock, int buff_size);

#endif

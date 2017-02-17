/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 05:39:28 by cchaumar          #+#    #+#             */
/*   Updated: 2017/02/17 05:39:29 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_handler.h"

t_gl_buff	*create_buffer(GLuint vao, GLuint type)
{
	t_gl_buff	*buff;

	buff = try(sizeof(t_gl_buff));
	glBindVertexArray(vao);
	glGenBuffers(1, &buff->id);
	glBindBuffer(type, buff->id);
}

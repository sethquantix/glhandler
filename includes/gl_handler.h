/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_handler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:35:24 by cchaumar          #+#    #+#             */
/*   Updated: 2017/02/06 17:36:12 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_HANDLER_H
# define GL_HANDLER_H

#include <unistd.h>
#include <stdlib.h>
#include "GL/glew.h"
#include <OpenGL/GL.h>
#include "libft.h"

# define T_GL_S(x, y)	(t_gl_shader){0, x, y}
# define SZ_S			sizeof(t_gl_shader)

typedef struct		s_gl_shader
{
	GLuint	id;
	GLuint	type;
	char	*file;
}					t_gl_shader;

GLuint		create_program(int shader_count, t_gl_shader *shaders);
void		validate(GLuint program);

#endif

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

/* TODO
** I need a way to properly do this. I wanna be able to instantiate buffer
** relatively to vao (make sense, i guess), with type argument, and fill it
** I want this to be flexible and generic, so I guess I depend on knowing
** what's must have and what's not. maybe keep a reference to the buffer with
** different parameters ? dunno what to do here
*/

// GLuint	create_buffer(GLuint vao, GLuint type)
// {
// 	GLuint	id;
//
// 	glBindVertexArray(vao);
// 	glGenBuffers(1, &id);
// 	glBindBuffer(type, id);
// 	glBindVertexArray(0);
// 	return (id);
// }

static void	gl_compile_log(GLuint shader, char *name)
{
	char	*log_info;
	GLint	size;

	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &size);
	log_info = try(size + 1);
	glGetShaderInfoLog(shader, size, NULL, log_info);
	ft_printf("Error compiling shader ! source name : %s\n%s", name, log_info);
	free(log_info);
}

static void	release_shaders(GLuint program, int shader_count, t_gl_shader *shaders)
{
	int		i;

	i = 0;
	while (i < shader_count)
	{
		glDetachShader(program, shaders[i].id);
		glDeleteShader(shaders[i].id);
		i++;
	}
}

static GLuint	gl_link_info(GLuint program)
{
	int		success;
	char	*log_info;
	GLint	size;

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &size);
		log_info = try(size + 1);
		glGetProgramInfoLog(program, size, NULL, log_info);
		ft_printf("Error linking program\n%s", log_info);
		free(log_info);
		return (0);
	}
	return (program);
}

void			validate(GLuint program)
{
	char	*log_info;
	GLint	size;

	glValidateProgram(program);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &size);
	log_info = try(size + 1);
	glGetProgramInfoLog(program, size, NULL, log_info);
	ft_printf("program validation :\n%s", log_info);
	free(log_info);
}

GLuint			create_program(int shader_count, t_gl_shader *shaders)
{
	GLuint	shader;
	GLuint	program;
	char	*source;
	int		i;
	int		success;

	i = 0;
	program = glCreateProgram();
	while (i < shader_count)
	{
		source = ft_read_file(shaders[i].file);
		shader = glCreateShader(shaders[i].type);
		shaders[i].id = shader;
		glShaderSource(shader, 1, (const GLchar *const *)&source, NULL);
		glCompileShader(shader);
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			release_shaders(program, i, shaders);
			gl_compile_log(shader, shaders[i].file);
			glDeleteProgram(program);
		}
		glAttachShader(program, shader);
		i++;
	}
	glLinkProgram(program);
	release_shaders(program, shader_count, shaders);
	return (gl_link_info(program));
}

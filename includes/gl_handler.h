/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_handler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:35:24 by cchaumar          #+#    #+#             */
/*   Updated: 2017/04/13 03:43:55 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_HANDLER_H
# define GL_HANDLER_H

#include <unistd.h>
#include <stdlib.h>
#include "GL/glew.h"
#include <OpenGL/GL.h>
#include "libft.h"

# define GL_M_SCALE		0
# define GL_M_TRANS		1
# define GL_M_CAM_ROT	2
# define GL_M_CAM_POS	3
# define GL_M_PROJ		4
# define GL_M_WVP		0x01
# define GL_M_VP		0x02
# define GL_M_WV		0x04
# define GL_M_WP		0x08
# define GL_M_W			0x10
# define GL_M_V			0x20

# define GL_IND_VB		0
# define GL_POS_VB		1
# define GL_NORMAL_VB	2
# define GL_TEX_VB		3
# define GL_WVP_VB		4
# define GL_WORLD_VB	5

/*
**	ratio is WIDTH / HEIGHT
*/

# define T_GL_S(x, y)	(t_gl_shader){0, x, y}
# define S_GLS			sizeof(t_gl_shader)
# define GL_AB			GL_ARRAY_BUFFER
# define GL_EAB			GL_ELEMENT_ARRAY_BUFFER
# define GL_VS			GL_VERTEX_SHADER
# define GL_FS			GL_FRAGMENT_SHADER

typedef struct		s_gl_shader
{
	GLuint	id;
	GLuint	type;
	char	*file;
}					t_gl_shader;

typedef struct		s_gl_mesh
{
	GLuint	vao;
	GLuint	mbuffers[6];
}					t_gl_mesh;

typedef struct		s_gl_pipe
{
	t_mat	m_wvp;
	t_mat	m_vp;
	t_mat	m_wp;
	t_mat	m_wv;
	t_mat	m_w;
	t_mat	m_v;
	t_mat	m_proj;
}					t_gl_pipe;

t_mat		gl_proj_mat(float ratio, float near, float far, float fov);
t_mat		gl_rot_mat(float r_x, float r_y, float r_z);
t_mat		gl_trans_mat(float t_x, float t_y, float t_z);
t_mat		gl_scale_mat(float s_x, float s_y, float s_z);
t_mat		gl_cam_mat(t_vec4 dir, t_vec4 r, t_vec4 up);
void		gl_set_matrix(t_gl_pipe *pipe, int type, t_mat mat[5]);
t_mat		gl_get_matrix(t_gl_pipe *pipe, int type);

t_gl_shader	gl_shader(GLuint type, char *file);
GLuint		create_program(int shader_count, t_gl_shader *shaders);
int			compile_shader(t_gl_shader *shader);
void		gl_compile_log(GLuint shader, char *name);
void		validate(GLuint program);

#endif

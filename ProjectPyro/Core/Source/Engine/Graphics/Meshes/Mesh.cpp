#include "stdafx.h"
#include "Mesh.h"


Mesh::Mesh()
	: vertexArrayID_(0), vertexBuffer_(0), vertexBufferData_(nullptr)
{
}


Mesh::~Mesh()
{
}

void Mesh::Init()
{
	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	//Generate and Bind the VAO
	glGenVertexArrays(1, &vertexArrayID_);
	glBindVertexArray(vertexArrayID_);

	//Generate and Bind the buffers
	glGenBuffers(1, &vertexBuffer_);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);

	//pass the vertex data to the buffers
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

}

GLuint Mesh::GetVAO()
{
	return vertexArrayID_;
}

GLuint Mesh::GetBuffers()
{
	return vertexBuffer_;
}

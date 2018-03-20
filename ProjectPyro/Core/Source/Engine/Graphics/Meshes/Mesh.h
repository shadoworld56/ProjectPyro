#pragma once
class Mesh
{
public:
	Mesh();

	~Mesh();

	void Init(void);

	GLuint GetVAO(void);

	GLuint GetBuffers(void);

private:
	GLuint vertexArrayID_;

	GLuint vertexBuffer_;

	GLfloat * vertexBufferData_;
};


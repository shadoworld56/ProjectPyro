///-------------------------------------------------------------------------------------------------
// file:	Source\Engine\Graphics\Meshes\Mesh.h
//
// summary:	Declares the mesh class
///-------------------------------------------------------------------------------------------------

#pragma once

/// <summary>	A mesh. </summary>
class Mesh
{
public:

	/// <summary>	Default constructor. </summary>
	Mesh();

	/// <summary>	Destructor. </summary>
	~Mesh();

	/// <summary>	Initializes this object. </summary>
	void Init(void);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the vao. </summary>
	///
	/// <returns>	The vao. </returns>
	///-------------------------------------------------------------------------------------------------

	GLuint GetVAO(void);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the buffers. </summary>
	///
	/// <returns>	The buffers. </returns>
	///-------------------------------------------------------------------------------------------------

	GLuint GetBuffers(void);

private:
	/// <summary>	Identifier for the vertex array. </summary>
	GLuint vertexArrayID_;

	/// <summary>	Buffer for vertex data. </summary>
	GLuint vertexBuffer_;

	/// <summary>	Information describing the vertex buffer. </summary>
	GLfloat * vertexBufferData_;
};


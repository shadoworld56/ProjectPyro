///-------------------------------------------------------------------------------------------------
// file:	Source\Startup\Core.cpp
//
// summary:	Implements the core class
///-------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "Window/WindowManager.h"
#include "../Engine/Graphics/Meshes/Mesh.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	Main entry-point for this application. </summary>
///
/// <returns>	Exit-code for the process - 0 for success, else an error code. </returns>
///-------------------------------------------------------------------------------------------------

int main()
{
	WindowManager window;

	if(!window.InitMainWindow(1024, 768, "Project: Pyro"))
	{
		return 1;
	}


	Mesh mesh;

	mesh.Init();

	glClearColor(0.1f, 0.0f, 0.0f, 1.0f);
	

	while (window.UpdateMainWindow())
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, mesh.GetBuffers());
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
		glDisableVertexAttribArray(0);
	}

	window.ShutdownMainWindow();
    return 0;
}

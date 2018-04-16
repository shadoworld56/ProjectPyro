///-------------------------------------------------------------------------------------------------
// file:	Source\Startup\Window\WindowManager.cpp
//
// summary:	Implements the window manager class
///-------------------------------------------------------------------------------------------------

#include <stdafx.h>
#include "WindowManager.h"

/// <summary>	Default constructor. </summary>
WindowManager::WindowManager()
{
}

/// <summary>	Destructor. </summary>
WindowManager::~WindowManager()
{
}

///-------------------------------------------------------------------------------------------------
/// <summary>	Initializes the main window. </summary>
///
/// <param name="width"> 	The width. </param>
/// <param name="height">	The height. </param>
/// <param name="title"> 	The title. </param>
///
/// <returns>	True if it succeeds, false if it fails. </returns>
///-------------------------------------------------------------------------------------------------

bool WindowManager::InitMainWindow(int width, int height, std::string title)
{
	if (!glfwInit())
	{
		return false;

	}


	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	mainWindow_ = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!mainWindow_)
	{
		//something went wrong
		glfwTerminate();
		return false;
	}


	glfwMakeContextCurrent(mainWindow_);

	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		//glew failed
		glfwDestroyWindow(mainWindow_);
		glfwTerminate();
		return false;

	}

	return true;
}

///-------------------------------------------------------------------------------------------------
/// <summary>	Updates the main window. </summary>
///
/// <returns>	True if it succeeds, false if it fails. </returns>
///-------------------------------------------------------------------------------------------------

bool WindowManager::UpdateMainWindow()
{
	if(!glfwWindowShouldClose(mainWindow_))
	{
		glfwSwapBuffers(mainWindow_);
		glfwPollEvents();
		return true;
	}
	
	return false;
}

/// <summary>	Shutdown main window. </summary>
void WindowManager::ShutdownMainWindow()
{
	glfwDestroyWindow(mainWindow_);
	glfwTerminate();
}

///-------------------------------------------------------------------------------------------------
/// <summary>	Gets main window. </summary>
///
/// <returns>	Null if it fails, else the main window. </returns>
///-------------------------------------------------------------------------------------------------

GLFWwindow* WindowManager::GetMainWindow()
{
	return mainWindow_;
}

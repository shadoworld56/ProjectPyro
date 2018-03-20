#include <stdafx.h>
#include "WindowManager.h"


WindowManager::WindowManager()
{
}


WindowManager::~WindowManager()
{
}

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

void WindowManager::ShutdownMainWindow()
{
	glfwDestroyWindow(mainWindow_);
	glfwTerminate();
}

GLFWwindow* WindowManager::GetMainWindow()
{
	return mainWindow_;
}

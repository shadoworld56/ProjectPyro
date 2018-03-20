#pragma once

#include <string>
class WindowManager
{
public:
	WindowManager();

	~WindowManager();

	bool InitMainWindow(int width, int height, std::string title);

	bool UpdateMainWindow(void);

	void ShutdownMainWindow(void);

	GLFWwindow * GetMainWindow(void);

private:
	GLFWwindow * mainWindow_;
};


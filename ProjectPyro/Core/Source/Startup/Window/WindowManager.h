///-------------------------------------------------------------------------------------------------
// file:	Source\Startup\Window\WindowManager.h
//
// summary:	Declares the window manager class
///-------------------------------------------------------------------------------------------------

#pragma once

#include <string>

/// <summary>	Manager for windows. </summary>
class WindowManager
{
public:

	/// <summary>	Default constructor. </summary>
	WindowManager();

	/// <summary>	Destructor. </summary>
	~WindowManager();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Initializes the main window. </summary>
	///
	/// <param name="width"> 	The width. </param>
	/// <param name="height">	The height. </param>
	/// <param name="title"> 	The title. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	///-------------------------------------------------------------------------------------------------

	bool InitMainWindow(int width, int height, std::string title);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Updates the main window. </summary>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	///-------------------------------------------------------------------------------------------------

	bool UpdateMainWindow(void);

	/// <summary>	Shutdown main window. </summary>
	void ShutdownMainWindow(void);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets main window. </summary>
	///
	/// <returns>	Null if it fails, else the main window. </returns>
	///-------------------------------------------------------------------------------------------------

	GLFWwindow * GetMainWindow(void);

private:
	/// <summary>	The main window. </summary>
	/// <summary>	The main window. </summary>
	GLFWwindow * mainWindow_;
};


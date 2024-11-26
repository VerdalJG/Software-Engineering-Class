#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "../swalib_example/Code/Game/global.h"
#include "../swalib_example/Code/Game/logic.h"
#include "../swalib_example/Code/Game/render.h"
#include "../swalib_example/swalib_example/NewWorld.h"

//-----------------------------------------------------------------------------
int Main(void)
{
	// Initialization.
	InitRender();
	//InitGlobalData();
	InitNewGlobalData();

	// Main loop.
	while (!SYS_GottaQuit()) {	// Controlling a request to terminate an application.
		LogicSlot();	// Logic slot.
		RenderSlot();	// Render slot.
   
		SYS_Pump();	// Process Windows messages.
		SYS_Sleep(17);	// To force 60 fps
	}

	// Shutdown. In reverse order to initilization.
	//ShutDownGlobalData();
	ShutDownNewGlobalData();
	ShutDownRender();

	return 0;
}

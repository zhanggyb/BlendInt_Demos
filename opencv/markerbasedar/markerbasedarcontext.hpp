/*
 * A context works in GLFW
 */

#ifndef _MARKERBASEDARCONTEXT_HPP_
#define _MARKERBASEDARCONTEXT_HPP_

#include <GLFW/glfw3.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <gui/window.hpp>
#include <gui/toolbox.hpp>

#include <gui/cvvideoviewport.hpp>
#include <core/timer.hpp>
#include <gui/button.hpp>
#include <gui/toggle-button.hpp>

#include "mbarviewport.hpp"

namespace BI=BlendInt;

class MarkerBasedARContext: public BI::Window
{
public:

	explicit MarkerBasedARContext (int width, int height, const char* name);

	virtual ~MarkerBasedARContext ();

protected:

private:

	BI::ToolBox* CreateToolBoxOnce ();

	BI::ToolBox* CreateToolBarOnce ();

	void OnResize(Window* window, const BI::Size& size);

	void OnToggleCamera (BI::AbstractButton* sender, bool toggled);

	void OnPlay (BI::AbstractButton* sender);

	void OnPause (BI::AbstractButton* sender);

	void OnStop(BI::AbstractButton* sender);

	MBARViewport* viewport_;

	BI::FrameSplitter* main_frame_;


};

#endif /* _MARKERBASEDARCONTEXT_HPP_ */

/*
 * A context works in GLFW
 */

#ifndef _HPECONTEXT_HPP_
#define _HPECONTEXT_HPP_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <gui/window.hpp>
#include <gui/frame.hpp>

#include <gui/image-viewport.hpp>
#include <core/timer.hpp>
#include <gui/viewport.hpp>
#include <gui/panel.hpp>
#include <gui/frame-splitter.hpp>

#include <gui/button.hpp>
#include <gui/workspace.hpp>
#include <gui/linear-layout.hpp>
#include <gui/button-group.hpp>

namespace BI=BlendInt;

class HPEWindow: public BI::Window
{
public:

	HPEWindow (int width, int height, const char* name);

	virtual ~HPEWindow ();

private:

	enum Status {
		VideoPlay,
		VideoPause,
		VideoStop
	};

	BI::Frame* CreateToolBarOnce ();

	BI::Panel* CreateButtons ();

	BI::Workspace* CreateWorkspaceOnce ();

	BI::Workspace* CreateToolsOnce ();

	BI::Frame* CreateRadios ();

	bool OpenCamera (int n, const BI::Size& resolution = BI::Size(640, 480));

	void OnResize(Window* window, const BI::Size& size);

	BI::Viewport* viewport_3d_;

	BI::RefPtr<BI::ButtonGroup> radio_group_;

	BI::FrameSplitter* main_frame_;

};

#endif /* _HPECONTEXT_HPP_ */

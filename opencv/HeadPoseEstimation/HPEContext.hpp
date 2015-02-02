/*
 * A context works in GLFW
 */

#ifndef _HPECONTEXT_HPP_
#define _HPECONTEXT_HPP_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <BlendInt/Gui/Window.hpp>
#include <BlendInt/Gui/ToolBox.hpp>

#include <BlendInt/Gui/ImageViewport.hpp>
#include <BlendInt/Core/Timer.hpp>
#include <BlendInt/Gui/Viewport.hpp>
#include <BlendInt/Gui/Panel.hpp>
#include <BlendInt/Gui/FrameSplitter.hpp>

#include <BlendInt/Gui/Button.hpp>
#include <BlendInt/Gui/Workspace.hpp>
#include <BlendInt/Gui/LinearLayout.hpp>
#include <BlendInt/Gui/ButtonGroup.hpp>

namespace BI=BlendInt;

class HPEContext: public BI::Window
{
public:

	HPEContext (int width, int height, const char* name);

	virtual ~HPEContext ();

private:

	enum Status {
		VideoPlay,
		VideoPause,
		VideoStop
	};

	BI::ToolBox* CreateToolBarOnce ();

	BI::Panel* CreateButtons ();

	BI::Workspace* CreateWorkspaceOnce ();

	BI::Workspace* CreateToolsOnce ();

	BI::ToolBox* CreateRadios ();

	bool OpenCamera (int n, const BI::Size& resolution = BI::Size(640, 480));

	void OnResize(Window* window, const BI::Size& size);

	BI::Viewport* viewport_3d_;

	BI::RefPtr<BI::ButtonGroup> radio_group_;

	BI::FrameSplitter* main_frame_;

};

#endif /* _HPECONTEXT_HPP_ */

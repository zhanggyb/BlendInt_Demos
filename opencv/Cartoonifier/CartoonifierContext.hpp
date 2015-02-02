/*
 * A context works in GLFW
 */

#ifndef _CARTOONIFIERCONTEXT_HPP_
#define _CARTOONIFIERCONTEXT_HPP_

#include <BlendInt/Gui/Window.hpp>
#include <BlendInt/Gui/ToolBox.hpp>

#include <BlendInt/Gui/CVVideoViewport.hpp>
#include <BlendInt/Gui/Button.hpp>

namespace BI=BlendInt;

class CartoonifierContext: public BI::Window
{
public:
	CartoonifierContext (int width, int height, const char* name);

	virtual ~CartoonifierContext ();

private:

	BI::ToolBox* CreateToolBoxOnce ();

	void OnResize (BI::Window* window, const BI::Size& size);

	void OnPlay (BI::AbstractButton* sender);

	void OnPause (BI::AbstractButton* sender);

	void OnStop(BI::AbstractButton* sender);

	BI::CVVideoViewport* video_;

	BI::FrameSplitter* main_frame_;
};

#endif /* _CARTOONIFIERCONTEXT_HPP_ */

/*
 * A context works in GLFW
 */

#ifndef _CARTOONIFIERCONTEXT_HPP_
#define _CARTOONIFIERCONTEXT_HPP_

#include <gui/window.hpp>
#include <gui/toolbox.hpp>

#include <gui/cvvideoviewport.hpp>
#include <gui/button.hpp>

namespace BI=BlendInt;

class CartoonifierWindow: public BI::Window
{
public:
	CartoonifierWindow (int width, int height, const char* name);

	virtual ~CartoonifierWindow ();

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

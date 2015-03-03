/*
 * A context works in GLFW
 */

#ifndef _MARKERBASEDARCONTEXT_HPP_
#define _MARKERBASEDARCONTEXT_HPP_

#include <GLFW/glfw3.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <gui/window.hpp>
#include <gui/frame.hpp>

#include <core/timer.hpp>
#include <gui/button.hpp>
#include <gui/toggle-button.hpp>

#include "mbar-image-view.hpp"

namespace BI=BlendInt;

class MBARWindow: public BI::Window
{
public:

	explicit MBARWindow (int width, int height, const char* name);

	virtual ~MBARWindow ();

protected:

private:

	BI::Frame* CreateToolBoxOnce ();

	BI::Frame* CreateToolBarOnce ();

	void OnResize(Window* window, const BI::Size& size);

	void OnToggleCamera (BI::AbstractButton* sender, bool toggled);

	void OnPlay (BI::AbstractButton* sender);

	void OnPause (BI::AbstractButton* sender);

	void OnStop(BI::AbstractButton* sender);

	MBARView* image_view_;

	BI::FrameSplitter* main_frame_;

};

#endif /* _MARKERBASEDARCONTEXT_HPP_ */

/*
 * A context works in GLFW
 */

#ifndef GLFWCONTEXT_HPP_
#define GLFWCONTEXT_HPP_

#include <GLFW/glfw3.h>

#include <vector>

#include <gui/push-button.hpp>
#include <gui/clock.hpp>
#include <gui/combo-box.hpp>
#include <gui/toggle-button.hpp>
#include <gui/linear-layout.hpp>
#include <gui/label.hpp>
#include <gui/slider.hpp>
#include <gui/panel.hpp>
#include <gui/vector-icon.hpp>
#include <gui/scroll-bar.hpp>
#include <gui/scroll-view.hpp>
#include <gui/menu.hpp>
#include <gui/texture-view.hpp>
#include <gui/textentry.hpp>
#include <gui/viewport3d.hpp>
#include <gui/numerical-slider.hpp>
#include <gui/scroll-area.hpp>
#include <gui/tool-button.hpp>
#include <gui/separator.hpp>
#include <gui/color-selector.hpp>
#include <gui/frame.hpp>
#include <gui/tab.hpp>
#include <gui/tab-button.hpp>
#include <gui/tab-header.hpp>
#include <gui/expander.hpp>
#include <gui/color-button.hpp>

#include <stock/icons.hpp>
#include <gui/file-selector.hpp>
#include <gui/block.hpp>

#include <gui/panel.hpp>
#include <gui/node-view.hpp>
#include <gui/progress-bar.hpp>
#include <gui/workspace.hpp>
#include <gui/list-view.hpp>

#include <gui/model-viewport.hpp>
#include <gui/window.hpp>
#include <gui/dialog.hpp>

namespace BI=BlendInt;

class GalleryWindow: public BI::Window
{
public:

	GalleryWindow(int width, int height, const char* name);

	virtual ~GalleryWindow();

private:

	BI::Frame* CreateTools ();

	BI::Workspace* CreateNodeSpace ();

	BI::Workspace* CreateViewportSpace ();

	BI::Dialog* CreateWidgetsDialog ();

	void OnResize (const BI::Size& size);

	BI::ModelViewport* viewport_;

	BI::Frame* tools_;

	BI::FrameSplitter* splitter_;

	BI::Dialog* widgets_dialog_;
};


#endif /* GLFWCONTEXT_HPP_ */

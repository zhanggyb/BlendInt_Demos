/*
 * A context works in GLFW
 */

#ifndef STUDIOCONTEXT_HPP_
#define STUDIOCONTEXT_HPP_

#include <GLFW/glfw3.h>

#include <gui/button.hpp>
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
#include <gui/tabheader.hpp>
#include <gui/expander.hpp>
#include <gui/color-button.hpp>

#include <stock/icons.hpp>
#include <gui/file-selector.hpp>
#include <gui/block.hpp>
#include <gui/panel.hpp>

#include <gui/panel.hpp>
#include <gui/node-view.hpp>
#include <gui/progress-bar.hpp>
#include <gui/workspace.hpp>
#include <gui/list-view.hpp>
#include <gui/texture-view.hpp>
#include <gui/frame.hpp>
#include <gui/dialog.hpp>

#include <gui/window.hpp>

namespace BI=BlendInt;

class StudioWindow: public BI::Window
{
public:

	StudioWindow (int width, int height, const char* name);

	virtual ~StudioWindow ();

private:

	BI::Frame* CreateToolBar ();

	void OnResize(Window* window, const BI::Size& size);

	void OnTakeScreenshot (BI::AbstractButton* sender);

	void OnOpenDialogForButtons ();

	void OnOpenDialogForTextureView ();

	void OnOpenModalDialog ();

	void OnOpenFileSelector ();

	void OnOpenDialogForNumericalSlider ();

	void OnOpenDialogForScrollView ();

	void OnOpenDialogForBlocks ();

	void OnOpenDialogForClock ();

	void OnOpenMenu1 ();

	void OnOpenPanel (BI::AbstractButton* btn);

	void OnOpenDialogForTab ();

	void OnOpenDialogForScrollArea ();

	void OnOpenDialogForTabHeader ();

	void OnTestAdaptiveLayout (BI::AbstractButton* sender);

	BI::Button* button_;

	//BI::PopupFrame* pop_;

	BI::Frame* toolbar_;
};

#endif /* STUDIOCONTEXT_HPP_ */

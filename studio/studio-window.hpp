/*
 * A context works in GLFW
 */

#ifndef STUDIOCONTEXT_HPP_
#define STUDIOCONTEXT_HPP_

#include <GLFW/glfw3.h>

#include <blendint/gui/push-button.hpp>
#include <blendint/gui/clock.hpp>
#include <blendint/gui/combo-box.hpp>
#include <blendint/gui/toggle-button.hpp>
#include <blendint/gui/linear-layout.hpp>
#include <blendint/gui/label.hpp>
#include <blendint/gui/slider.hpp>
#include <blendint/gui/panel.hpp>
#include <blendint/gui/vector-icon.hpp>
#include <blendint/gui/scroll-bar.hpp>
#include <blendint/gui/scroll-view.hpp>
#include <blendint/gui/menu.hpp>
#include <blendint/gui/textentry.hpp>
#include <blendint/gui/viewport3d.hpp>
#include <blendint/gui/numerical-slider.hpp>
#include <blendint/gui/scroll-area.hpp>
#include <blendint/gui/tool-button.hpp>
#include <blendint/gui/separator.hpp>
#include <blendint/gui/color-selector.hpp>
#include <blendint/gui/frame.hpp>
#include <blendint/gui/tab.hpp>
#include <blendint/gui/tab-button.hpp>
#include <blendint/gui/tab-header.hpp>
#include <blendint/gui/expander.hpp>
#include <blendint/gui/color-button.hpp>

#include <blendint/stock/icons.hpp>
#include <blendint/gui/file-selector.hpp>
#include <blendint/gui/block.hpp>
#include <blendint/gui/panel.hpp>

#include <blendint/gui/panel.hpp>
#include <blendint/gui/node-view.hpp>
#include <blendint/gui/progress-bar.hpp>
#include <blendint/gui/workspace.hpp>
#include <blendint/gui/list-view.hpp>
#include <blendint/gui/texture-view.hpp>
#include <blendint/gui/frame.hpp>
#include <blendint/gui/dialog.hpp>

#include <blendint/gui/window.hpp>

namespace BI=BlendInt;

class StudioWindow: public BI::Window
{
public:

	StudioWindow (int width, int height, const char* name);

	virtual ~StudioWindow ();

private:

	BI::Frame* CreateToolBar ();

	void OnResize(const BI::Size& size);

	void OnTakeScreenshot ();

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

	void OnTestAdaptiveLayout ();

	BI::PushButton* button_;

	//BI::PopupFrame* pop_;

	BI::Frame* toolbar_;
};

#endif /* STUDIOCONTEXT_HPP_ */

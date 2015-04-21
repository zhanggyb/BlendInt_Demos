/*
 * A context works in GLFW
 */

#ifndef _FONTVIEWERCONTEXT_HPP_
#define _FONTVIEWERCONTEXT_HPP_

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

#include <blendint/gui/window.hpp>

namespace BI = BlendInt;

class FontViewerWindow: public BI::Window
{
public:

  FontViewerWindow (int width, int height, const char* name);

  virtual ~FontViewerWindow ();

private:

  void OnResize (const BI::Size& size);

  BI::Frame* CreateMenuBar ();

  void OnOpen ();

#ifdef __USE_OPENCV__
  void OnOpenCVImageView ();
#endif

  void OnOpenClock ();

  void OnOpenComboBox ();

  void OnOpenListView ();

  void OnTestNodeView ();

  void OnTestMenu ();

  BI::Frame* menubar_;
};

#endif /* _FONTVIEWERCONTEXT_HPP_ */

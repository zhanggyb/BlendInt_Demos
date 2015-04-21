/*
 * A context works in GLFW
 */

#ifndef _HPECONTEXT_HPP_
#define _HPECONTEXT_HPP_

#include <blendint/core/timer.hpp>

#include <blendint/gui/window.hpp>
#include <blendint/gui/frame.hpp>

#include <blendint/gui/image-viewport.hpp>
#include <blendint/gui/model-viewport.hpp>
#include <blendint/gui/panel.hpp>
#include <blendint/gui/frame-splitter.hpp>
#include <blendint/gui/cv-image-view.hpp>
#include <blendint/gui/node.hpp>
#include <blendint/gui/node-view.hpp>
#include <blendint/gui/label.hpp>
#include <blendint/gui/texture-view.hpp>

#include <blendint/gui/push-button.hpp>
#include <blendint/gui/workspace.hpp>
#include <blendint/gui/linear-layout.hpp>
#include <blendint/gui/button-group.hpp>

#include "cv-space.hpp"

namespace BI = BlendInt;

class HPEWindow: public BI::Window
{
public:

  HPEWindow (int width, int height, const char* name);

  virtual ~HPEWindow ();

private:

  BI::Frame* CreateToolBarOnce ();

  BI::Panel* CreateButtons ();

  BI::Workspace* CreateViewportSpace ();

  BI::Workspace* CreateToolSpace ();

  BI::Workspace* CreateNodeSpace ();

  BI::Frame* CreateRadios ();

  bool OpenCamera (int n, const BI::Size& resolution = BI::Size(640, 480));

  void OnResize (const BI::Size& size);

  BI::ModelViewport* viewport_3d_;

  BI::RefPtr<BI::ButtonGroup> radio_group_;

  BI::FrameSplitter* main_frame_;

  CVSpace* cv_space_;
};

#endif /* _HPECONTEXT_HPP_ */

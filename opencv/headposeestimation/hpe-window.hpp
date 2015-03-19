/*
 * A context works in GLFW
 */

#ifndef _HPECONTEXT_HPP_
#define _HPECONTEXT_HPP_

#include <core/timer.hpp>

#include <gui/window.hpp>
#include <gui/frame.hpp>

#include <gui/image-viewport.hpp>
#include <gui/model-viewport.hpp>
#include <gui/panel.hpp>
#include <gui/frame-splitter.hpp>
#include <gui/cv-image-view.hpp>
#include <gui/node.hpp>
#include <gui/node-view.hpp>
#include <gui/label.hpp>
#include <gui/texture-view.hpp>

#include <gui/button.hpp>
#include <gui/workspace.hpp>
#include <gui/linear-layout.hpp>
#include <gui/button-group.hpp>

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

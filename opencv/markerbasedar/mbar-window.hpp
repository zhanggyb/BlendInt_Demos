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
#include <gui/push-button.hpp>
#include <gui/toggle-button.hpp>

#include "mbar-image-view.hpp"

namespace BI = BlendInt;

class MBARWindow: public BI::Window
{
public:

  explicit MBARWindow (int width, int height, const char* name);

  virtual ~MBARWindow ();

protected:

private:

  BI::Frame* CreateToolBoxOnce ();

  BI::Frame* CreateToolBarOnce ();

  void OnResize (const BI::Size& size);

  void OnToggleCamera (bool toggled);

  void OnPlay ();

  void OnPause ();

  void OnStop ();

  MBARView* image_view_;

  BI::FrameSplitter* main_frame_;

};

#endif /* _MARKERBASEDARCONTEXT_HPP_ */

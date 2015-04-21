/*
 * A context works in GLFW
 */

#ifndef _CARTOONIFIERCONTEXT_HPP_
#define _CARTOONIFIERCONTEXT_HPP_

#include <blendint/gui/window.hpp>
#include <blendint/gui/frame.hpp>

#include <blendint/gui/frame.hpp>
#include <blendint/gui/push-button.hpp>
#include <blendint/gui/cv-image-view.hpp>

#include "cartoon-image-view.hpp"

namespace BI = BlendInt;

class CartoonifierWindow: public BI::Window
{
public:
  CartoonifierWindow (int width, int height, const char* name);

  virtual ~CartoonifierWindow ();

private:

  BI::Frame* CreateToolBoxOnce ();

  void OnResize (const BI::Size& size);

  void OnPlay ();

  void OnPause ();

  void OnStop ();

  CartoonImageView* cv_view_;

  BI::FrameSplitter* main_frame_;
};

#endif /* _CARTOONIFIERCONTEXT_HPP_ */

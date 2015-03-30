// cv-space.hpp

#pragma once

#include <gui/workspace.hpp>
#include <gui/cv-image-view.hpp>

namespace BI = BlendInt;

class CVSpace: public BI::Workspace
{
public:

  CVSpace ();

  virtual ~CVSpace ();

  virtual bool IsExpandX () const;

  virtual bool IsExpandY () const;

private:

  BI::CVImageView* img_view_;

  BI::Frame* CreateHeader ();

  void OnOpenCamera ();

  void OnPlay ();

  void OnPause ();

};

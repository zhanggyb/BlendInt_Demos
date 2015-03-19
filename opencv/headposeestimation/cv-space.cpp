/*
 * cv-space.cpp
 *
 *  Created on: 2015年3月19日
 *      Author: zhanggyb
 */

#include <gui/linear-layout.hpp>
#include <gui/cv-image-view.hpp>
#include <gui/menu-button.hpp>
#include <gui/combo-box.hpp>
#include <gui/frame.hpp>
#include <gui/button.hpp>

#include "cv-space.hpp"

using namespace BlendInt;

CVSpace::CVSpace ()
{
  Frame* header = CreateHeader();

  LinearLayout* vlayout = new LinearLayout(Vertical);
  vlayout->SetMargin(Margin(0, 0, 0, 0));
  Frame* image_frame = new Frame(vlayout);

  CVImageView* img_view = new CVImageView;
  image_frame->AddWidget(img_view);

  SetHeaderFrame(header);
  SetMainFrame(image_frame);
}

CVSpace::~CVSpace ()
{
}

bool CVSpace::IsExpandX () const
{
  return true;
}

bool CVSpace::IsExpandY () const
{
  return true;
}

Frame* CVSpace::CreateHeader ()
{
  LinearLayout* layout = new LinearLayout(Horizontal);
  layout->SetMargin(Margin(2, 2, 2, 2));

  Frame* header = new Frame(layout);
  header->EnableViewBuffer();

  ComboBox* combo = new ComboBox;

  MenuButton* btn1 = new MenuButton("File");
  MenuButton* btn2 = new MenuButton("Edit");
  MenuButton* btn3 = new MenuButton("View");

  header->AddWidget(combo);
  header->AddWidget(btn1);
  header->AddWidget(btn2);
  header->AddWidget(btn3);

  Button* open_button = new Button(AbstractWindow::icons()->icon_16x16(Icons::FILE_IMAGE), "Open");
  header->AddWidget(open_button);

  header->Resize(header->GetPreferredSize());

  return header;
}

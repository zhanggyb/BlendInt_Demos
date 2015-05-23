/*
 * cv-space.cpp
 *
 *  Created on: 2015年3月19日
 *      Author: zhanggyb
 */

#include <blendint/gui/linear-layout.hpp>
#include <blendint/gui/cv-image-view.hpp>
#include <blendint/gui/menu-button.hpp>
#include <blendint/gui/combo-box.hpp>
#include <blendint/gui/frame.hpp>
#include <blendint/gui/push-button.hpp>
#include <blendint/gui/block.hpp>

#include "cv-space.hpp"

using namespace BlendInt;

CVSpace::CVSpace ()
: Workspace(),
  img_view_(0)
{
  Frame* header = CreateHeader();

  LinearLayout* vlayout = new LinearLayout(Vertical);
  vlayout->SetMargin(Margin(0, 0, 0, 0));
  Frame* image_frame = new Frame(vlayout);

  img_view_ = new CVImageView;
  image_frame->AddWidget(img_view_);

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

  PushButton* open_button = new PushButton(icons()->icon_16x16(Icons::SCENE), "Open Camera");
  header->AddWidget(open_button);

  Block* block = new Block;
  PushButton* b1 = new PushButton(icons()->icon_16x16(Icons::PLAY));
  PushButton* b2 = new PushButton(icons()->icon_16x16(Icons::PAUSE));

  block->AddWidget(b1);
  block->AddWidget(b2);

  header->AddWidget(block);

  header->Resize(header->GetPreferredSize());

  open_button->clicked().connect(this, &CVSpace::OnOpenCamera);
  b1->clicked().connect(this, &CVSpace::OnPlay);
  b2->clicked().connect(this, &CVSpace::OnPause);

  return header;
}

void CVSpace::OnOpenCamera ()
{
#ifdef __APPLE__
    img_view_->OpenCamera(0, 15, Size(1080, 720));
#else
    img_view_->OpenCamera(0, 15, Size(640, 480));
#endif
}

void CVSpace::OnPlay ()
{
  img_view_->Play();
}

void CVSpace::OnPause ()
{
  img_view_->Pause();
}

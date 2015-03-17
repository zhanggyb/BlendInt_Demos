/*
 * GLFWContext.cpp
 */

#include "font-viewer-window.hpp"

#include <gui/abstract-round-frame.hpp>
#include <gui/menu-button.hpp>
#include <gui/clock.hpp>
#include <gui/scroll-area.hpp>
#include <gui/tab-header.hpp>
#include <gui/dialog.hpp>
#include <gui/cv-image-view.hpp>
#include <gui/string-list-model.hpp>
#include <gui/node.hpp>

using namespace BI;

FontViewerWindow::FontViewerWindow (int width, int height, const char* name)
: BI::Window(width, height, name), menubar_(nullptr)
{
  menubar_ = CreateMenuBar();
  AddFrame(menubar_);

  OnResize(size());

  events()->connect(resized(), this, &FontViewerWindow::OnResize);
}

FontViewerWindow::~FontViewerWindow ()
{

}

void FontViewerWindow::OnResize (const BI::Size& size)
{
  Size menubar_size = menubar_->GetPreferredSize();

  menubar_->MoveTo(0, size.height() - menubar_size.height());
  menubar_->Resize(size.width(), menubar_size.height());
}

BI::Frame* FontViewerWindow::CreateMenuBar ()
{
  LinearLayout* layout = new LinearLayout(Horizontal);
  layout->SetMargin(Margin(0, 0, 0, 0));

  Frame* menubar = new Frame(layout);
  menubar->MoveTo(0, size().height() - menubar->size().height());

  MenuButton* menubtn1 = new MenuButton("Open");
  menubar->AddWidget(menubtn1);
  events()->connect(menubtn1->clicked(), this, &FontViewerWindow::OnOpen);

  MenuButton* menubtn2 = new MenuButton("Test CVImageView");
  menubar->AddWidget(menubtn2);

#ifdef __USE_OPENCV__
  events()->connect(menubtn2->clicked(), this,
                    &FontViewerWindow::OnOpenCVImageView);
#endif

  MenuButton* menubtn3 = new MenuButton("Test RequestDraw");
  menubar->AddWidget(menubtn3);

  events()->connect(menubtn3->clicked(), this, &FontViewerWindow::OnOpenClock);

  MenuButton* menubtn4 = new MenuButton("Test ComboBox");
  menubar->AddWidget(menubtn4);

  events()->connect(menubtn4->clicked(), this,
                    &FontViewerWindow::OnOpenComboBox);

  MenuButton* menubtn5 = new MenuButton("Test ListView");
  menubar->AddWidget(menubtn5);

  events()->connect(menubtn5->clicked(), this,
                    &FontViewerWindow::OnOpenListView);

  MenuButton* menubtn6 = new MenuButton("Test NodeView");
  menubar->AddWidget(menubtn6);

  events()->connect(menubtn6->clicked(), this,
                    &FontViewerWindow::OnTestNodeView);

  MenuButton* menubtn7 = new MenuButton("Test Menu");
  menubar->AddWidget(menubtn7);

  events()->connect(menubtn7->clicked(), this, &FontViewerWindow::OnTestMenu);

  return menubar;
}

void FontViewerWindow::OnOpen ()
{
  Dialog* dialog = new Dialog("Font Viewer");

  TextureView* textureview = new TextureView;
  textureview->MoveTo(50, 50);

  Font font;

  // textureview->SetTexture(font.GetTexture(L'A'));

  LinearLayout* layout = new LinearLayout(Vertical);
  layout->AddWidget(textureview);

  // dialog->SetLayout(layout);

  dialog->Resize(textureview->size().width() + 100,
                 textureview->size().height() + 100);
  dialog->MoveTo((size().width() - dialog->size().width()) / 2,
                 (size().height() - dialog->size().height()) / 2);
//	dialog->AddWidget(textureview);

  dialog->Resize(520, 520);

  AddFrame(dialog);

  AbstractWindow* off_screen = CreateSharedContext(size().width(),
                                                   size().height(), false);

  assert(off_screen);

  delete off_screen;
}

#ifdef __USE_OPENCV__

void FontViewerWindow::OnOpenCVImageView ()
{
  Dialog* dlg = new Dialog("CV Image", new LinearLayout(Vertical));

  CVImageView* view = new CVImageView;
  dlg->AddWidget(view);

  AddFrame(dlg);

//	view->OpenFile("test.jpg");
  view->OpenCamera(0, 15);
  view->Play();
}

#endif

void FontViewerWindow::OnOpenClock ()
{
  Dialog* dlg = new Dialog("Clock1", new LinearLayout(Vertical));

  Clock* view = new Clock;
  dlg->AddWidget(view);
  dlg->Resize(dlg->GetPreferredSize());
  dlg->MoveTo(200, 200);

  AddFrame(dlg);

  view->Start();
}

void FontViewerWindow::OnOpenComboBox ()
{
  Dialog* frame = new Dialog("ComboBox test", new LinearLayout(Vertical));

  RefPtr<StringListModel> model(new StringListModel);
  model->AddString("Row 0");
  model->AddString("Row 1");
  model->AddString("Row 2");

  model->Print();

  ComboBox* widget = new ComboBox;
  widget->SetModel(model);

  frame->AddWidget(widget);
  frame->Resize(frame->GetPreferredSize());
  frame->MoveTo((size().width() - frame->size().width()) / 2,
                (size().height() - frame->size().height()) / 2);

  AddFrame(frame);
}

void FontViewerWindow::OnOpenListView ()
{
  Dialog* frame = new Dialog("ComboBox test", new LinearLayout(Vertical));

  RefPtr<StringListModel> model(new StringListModel);
  model->AddString("Row 0");
  model->AddString("Row 1");
  model->AddString("Row 2");

  model->Print();

  ListView* widget = new ListView;
  widget->SetModel(model);

  frame->AddWidget(widget);
  frame->Resize(frame->GetPreferredSize());
  frame->MoveTo((size().width() - frame->size().width()) / 2,
                (size().height() - frame->size().height()) / 2);

  AddFrame(frame);
}

void FontViewerWindow::OnTestNodeView ()
{
  Frame* f1 = new Frame(new LinearLayout(Vertical));
  Frame* f2 = new Frame(new LinearLayout(Vertical));

  NodeView* widget = new NodeView;

  f1->AddWidget(widget);

  Label* label = new Label("Example Node");
  NumericalSlider* ns1 = new NumericalSlider;
  NumericalSlider* ns2 = new NumericalSlider;
  NumericalSlider* ns3 = new NumericalSlider;

  Node* node = new Node(new LinearLayout(Vertical), 0x9F9F9F9F);
  node->AddWidget(label);
  node->AddWidget(ns1);
  node->AddWidget(ns2);
  node->AddWidget(ns3);

  node->Resize(node->GetPreferredSize());

  widget->AddNode(node);

  f1->Resize(800, 600);
  f1->MoveTo(20, 60);

  f2->MoveTo(size().width() - f2->size().width() - 20, 300);

  AddFrame(f1);
  AddFrame(f2);
}

void FontViewerWindow::OnTestMenu ()
{
  Menu* frame = new Menu;
  frame->AddAction(icons()->icon_16x16(Icons::IMAGE_ALPHA), "Hello!",
                   "Ctrl + A");
  frame->AddAction(icons()->icon_16x16(Icons::IMAGE_DATA), "Wooo", "Ctrl + B");

  frame->Resize(frame->GetPreferredSize());
  frame->MoveTo((size().width() - frame->size().width()) / 2,
                (size().height() - frame->size().height()) / 2);

  AddFrame(frame);
}

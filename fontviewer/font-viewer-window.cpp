/*
 * GLFWContext.cpp
 */

#include "font-viewer-window.hpp"

#include <blendint/gui/abstract-round-frame.hpp>
#include <blendint/gui/menu-button.hpp>
#include <blendint/gui/clock.hpp>
#include <blendint/gui/scroll-area.hpp>
#include <blendint/gui/tab-header.hpp>
#include <blendint/gui/dialog.hpp>
#include <blendint/gui/cv-image-view.hpp>
#include <blendint/gui/string-list-model.hpp>
#include <blendint/gui/node.hpp>

using namespace BI;

FontViewerWindow::FontViewerWindow (int width, int height, const char* name)
: BI::Window(width, height, name), menubar_(nullptr)
{
  menubar_ = CreateMenuBar();
  AddFrame(menubar_);

  OnResize(size());

  resized().connect(this, &FontViewerWindow::OnResize);
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
  menubtn1->clicked().connect(this, &FontViewerWindow::OnOpen);

  MenuButton* menubtn2 = new MenuButton("Test CVImageView");
  menubar->AddWidget(menubtn2);

#ifdef __USE_OPENCV__
  menubtn2->clicked().connect(this,
                    &FontViewerWindow::OnOpenCVImageView);
#endif

  MenuButton* menubtn3 = new MenuButton("Test RequestDraw");
  menubar->AddWidget(menubtn3);

  menubtn3->clicked().connect(this, &FontViewerWindow::OnOpenClock);

  MenuButton* menubtn4 = new MenuButton("Test ComboBox");
  menubar->AddWidget(menubtn4);

  menubtn4->clicked().connect(this,
                    &FontViewerWindow::OnOpenComboBox);

  MenuButton* menubtn5 = new MenuButton("Test ListView");
  menubar->AddWidget(menubtn5);

  menubtn5->clicked().connect(this,
                    &FontViewerWindow::OnOpenListView);

  MenuButton* menubtn6 = new MenuButton("Test NodeView");
  menubar->AddWidget(menubtn6);

  menubtn6->clicked().connect(this,
                    &FontViewerWindow::OnTestNodeView);

  MenuButton* menubtn7 = new MenuButton("Test Menu");
  menubar->AddWidget(menubtn7);

  menubtn7->clicked().connect(this, &FontViewerWindow::OnTestMenu);

  return menubar;
}

void FontViewerWindow::OnOpen ()
{
  Dialog* dialog = new Dialog("Font Viewer");

  TextureView* textureview = new TextureView;
  textureview->MoveTo(50, 50);

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

  RefPtr<ComboListModel> model(new ComboListModel);
  ModelIndex root = model->GetRootIndex();

  model->InsertColumns(0, 2, root);
  model->InsertRows(1, 1, root);
  model->InsertRows(2, 1, root);

  ModelIndex index = root.GetChildIndex(0, 0);
  ModelIndex next;

  model->SetIcon(index, icons()->icon_16x16(Icons::IMAGE_RGB));
  next = index.GetRightIndex();
  model->SetText(next, RefPtr<Text>(new Text("Row 0")));

  index = index.GetDownIndex();
  model->SetIcon(index, icons()->icon_16x16(Icons::IMAGE_RGB_ALPHA));
  next = index.GetRightIndex();
  model->SetText(next, RefPtr<Text>(new Text("Row 1")));

  index = index.GetDownIndex();
  model->SetIcon(index, icons()->icon_16x16(Icons::IMAGE_DATA));
  next = index.GetRightIndex();
  model->SetText(next, RefPtr<Text>(new Text("Row 2")));

  ComboBox* widget = new ComboBox(ComboBox::IconTextMode);
  widget->SetModel(model);
  widget->SetCurrentIndex(2);

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

#ifdef DEBUG
  model->Print();
#endif

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

  NodeView* widget = new NodeView;

  f1->AddWidget(widget);

  NumericalSlider* ns1 = new NumericalSlider;
  NumericalSlider* ns2 = new NumericalSlider;
  NumericalSlider* ns3 = new NumericalSlider;

  Node* node = new Node("Example Node");
  node->AddWidget(ns1);
  node->AddWidget(ns2);
  node->AddWidget(ns3);

  node->Resize(node->GetPreferredSize());

  widget->AddNode(node);

  f1->Resize(800, 600);
  f1->MoveTo(20, 60);

  Dialog* f2 = new Dialog("Dialog", new LinearLayout(Vertical));
  f2->AddWidget(new PushButton("PushButton"));

  f2->Resize(f2->GetPreferredSize());
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

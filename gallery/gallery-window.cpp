/*
 * GLFWContext.cpp
 */

#include "gallery-window.hpp"

#include <core/image.hpp>

#include <font/fc-config.hpp>
#include <font/fc-pattern.hpp>

#include <gui/abstract-round-widget.hpp>
#include <gui/radio-button.hpp>
#include <gui/check-button.hpp>
#include <gui/abstract-round-frame.hpp>
#include <gui/frame-splitter.hpp>
#include <gui/filebutton.hpp>
#include <gui/color-wheel.hpp>
#include <gui/viewport2d.hpp>
#include <gui/model-viewport.hpp>
#include <gui/color-selector.hpp>

#include <stock/shaders.hpp>
#include <gui/dialog.hpp>

#include <gui/abstract-round-frame.hpp>
#include <gui/frame.hpp>
#include <gui/block.hpp>
#include <gui/close-button.hpp>
#include <gui/folder-list.hpp>

#include <gui/menu-button.hpp>
#include <gui/linear-adjustment.hpp>

#include <gui/node.hpp>
#include <gui/abstract-window.hpp>
#include <gui/cv-image-view.hpp>

using namespace BI;

GalleryWindow::GalleryWindow (int width, int height, const char* name)
: Window(width, height, name),
  viewport_(nullptr),
  tools_(nullptr),
  splitter_(0),
  widgets_dialog_(0)
{
  splitter_ = new FrameSplitter(Vertical);

  Workspace* viewport_space = CreateViewportSpace();
	Workspace* node_space = CreateNodeSpace();

	splitter_->AddFrame(viewport_space);
	splitter_->AddFrame(node_space);

  AddFrame(splitter_);

	tools_ = CreateTools();
	AddFrame(tools_);

  Dialog* dlg = CreateWidgetsDialog();
  AddFrame(dlg);
  dlg->Resize(460, dlg->GetPreferredSize().height());
  dlg->MoveTo(size().width() - dlg->size().width() - 50,
               size().height() - dlg->size().height() - 50);

	events()->connect(resized(), this, &GalleryWindow::OnResize);

	OnResize(size());
}

GalleryWindow::~GalleryWindow ()
{
}

BI::Dialog* GalleryWindow::CreateWidgetsDialog ()
{
  Dialog* dialog = new Dialog("More Widgets", new LinearLayout(Vertical));

  // ---- buttons

  TableLayout* table_layout = new TableLayout(6, 2);

  Label* l1 = new Label("Regular Button: ", AlignRight);
  Button* b1 = new Button("Button");
  table_layout->InsertWidget(0, 0, l1);
  table_layout->InsertWidget(0, 1, b1);

  Label* l2 = new Label("Toggle Button: ", AlignRight);
  ToggleButton* b2 = new ToggleButton("Toggle Button");
  table_layout->InsertWidget(1, 0, l2);
  table_layout->InsertWidget(1, 1, b2);

  Label* l3 = new Label("Radio Button: ", AlignRight);
  Block* block1 = new Block(Horizontal);
  RadioButton* radio1 = new RadioButton(AbstractWindow::icons()->icon_16x16(Icons::SCENE));
  RadioButton* radio2 = new RadioButton(AbstractWindow::icons()->icon_16x16(Icons::SCENE_DATA));
  RadioButton* radio3 = new RadioButton(AbstractWindow::icons()->icon_16x16(Icons::SURFACE_NSURFACE));
  RadioButton* radio4 = new RadioButton(AbstractWindow::icons()->icon_16x16(Icons::SURFACE_NCIRCLE));
  RadioButton* radio5 = new RadioButton(AbstractWindow::icons()->icon_16x16(Icons::SURFACE_NCURVE));

  block1->AddWidget(radio1);
  block1->AddWidget(radio2);
  block1->AddWidget(radio3);
  block1->AddWidget(radio4);
  block1->AddWidget(radio5);

  table_layout->InsertWidget(2, 0, l3);
  table_layout->InsertWidget(2, 1, block1);

  Label* l4 = new Label("Check Button: ", AlignRight);
  CheckButton* b4 = new CheckButton("Check Button");
  table_layout->InsertWidget(3, 0, l4);
  table_layout->InsertWidget(3, 1, b4);

  Label* l5 = new Label("Radio Button: ", AlignRight);
  ColorButton* b5 = new ColorButton;
  table_layout->InsertWidget(4, 0, l5);
  table_layout->InsertWidget(4, 1, b5);

  Label* l6 = new Label("Radio Button: ", AlignRight);
  FileButton* b6 = new FileButton;
  table_layout->InsertWidget(5, 0, l6);
  table_layout->InsertWidget(5, 1, b6);

  dialog->AddWidget(table_layout);

  // ---- tab

  Tab* tab = new Tab;

  tab->AddWidget("Texture View", new TextureView);
  tab->AddWidget("Node View", new NodeView);
  tab->AddWidget("Scroll View", new ScrollView);

  dialog->AddWidget(tab);

  return dialog;
}

void GalleryWindow::OnResize (const BI::Size& size)
{
	tools_->Resize(tools_->GetPreferredSize().width(), size.height());

	splitter_->MoveTo(tools_->size().width(), 0);
	splitter_->Resize(size.width() - tools_->size().width(), size.height());
}

Frame* GalleryWindow::CreateTools()
{
	LinearLayout* layout = new LinearLayout(Vertical);

	Frame* tools = new Frame(layout);
	tools->EnableViewBuffer();

	Button* b1 = new Button;
	b1->SetIcon(icons()->icon_16x16(Icons::ACTION));

	Button* b2 = new Button;
	b2->SetIcon(icons()->icon_16x16(Icons::ALIASED));

	Button* b3 = new Button;
	b3->SetIcon(icons()->icon_16x16(Icons::AUTO));

	Button* b4 = new Button;
	b4->SetIcon(icons()->icon_16x16(Icons::CAMERA_DATA));

	tools->AddWidget(b1);
	tools->AddWidget(b2);
	tools->AddWidget(b3);
	tools->AddWidget(b4);

	// tools->Resize(tools->GetPreferredSize());

	return tools;
}

Workspace* GalleryWindow::CreateNodeSpace()
{
  Workspace* workspace = new Workspace;

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

  header->Resize(header->GetPreferredSize());

  LinearLayout* vlayout = new LinearLayout(Vertical);
  vlayout->SetMargin(Margin(0, 0, 0, 0));
  Frame* node_frame = new Frame(vlayout);

  NodeView* node_view = new NodeView;
  node_frame->AddWidget(node_view);

  // +++++
  // add some node

  Node* node1 = new Node(new LinearLayout(Vertical), 0x9f9f9fff);

  node1->AddWidget(new Label("Node 1"));
  node1->AddWidget(new NumericalSlider);
  node1->AddWidget(new NumericalSlider);

  node1->Resize(node1->GetPreferredSize());

  node_view->AddNode(node1);
  node1->MoveTo(100, 20);

  Node* node2 = new Node(new LinearLayout(Vertical), 0x9f9fefff);

  node2->AddWidget(new Label("Node 2"));
  node2->AddWidget(new ComboBox);
  node2->AddWidget(new TextureView);

  node2->Resize(120, 160);

  node_view->AddNode(node2);
  node2->MoveTo(400, 20);
  // ------

  workspace->SetHeaderFrame(header);
  workspace->SetMainFrame(node_frame);
  return workspace;
}

Workspace* GalleryWindow::CreateViewportSpace()
{
  Workspace* workspace = new Workspace;

  LinearLayout* layout = new LinearLayout(Horizontal);
  layout->SetMargin(Margin(2, 2, 2, 2));

  Frame* header = new Frame(layout);
  header->EnableViewBuffer();

  ComboBox* combo = new ComboBox;

  Block* block1 = new Block(Horizontal);

  Button* btn = new Button("Button1");
  block1->AddWidget(btn);

  btn = new Button("Button2");
  block1->AddWidget(btn);

  header->AddWidget(combo);
  header->AddWidget(block1);

  header->Resize(header->GetPreferredSize());

  viewport_ = new ModelViewport;

  workspace->SetHeaderFrame(header);
  workspace->SetMainFrame(viewport_);
  return workspace;
}

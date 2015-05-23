/*
 * GLFWContext.cpp
 */

#include <GLFW/glfw3.h>

#include <blendint/gui/abstract-round-frame.hpp>
#include <blendint/gui/image-viewport.hpp>
#include <blendint/gui/push-button.hpp>
#include <blendint/gui/expander.hpp>
#include <blendint/gui/numerical-slider.hpp>
#include <blendint/gui/block.hpp>
#include <blendint/gui/combo-box.hpp>

#include <blendint/gui/frame.hpp>
#include <blendint/gui/linear-layout.hpp>
#include <blendint/gui/menu-button.hpp>
#include <blendint/gui/toggle-button.hpp>
#include <blendint/gui/radio-button.hpp>
#include <blendint/gui/adaptive-layout.hpp>
#include <blendint/gui/cube.hpp>
#include <blendint/gui/mesh.hpp>

#include "hpe-window.hpp"

using namespace BlendInt;

HPEWindow::HPEWindow (int width, int height, const char* name)
: BI::Window(width, height, name),
  viewport_3d_(0),
  main_frame_(0),
  cv_space_(0)
{
  main_frame_ = new FrameSplitter(Vertical);

  FrameSplitter* hsplitter1 = new FrameSplitter;
  Workspace* workspace = CreateViewportSpace();
  cv_space_ = new CVSpace;

  hsplitter1->AddFrame(workspace);
  hsplitter1->AddFrame(cv_space_);

  Workspace* node_space = CreateNodeSpace();

  FrameSplitter* vsplitter = new FrameSplitter(Vertical);
  vsplitter->AddFrame(hsplitter1);
  vsplitter->AddFrame(node_space, PreferredWidth);

  Workspace* tools = CreateToolSpace();

  FrameSplitter* hsplitter2 = new FrameSplitter;

  hsplitter2->AddFrame(vsplitter);
  hsplitter2->AddFrame(tools, PreferredWidth);

  Frame* bar = CreateToolBarOnce();

  main_frame_->AddFrame(bar);
  main_frame_->AddFrame(hsplitter2, ExpandY);

  AddFrame(main_frame_);
  main_frame_->Resize(size());

  resized().connect(this, &HPEWindow::OnResize);

  //events()->connect(resized(), vsplitter, static_cast<void (BI::AbstractView::*)(const BI::Size&) >(&BI::FrameSplitter::Resize));
}

HPEWindow::~HPEWindow ()
{

}

Frame* HPEWindow::CreateToolBarOnce ()
{
  LinearLayout* layout = new LinearLayout(Horizontal);
  layout->SetMargin(Margin(2, 2, 2, 2));

  Frame* bar = new Frame(layout);
  bar->EnableViewBuffer();

  ComboBox* combo = new ComboBox;
  combo->Resize(48, combo->size().height());

  MenuButton* btn1 = new MenuButton("File");
  MenuButton* btn2 = new MenuButton("Edit");
  MenuButton* btn3 = new MenuButton("View");

  bar->AddWidget(combo);
  bar->AddWidget(btn1);
  bar->AddWidget(btn2);
  bar->AddWidget(btn3);

  bar->Resize(bar->GetPreferredSize());

  return bar;
}

Workspace* HPEWindow::CreateViewportSpace ()
{
  Workspace* workspace = new Workspace;

  LinearLayout* layout = new LinearLayout(Horizontal);
  layout->SetMargin(Margin(2, 2, 2, 2));

  Frame* header = new Frame(layout);
  header->EnableViewBuffer();

  ComboBox* combo = new ComboBox;

  PushButton* open_btn = new PushButton(icons()->icon_16x16(Icons::MESH_MONKEY), "Open Mesh");

  header->AddWidget(combo);
  header->AddWidget(open_btn);

  header->Resize(header->GetPreferredSize());

  ModelViewport* model_view = new ModelViewport;

  workspace->SetHeaderFrame(header);
  workspace->SetMainFrame(model_view);
  return workspace;
}

Workspace* HPEWindow::CreateToolSpace ()
{
  Workspace* workspace = new Workspace;

  Frame* header = CreateRadios();

  AdaptiveLayout* layout = new AdaptiveLayout(Vertical);
  layout->SetMargin(Margin(2, 2, 2, 2));

  Frame* tools = new Frame(layout);
  tools->EnableViewBuffer();

  Expander* expander = new Expander("Resolution");

  NumericalSlider* ns1 = new NumericalSlider;
  NumericalSlider* ns2 = new NumericalSlider;

  Block* vblock = new Block(Vertical);
  vblock->AddWidget(ns1);
  vblock->AddWidget(ns2);

  expander->AddWidget(vblock);
  expander->Resize(expander->GetPreferredSize());

  Panel* btn_panel = CreateButtons();

  tools->AddWidget(expander);
  tools->AddWidget(btn_panel);

  workspace->SetHeaderFrame(header, false);
  workspace->SetMainFrame(tools);

  return workspace;
}

Frame* HPEWindow::CreateRadios ()
{
  AdaptiveLayout* layout = new AdaptiveLayout(Horizontal);
  layout->SetMargin(Margin(2, 2, 2, 2));

  Frame* radio_tool = new Frame(layout);
  radio_tool->EnableViewBuffer();

//	radio_group_.reset(new ButtonGroup);

  ComboBox* combo = new ComboBox;

  Block* hblock = new Block(Horizontal);

  RadioButton* radio1 = new RadioButton(
      icons()->icon_16x16(Icons::SCENE));
  RadioButton* radio2 = new RadioButton(
      icons()->icon_16x16(Icons::SCENE_DATA));
  RadioButton* radio3 = new RadioButton(
      icons()->icon_16x16(Icons::SURFACE_NSURFACE));
  RadioButton* radio4 = new RadioButton(
      icons()->icon_16x16(Icons::SURFACE_NCIRCLE));
  RadioButton* radio5 = new RadioButton(
      icons()->icon_16x16(Icons::SURFACE_NCURVE));

//	radio_group_->AddButton(radio1);
//	radio_group_->AddButton(radio2);
//	radio_group_->AddButton(radio3);
//	radio_group_->AddButton(radio4);
//	radio_group_->AddButton(radio5);

  radio1->SetChecked(true);

  hblock->AddWidget(radio1);
  hblock->AddWidget(radio2);
  hblock->AddWidget(radio3);
  hblock->AddWidget(radio4);
  hblock->AddWidget(radio5);

  radio_tool->AddWidget(combo);
  radio_tool->AddWidget(hblock);

  radio_tool->Resize(radio_tool->GetPreferredSize());

  return radio_tool;
}

Panel* HPEWindow::CreateButtons ()
{
  Block* hblock1 = new Block(Horizontal);

  ComboBox* camera_no = new ComboBox;
  ToggleButton* btn1 = new ToggleButton("Open Camera");

  hblock1->AddWidget(camera_no);
  hblock1->AddWidget(btn1);

  LinearLayout* layout = new LinearLayout(Vertical);

  Block* hblock2 = new Block(Horizontal);

  PushButton* play = new PushButton("Play");
  PushButton* pause = new PushButton("Pause");
  PushButton* stop = new PushButton("Stop");

  hblock2->AddWidget(play);
  hblock2->AddWidget(pause);
  hblock2->AddWidget(stop);

  layout->AddWidget(hblock1);
  layout->AddWidget(hblock2);

  Panel* panel = new Panel(layout);
  panel->SetRoundType(RoundAll);
  panel->Resize(layout->GetPreferredSize());

  return panel;
}

BI::Workspace* HPEWindow::CreateNodeSpace ()
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
  node_frame->EnableViewBuffer();

  NodeView* node_view = new NodeView;
  node_frame->AddWidget(node_view);

  // +++++
  // add some node

  Node* node1 = new Node("Node 1");

  node1->AddWidget(new NumericalSlider);
  node1->AddWidget(new NumericalSlider);

  node1->Resize(node1->GetPreferredSize());

  node_view->AddNode(node1);
  node1->MoveTo(100, 20);

  Node* node2 = new Node("Node 2");

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

void HPEWindow::OnResize (const Size& size)
{
  main_frame_->Resize(size);
}

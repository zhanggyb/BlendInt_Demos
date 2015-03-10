/*
 * GLFWContext.cpp
 */

#include <GLFW/glfw3.h>

#include <gui/abstract-round-frame.hpp>
#include <gui/image-viewport.hpp>
#include <gui/button.hpp>
#include <gui/expander.hpp>
#include <gui/numerical-slider.hpp>
#include <gui/block.hpp>
#include <gui/combo-box.hpp>

#include <gui/frame.hpp>
#include <gui/linear-layout.hpp>
#include <gui/menu-button.hpp>
#include <gui/toggle-button.hpp>
#include <gui/radio-button.hpp>
#include <gui/adaptive-layout.hpp>

#include "hpe-window.hpp"

using namespace BlendInt;

HPEWindow::HPEWindow (int width, int height, const char* name)
: BI::Window(width, height, name), viewport_3d_(0), main_frame_(0)
{
  main_frame_ = new FrameSplitter(Vertical);

  FrameSplitter* splitter = new FrameSplitter;

  Workspace* tools = CreateToolsOnce();
  Workspace* workspace = CreateWorkspaceOnce();

  splitter->AddFrame(workspace);
  splitter->AddFrame(tools, PreferredWidth);

  Frame* bar = CreateToolBarOnce();

  main_frame_->AddFrame(bar);
  main_frame_->AddFrame(splitter, ExpandY);

  AddFrame(main_frame_);
  main_frame_->Resize(size());

  events()->connect(resized(), this, &HPEWindow::OnResize);

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

Workspace* HPEWindow::CreateWorkspaceOnce ()
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

  workspace->SetHeader(header);
  workspace->SetViewport(new Viewport);
  return workspace;
}

Workspace* HPEWindow::CreateToolsOnce ()
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

  workspace->SetHeader(header, false);
  workspace->SetViewport(tools);

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
      AbstractWindow::icons()->icon_16x16(Icons::SCENE));
  RadioButton* radio2 = new RadioButton(
      AbstractWindow::icons()->icon_16x16(Icons::SCENE_DATA));
  RadioButton* radio3 = new RadioButton(
      AbstractWindow::icons()->icon_16x16(Icons::SURFACE_NSURFACE));
  RadioButton* radio4 = new RadioButton(
      AbstractWindow::icons()->icon_16x16(Icons::SURFACE_NCIRCLE));
  RadioButton* radio5 = new RadioButton(
      AbstractWindow::icons()->icon_16x16(Icons::SURFACE_NCURVE));

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

  Button* play = new Button("Play");
  Button* pause = new Button("Pause");
  Button* stop = new Button("Stop");

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

void HPEWindow::OnResize (Window* window, const Size& size)
{
  main_frame_->Resize(size);
}

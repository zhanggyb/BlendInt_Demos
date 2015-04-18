/*
 * GLFWContext.cpp
 */

#include "node-editor-window.hpp"

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
#include <gui/adaptive-layout.hpp>

#include <gui/node.hpp>
#include <gui/abstract-window.hpp>
#include <gui/cv-image-view.hpp>
#include <core/timer.hpp>

using namespace BI;

NodeEditorWindow::NodeEditorWindow (int width, int height, const char* name)
: Window(width, height, name),
  workspace_(0),
  node_view_()
{
  Frame* left_tools = CreateLeftTools();
  Frame* right_tools = CreateRightTools();
  Frame* node_area = CreateNodeArea();
  Frame* header = CreateHeaderArea();

  workspace_ = new Workspace;

  workspace_->SetLeftFrame(left_tools);
  workspace_->SetMainFrame(node_area);
  workspace_->SetRightFrame(right_tools);
  workspace_->SetHeaderFrame(header);

  AddFrame(workspace_);

  resized().connect(this, &NodeEditorWindow::OnResize);

  OnResize(size());
}

NodeEditorWindow::~NodeEditorWindow ()
{
}

BI::Frame* NodeEditorWindow::CreateLeftTools ()
{
  Frame* frame = new Frame(new AdaptiveLayout(Vertical));
  frame->EnableViewBuffer();

  Panel* p1 = new Panel(new LinearLayout(Vertical));

  PushButton* b1 = new PushButton("Button1");
  PushButton* b2 = new PushButton("Button2");
  PushButton* b3 = new PushButton("Button3");

  p1->AddWidget(b1);
  p1->AddWidget(b2);
  p1->AddWidget(b3);

  frame->AddWidget(p1);

  return frame;
}

BI::Frame* NodeEditorWindow::CreateRightTools ()
{
  Frame* frame = new Frame(new AdaptiveLayout(Vertical));
  frame->EnableViewBuffer();

  Expander* expander = new Expander("Resolution");

  PushButton* b1 = new PushButton("Add Node");
  PushButton* b2 = new PushButton("Button2");
  PushButton* b3 = new PushButton("Button3");

  Block* vblock = new Block(Vertical);
  vblock->AddWidget(b1);
  vblock->AddWidget(b2);
  vblock->AddWidget(b3);

  expander->AddWidget(vblock);
  expander->Resize(expander->GetPreferredSize());

  frame->AddWidget(expander);

  b1->clicked().connect(this, &NodeEditorWindow::OnAddNode);

  return frame;
}

BI::Frame* NodeEditorWindow::CreateNodeArea ()
{
  LinearLayout* layout = new LinearLayout(Vertical);
  layout->SetMargin(Margin(0, 0, 0, 0));

  Frame* frame = new Frame(layout);
  frame->EnableViewBuffer();

  node_view_ = new NodeView;

  frame->AddWidget(node_view_);

  return frame;
}

BI::Frame* NodeEditorWindow::CreateHeaderArea ()
{
  AdaptiveLayout* layout = new AdaptiveLayout(Horizontal);
  layout->SetMargin(Margin(2, 2, 2, 2));

  Frame* frame = new Frame(layout);
  frame->EnableViewBuffer();

  ComboBox* combo = new ComboBox;

  MenuButton* b1 = new MenuButton("File");
  MenuButton* b2 = new MenuButton("Edit");
  MenuButton* b3 = new MenuButton("Help");

  frame->AddWidget(combo);
  frame->AddWidget(b1);
  frame->AddWidget(b2);
  frame->AddWidget(b3);

  return frame;
}

void NodeEditorWindow::OnResize (const BI::Size& size)
{
  workspace_->Resize(size);
}

void NodeEditorWindow::OnAddNode ()
{
  Node* node = new Node("New Node");

  node->AddWidget(new NumericalSlider);
  node->AddWidget(new NumericalSlider);

  node->Resize(node->GetPreferredSize());

  node_view_->AddNode(node);
  node->MoveTo(200, 200);
}

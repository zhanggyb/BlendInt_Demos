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
#include <gui/viewport.hpp>
#include <gui/colorselector.hpp>

#include <stock/shaders.hpp>
#include <gui/dialog.hpp>

#include <gui/abstract-round-frame.hpp>
#include <gui/toolbox.hpp>
#include <gui/block.hpp>
#include <gui/close-button.hpp>
#include <gui/folder-list.hpp>

#include <gui/menu-button.hpp>
#include <gui/linear-adjustment.hpp>

#include <gui/node.hpp>
#include <gui/abstract-window.hpp>

using namespace BI;

GalleryWindow::GalleryWindow (int width, int height, const char* name)
: Window(width, height, name),
  viewport_(nullptr),
  tools_(nullptr)
{
	viewport_ = new Viewport;
	AddFrame(viewport_);
	viewport_->Resize(size());

	tools_ = CreateTools();
	AddFrame(tools_);
	tools_->MoveTo(0, (size().height() - tools_->size().height()) / 2);

	Dialog* dlg1 = CreateMenuBarArea();
	AddFrame(dlg1);
	dlg1->Resize(dlg1->GetPreferredSize());
	dlg1->MoveTo(100, 100);

	Dialog* dlg2 = CreateButtons();
	AddFrame(dlg2);
	dlg2->Resize(dlg2->GetPreferredSize());
	dlg2->MoveTo(100, 700);

	Dialog* dlg3 = CreateWidgetsArea();
	AddFrame(dlg3);
	dlg3->Resize(dlg3->GetPreferredSize());
	dlg3->MoveTo(240, 240);

	events()->connect(resized(), this, &GalleryWindow::OnResize);
}

GalleryWindow::~GalleryWindow ()
{
}

void GalleryWindow::OnResize (BI::Window* window, const BI::Size& size)
{
	viewport_->Resize(size);
	tools_->MoveTo(0, (size.height() - tools_->size().height()) / 2);
}

BI::Dialog* GalleryWindow::CreateMenuBarArea ()
{
	Dialog* dlg = new Dialog("Menu Bar", new LinearLayout(Horizontal));

	LinearLayout* l1 = new LinearLayout;

	MenuButton* b1 = new MenuButton("Menu1");
	MenuButton* b2 = new MenuButton("Menu2");
	MenuButton* b3 = new MenuButton("Menu3");
	Separator* sp = new Separator(true);

	l1->AddWidget(b1);
	l1->AddWidget(b2);
	l1->AddWidget(b3);
	l1->AddWidget(sp);

	dlg->AddWidget(l1);

	return dlg;
}

BI::Dialog* GalleryWindow::CreateWidgetsArea ()
{
	Dialog* toolbox = new Dialog("Widgets", new LinearLayout(Vertical));

	Tab* tab = new Tab;

	tab->AddWidget("Texture View", new TextureView);
	tab->AddWidget("Node View", new NodeView);

	toolbox->AddWidget(tab);

//	LinearLayout* l2 = new LinearLayout;
//
//	LinearLayout* l2_1 = new LinearLayout(Vertical, AlignCenter, 0);
//	Label* tv_lbl = new Label("TextureView: ", AlignLeft);
//	TextureView* tv = new TextureView;
//	l2_1->AddWidget(tv_lbl);
//	l2_1->AddWidget(tv);
//
//	LinearLayout* l2_2 = new LinearLayout(Vertical, AlignCenter, 0);
//	Label* nv_lbl = new Label("NodeView: ", AlignLeft);
//	NodeView* nv = new NodeView;
//	l2_2->AddWidget(nv_lbl);
//	l2_2->AddWidget(nv);
//
//	l2->AddWidget(l2_1);
//	l2->AddWidget(l2_2);
//
//	toolbox->AddWidget(l2);

	return toolbox;
}

BI::Dialog* GalleryWindow::CreateButtons ()
{
	Dialog* dlg = new Dialog("Buttons", new LinearLayout(Vertical));

	LinearLayout* l1 = new LinearLayout;

	Button* b1 = new Button("Button");
	ToggleButton* b2 = new ToggleButton("Toggle Button");

	Block* block1 = new Block(Horizontal);
	RadioButton* radio1 = new RadioButton(AbstractWindow::icons->icon_16x16(Icons::SCENE));
	RadioButton* radio2 = new RadioButton(AbstractWindow::icons->icon_16x16(Icons::SCENE_DATA));
	RadioButton* radio3 = new RadioButton(AbstractWindow::icons->icon_16x16(Icons::SURFACE_NSURFACE));
	RadioButton* radio4 = new RadioButton(AbstractWindow::icons->icon_16x16(Icons::SURFACE_NCIRCLE));
	RadioButton* radio5 = new RadioButton(AbstractWindow::icons->icon_16x16(Icons::SURFACE_NCURVE));

	block1->AddWidget(radio1);
	block1->AddWidget(radio2);
	block1->AddWidget(radio3);
	block1->AddWidget(radio4);
	block1->AddWidget(radio5);

	CheckButton* b4 = new CheckButton;
	ColorButton* b5 = new ColorButton;
	FileButton* b6 = new FileButton;

	Separator* sp1 = new Separator(true);

	l1->AddWidget(b1);
	l1->AddWidget(b2);
	l1->AddWidget(block1);
	l1->AddWidget(b4);
	l1->AddWidget(b5);
	l1->AddWidget(b6);
	l1->AddWidget(sp1);

	l1->Resize(l1->GetPreferredSize());
	
	dlg->AddWidget(l1);

	return dlg;
}

ToolBox* GalleryWindow::CreateTools()
{
	LinearLayout* layout = new LinearLayout(Vertical);

	ToolBox* tools = new ToolBox(layout);

	Button* b1 = new Button;
	b1->SetIcon(icons->icon_16x16(Icons::ACTION));

	Button* b2 = new Button;
	b2->SetIcon(icons->icon_16x16(Icons::ALIASED));

	Button* b3 = new Button;
	b3->SetIcon(icons->icon_16x16(Icons::AUTO));

	Button* b4 = new Button;
	b4->SetIcon(icons->icon_16x16(Icons::CAMERA_DATA));

	tools->AddWidget(b1);
	tools->AddWidget(b2);
	tools->AddWidget(b3);
	tools->AddWidget(b4);

	tools->Resize(tools->GetPreferredSize());

	return tools;
}

/*
 * GLFWContext.cpp
 */

#include "gallerycontext.hpp"

#include <core/image.hpp>

#include <font/fc-config.hpp>
#include <font/fc-pattern.hpp>

#include <gui/widget.hpp>
#include <gui/radio-button.hpp>
#include <gui/check-button.hpp>
#include <gui/frame.hpp>
#include <gui/frame-splitter.hpp>
#include <gui/filebutton.hpp>
#include <gui/color-wheel.hpp>
#include <gui/viewport2d.hpp>
#include <gui/viewport.hpp>
#include <gui/colorselector.hpp>

#include <stock/shaders.hpp>
#include <gui/dialog.hpp>

#include <gui/frame.hpp>
#include <gui/toolbox.hpp>
#include <gui/block.hpp>
#include <gui/close-button.hpp>
#include <gui/folder-list.hpp>

#include <gui/menu-button.hpp>
#include <gui/linear-adjustment.hpp>

#include <gui/node.hpp>
#include <gui/abstract-window.hpp>

using namespace BI;

void InitializeGLFWDemoContext ()
{
//	ToolBox* t1 = CreateMenuBarArea();
//	AddFrame(t1);
//	ToolBox* t2 = CreateWidgetsArea();
//	AddFrame(t2);
//	Viewport* viewport = new Viewport;
//	AddFrame(viewport);

	//events()->connect(resized(), splitter1, static_cast<void (BI::AbstractView::*)(const BI::Size&) >(&BI::FrameSplitter::Resize));
	//events()->connect(resized(), this, &GalleryContext::OnResize);

}

BI::ToolBox* CreateMenuBarArea ()
{
	ToolBox* toolbox = new ToolBox(new LinearLayout(Horizontal));

	LinearLayout* l1 = new LinearLayout;

	MenuButton* b1 = new MenuButton("Menu1");
	MenuButton* b2 = new MenuButton("Menu2");
	MenuButton* b3 = new MenuButton("Menu3");
	Separator* sp = new Separator(true);

	l1->AddWidget(b1);
	l1->AddWidget(b2);
	l1->AddWidget(b3);
	l1->AddWidget(sp);

	toolbox->AddWidget(l1);

	return toolbox;
}

BI::ToolBox* CreateWidgetsArea ()
{
	ToolBox* toolbox = new ToolBox(new LinearLayout(Vertical));

	LinearLayout* l2 = new LinearLayout;

	LinearLayout* l2_1 = new LinearLayout(Vertical, AlignCenter, 0);
	Label* tv_lbl = new Label("TextureView: ", AlignLeft);
	TextureView* tv = new TextureView;
	l2_1->AddWidget(tv_lbl);
	l2_1->AddWidget(tv);

	LinearLayout* l2_2 = new LinearLayout(Vertical, AlignCenter, 0);
	Label* nv_lbl = new Label("NodeView: ", AlignLeft);
	NodeView* nv = new NodeView;
	l2_2->AddWidget(nv_lbl);
	l2_2->AddWidget(nv);

	l2->AddWidget(l2_1);
	l2->AddWidget(l2_2);

	toolbox->AddWidget(l2);

	return toolbox;
}

BI::ToolBox* CreateButtons ()
{
	ToolBox* toolbox = new ToolBox(new LinearLayout(Vertical));

	LinearLayout* l1 = new LinearLayout;

	Label* btn_lbl = new Label(L"Buttons: ", AlignLeft);

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

	l1->AddWidget(btn_lbl);
	l1->AddWidget(b1);
	l1->AddWidget(b2);
	l1->AddWidget(block1);
	l1->AddWidget(b4);
	l1->AddWidget(b5);
	l1->AddWidget(b6);
	l1->AddWidget(sp1);

	l1->Resize(l1->GetPreferredSize());
	
	toolbox->AddWidget(l1);

	return toolbox;
}


//void GalleryContext::OnResize (const BI::Size& size)
//{
//	LinearAdjustment vertical_layout(this, Vertical, AlignCenter, 1);
//	vertical_layout.Adjust(0, 0, size.width(), size.height());
//}

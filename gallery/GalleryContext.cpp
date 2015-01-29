/*
 * GLFWContext.cpp
 */

#include "GalleryContext.hpp"

#include <BlendInt/Core/Image.hpp>

#include <BlendInt/Font/FcConfig.hpp>
#include <BlendInt/Font/FcPattern.hpp>

#include <BlendInt/Gui/Widget.hpp>
#include <BlendInt/Gui/RadioButton.hpp>
#include <BlendInt/Gui/CheckButton.hpp>
#include <BlendInt/Gui/Frame.hpp>
#include <BlendInt/Gui/FrameSplitter.hpp>
#include <BlendInt/Gui/FileButton.hpp>
#include <BlendInt/Gui/ColorWheel.hpp>
#include <BlendInt/Gui/Viewport2D.hpp>
#include <BlendInt/Gui/Viewport.hpp>
#include <BlendInt/Gui/ColorSelector.hpp>

#include <BlendInt/Stock/Shaders.hpp>
#include <BlendInt/Gui/Dialog.hpp>

#include <BlendInt/Gui/Frame.hpp>
#include <BlendInt/Gui/ToolBox.hpp>
#include <BlendInt/Gui/Block.hpp>
#include <BlendInt/Gui/CloseButton.hpp>
#include <BlendInt/Gui/FolderList.hpp>

#include <BlendInt/Gui/MenuButton.hpp>
#include <BlendInt/Gui/LinearAdjustment.hpp>

#include <BlendInt/Gui/Node.hpp>

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
	ToolBox* toolbox = new ToolBox(Horizontal);

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
	ToolBox* toolbox = new ToolBox(Vertical);

	Label* label = new Label(L"Widgets Area", AlignCenter);

	LinearLayout* l1 = new LinearLayout;

	Label* btn_lbl = new Label(L"Buttons: ", AlignRight);
	Button* b1 = new Button("Button");
	ToggleButton* b2 = new ToggleButton("Toggle Button");
	RadioButton* b3 = new RadioButton("Radio Button");
	CheckButton* b4 = new CheckButton;
	ColorButton* b5 = new ColorButton;
	FileButton* b6 = new FileButton;

	l1->AddWidget(btn_lbl);
	l1->AddWidget(b1);
	l1->AddWidget(b2);
	l1->AddWidget(b3);
	l1->AddWidget(b4);
	l1->AddWidget(b5);
	l1->AddWidget(b6);

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

	toolbox->AddWidget(label);
	toolbox->AddWidget(l1);
	toolbox->AddWidget(l2);

	return toolbox;
}

//void GalleryContext::OnResize (const BI::Size& size)
//{
//	LinearAdjustment vertical_layout(this, Vertical, AlignCenter, 1);
//	vertical_layout.Adjust(0, 0, size.width(), size.height());
//}

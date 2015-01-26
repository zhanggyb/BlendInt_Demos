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

#include <BlendInt/Gui/Node.hpp>

using namespace BI;

GalleryContext::GalleryContext(GLFWwindow* win)
: BI::Context(),
  window_(win)
{
	InitializeGLFWDemoContext ();
}

GalleryContext::~GalleryContext ()
{
}

void GalleryContext::SynchronizeWindow()
{
	glfwPostEmptyEvent();
}

void GalleryContext::InitializeGLFWDemoContext ()
{
	ToolBox* vp1 = new ToolBox(Vertical);
	//vp1->SetPosition(200, 200);
	//frame->Resize(400, 32);

	Block* block = new Block(Vertical);

	Button* btn1 = new Button("Hello");
	DBG_SET_NAME(btn1, "Button1");
	Button* btn2 = new Button("Hello");
	DBG_SET_NAME(btn2, "Button2");
	Button* btn3 = new Button("Hello");
	DBG_SET_NAME(btn3, "Button3");

	block->AddWidget(btn1);
	block->AddWidget(btn2);
	block->AddWidget(btn3);

	ScrollBar* bar = new ScrollBar;

	vp1->AddWidget(block);
	vp1->AddWidget(bar);

	Viewport* vp2 = new Viewport;
	DBG_SET_NAME(vp2, "Viewport2");

	Viewport* vp3 = new Viewport;
	DBG_SET_NAME(vp3, "VFrame");

	FrameSplitter* splitter1 = new FrameSplitter;
	DBG_SET_NAME(splitter1, "Splitter1");

	FrameSplitter* splitter2 = new FrameSplitter(Vertical);
	DBG_SET_NAME(splitter2, "Splitter2");
	splitter2->Resize(600, 720);

	splitter1->Resize(1200, 720);
	//splitter1->SetPosition(20, 20);

	splitter2->AddFrame(vp2);
	splitter2->AddFrame(vp3);

	splitter1->AddFrame(splitter2);
	splitter1->AddFrame(vp1, PreferredWidth);

	AddFrame(splitter1);

	splitter1->Resize(1200, 760);

	events()->connect(resized(), splitter1, static_cast<void (BI::AbstractView::*)(const BI::Size&) >(&BI::FrameSplitter::Resize));

	Dialog* dlg = new Dialog(String("Hello"));
    dlg->Resize(800, 600);
    dlg->MoveTo(200, 150);

    LinearLayout* hl = new LinearLayout;

    Button* b1 = new Button("B1");
    Button* b2 = new Button("B1");
    Button* b3 = new Button("B1");
    Label* l = new Label("Label");

    hl->AddWidget(b1);
    hl->AddWidget(b2);
    hl->AddWidget(b3);
    hl->AddWidget(l);

    hl->Resize(300, 32);

    dlg->AddWidget(hl);

    AddFrame(dlg);
}

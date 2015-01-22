/*
 * GLFWContext.cpp
 */

#include "GLFWDemoContext.hpp"

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

using namespace BI;

GLFWDemoContext::GLFWDemoContext(GLFWwindow* win)
: BI::Context(),
  window_(win)
{
	Debug();

//	InitializeGLFWDemoContext ();
}

GLFWDemoContext::~GLFWDemoContext ()
{
}

void GLFWDemoContext::SynchronizeWindow()
{
	glfwPostEmptyEvent();
}

void GLFWDemoContext::Debug()
{
	Dialog* dlg = new Dialog("Hello");

	Button* btn = new Button(L"Hello World!");
	btn->MoveTo(100, 100);

	Label* label1 = new Label(L"床前明月光，疑是地上霜。");
	label1->MoveTo(20, 200);

	label1->SetFont(Font((const FcChar8*)("Droid Sans"), 24));
	label1->Resize(label1->GetPreferredSize());

	Label* label2 = new Label(L"举头望明月，低头思故乡。");
	label2->MoveTo(20, 150);

	label2->SetFont(Font((const FcChar8*)("Source Han Sans"), 24));
	label2->Resize(label1->GetPreferredSize());

	dlg->AddWidget(btn);
	dlg->AddWidget(label1);
	dlg->AddWidget(label2);

	AddFrame(dlg);
}

void GLFWDemoContext::InitializeGLFWDemoContext ()
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
	AddFrame(dlg);

	Button* ok = new Button("OK");
	Button* cancel = new Button("Cancel");
	dlg->AddWidget(cancel);
	dlg->AddWidget(ok);

	ok->MoveTo(dlg->size().width() - ok->size().width() - 10, 10);
	cancel->MoveTo(ok->position().x() - 5 - cancel->size().width(), 10);

	PopupFrame* cs = new PopupFrame;
	cs->Resize(240, 320);
	cs->MoveTo(500, 300);
	AddFrame(cs);

	TextEntry* text = new TextEntry;
	text->MoveTo(20, 20);
	cs->AddWidget(text);

	ScrollBar* scroll = new ScrollBar(Horizontal);
	scroll->MoveTo(20, 100);
	cs->AddWidget(scroll);

	Button* b = new Button("Test");
	b->MoveTo(20, 150);
	cs->AddWidget(b);

}

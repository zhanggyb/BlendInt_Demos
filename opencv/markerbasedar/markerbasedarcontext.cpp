/*
 * GLFWContext.cpp
 */

#include <GLFW/glfw3.h>

#include "markerbasedarcontext.hpp"

#include <gui/frame.hpp>
#include <gui/image-viewport.hpp>
#include <gui/linear-layout.hpp>
#include <gui/button.hpp>
#include <gui/expander.hpp>
#include <gui/numerical-slider.hpp>
#include <gui/block.hpp>
#include <gui/combobox.hpp>

#include <gui/toolbox.hpp>
#include <gui/frame-splitter.hpp>
#include <gui/menu-button.hpp>
#include <gui/toggle-button.hpp>
#include <gui/separator.hpp>

using namespace BlendInt;

MarkerBasedARContext::MarkerBasedARContext(int width, int height, const char* name)
: BI::Window(width, height, name),
  viewport_(0),
  main_frame_(0)
{
	main_frame_ = new FrameSplitter(Vertical);

	FrameSplitter* splitter = new FrameSplitter;

	ToolBox* tools = CreateToolBoxOnce();
	viewport_ = new MBARViewport;

	splitter->AddFrame(viewport_);
	splitter->AddFrame(tools, PreferredWidth);

	ToolBox* bar = CreateToolBarOnce();

	main_frame_->AddFrame(bar);
	main_frame_->AddFrame(splitter, ExpandY);

	AddFrame(main_frame_);
	main_frame_->Resize(size());

	events()->connect(resized(), this, &MarkerBasedARContext::OnResize);

	//events()->connect(resized(), vsplitter, static_cast<void (BI::AbstractView::*)(const BI::Size&) >(&BI::FrameSplitter::Resize));
}

MarkerBasedARContext::~MarkerBasedARContext ()
{

}

ToolBox* MarkerBasedARContext::CreateToolBoxOnce()
{
	ToolBox* tools = new ToolBox(new LinearLayout(Vertical));

	Expander* expander = new Expander("Resolution");

	NumericalSlider* ns1 = new NumericalSlider("Width:");
	ns1->SetValue(50.f);
	NumericalSlider* ns2 = new NumericalSlider("Height:");
	ns2->SetValue(50.f);

	ToggleButton* open = new ToggleButton("Open Camera 0");
	Separator* separator1 = new Separator;
	Separator* separator2 = new Separator;

	Block* vblock = new Block(Vertical);
	vblock->AddWidget(ns1);
	vblock->AddWidget(ns2);

	expander->Setup(vblock);
	expander->Resize(expander->GetPreferredSize());

	Button* play = new Button("Play");
	Button* pause = new Button("Pause");
	Button* stop = new Button("Stop");

	Block* vblock1 = new Block(Vertical);
	vblock1->AddWidget(play);
	vblock1->AddWidget(pause);
	vblock1->AddWidget(stop);

	tools->AddWidget(expander);
	tools->AddWidget(separator1);
	tools->AddWidget(open);
	tools->AddWidget(separator2);
	tools->AddWidget(vblock1);

	events()->connect(open->toggled(), this, &MarkerBasedARContext::OnToggleCamera);
	events()->connect(play->clicked(), this, &MarkerBasedARContext::OnPlay);
	events()->connect(pause->clicked(), this, &MarkerBasedARContext::OnPause);
	events()->connect(stop->clicked(), this, &MarkerBasedARContext::OnStop);

	return tools;
}

ToolBox* MarkerBasedARContext::CreateToolBarOnce()
{
	ToolBox* bar = new ToolBox(new LinearLayout(Horizontal));

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

void MarkerBasedARContext::OnResize(Window* window, const Size& size)
{
	main_frame_->Resize(size);
}

void MarkerBasedARContext::OnToggleCamera(AbstractButton* sender, bool toggled)
{
	if(toggled) {
#ifdef __APPLE__
		viewport_->OpenCamera(0, Size(1080, 720));
#else
        viewport_->OpenCamera(0, Size(640, 480));
#endif
	} else {
		viewport_->Release();
	}
}

void MarkerBasedARContext::OnPlay(AbstractButton* sender)
{
	DBG_PRINT_MSG("%s", "Start Play");
	viewport_->Play();
}

void MarkerBasedARContext::OnPause (AbstractButton* sender)
{
	DBG_PRINT_MSG("%s", "Pause");
	viewport_->Pause();
}

void MarkerBasedARContext::OnStop(AbstractButton* sender)
{
	DBG_PRINT_MSG("%s", "Stop Play");
	viewport_->Stop();
}

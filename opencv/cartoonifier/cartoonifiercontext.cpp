/*
 * GLFWContext.cpp
 */

#include <GLFW/glfw3.h>

#include "cartoonifiercontext.hpp"

#include <gui/frame.hpp>
#include <gui/image-viewport.hpp>
#include <gui/linear-layout.hpp>
#include <gui/button.hpp>
#include <gui/expander.hpp>
#include <gui/numerical-slider.hpp>
#include <gui/block.hpp>

#include <gui/toolbox.hpp>
#include <gui/frame-splitter.hpp>

using namespace BlendInt;

CartoonifierContext::CartoonifierContext(int width, int height, const char* name)
: BI::Window(width, height, name),
  video_(0)
{
	main_frame_ = new FrameSplitter;

	ToolBox* tools = CreateToolBoxOnce();
	video_ = new CVVideoViewport;

	main_frame_->AddFrame(video_);
	main_frame_->AddFrame(tools);

	AddFrame(main_frame_);

	main_frame_->Resize(size());

	//events()->connect(resized(), splitter, static_cast<void (BI::AbstractView::*)(const BI::Size&) >(&BI::FrameSplitter::Resize));
	events()->connect(resized(), this, &CartoonifierContext::OnResize);
}

CartoonifierContext::~CartoonifierContext ()
{

}

ToolBox* CartoonifierContext::CreateToolBoxOnce()
{
	ToolBox* tools = new ToolBox(new LinearLayout(Vertical));

	Expander* expander = new Expander("Light");

	NumericalSlider* ns1 = new NumericalSlider;
	NumericalSlider* ns2 = new NumericalSlider;
	NumericalSlider* ns3 = new NumericalSlider;

	Block* vblock = new Block(Vertical);
	vblock->AddWidget(ns1);
	vblock->AddWidget(ns2);
	vblock->AddWidget(ns3);

	expander->Setup(vblock);
	expander->Resize(expander->GetPreferredSize());

	Button* play = new Button("Play");
	Button* pause = new Button("Pause");
	Button* stop = new Button("Stop");

	tools->AddWidget(expander);
	tools->AddWidget(play);
	tools->AddWidget(pause);
	tools->AddWidget(stop);

	events()->connect(play->clicked(), this, &CartoonifierContext::OnPlay);
	events()->connect(pause->clicked(), this, &CartoonifierContext::OnPause);
	events()->connect(stop->clicked(), this, &CartoonifierContext::OnStop);

	return tools;
}

void CartoonifierContext::OnPlay(AbstractButton* sender)
{
	DBG_PRINT_MSG("%s", "Start Play");
	video_->OpenCamera(0, Size(800, 600));
	video_->Play();
}

void CartoonifierContext::OnPause (AbstractButton* sender)
{
	DBG_PRINT_MSG("%s", "Pause");
	video_->Pause();
}

void CartoonifierContext::OnStop(AbstractButton* sender)
{
	DBG_PRINT_MSG("%s", "Stop Play");
	video_->Stop();
}

void CartoonifierContext::OnResize(Window* window, const Size& size)
{
	main_frame_->Resize(size);
}

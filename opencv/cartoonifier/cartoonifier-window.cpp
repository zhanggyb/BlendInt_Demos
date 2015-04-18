/*
 * GLFWContext.cpp
 */

#include <GLFW/glfw3.h>

#include "cartoonifier-window.hpp"

#include <gui/abstract-round-frame.hpp>
#include <gui/image-viewport.hpp>
#include <gui/linear-layout.hpp>
#include <gui/push-button.hpp>
#include <gui/expander.hpp>
#include <gui/numerical-slider.hpp>
#include <gui/block.hpp>

#include <gui/frame.hpp>
#include <gui/frame-splitter.hpp>
#include <gui/separator.hpp>
#include <gui/cv-image-view.hpp>

using namespace BlendInt;

CartoonifierWindow::CartoonifierWindow(int width, int height, const char* name)
: BI::Window(width, height, name),
  cv_view_(0)
{
	main_frame_ = new FrameSplitter(Vertical);

	Frame* tools = CreateToolBoxOnce();

	LinearLayout* image_layout = new LinearLayout(Vertical);
	image_layout->SetMargin(Margin(0, 0, 0, 0));
	Frame* video_frame = new Frame(image_layout);
	cv_view_ = new CartoonImageView;
	video_frame->AddWidget(cv_view_);


	main_frame_->AddFrame(video_frame);
	main_frame_->AddFrame(tools, PreferredHeight);

	AddFrame(main_frame_);

	main_frame_->Resize(size());

	//events()->connect(resized(), splitter, static_cast<void (BI::AbstractView::*)(const BI::Size&) >(&BI::FrameSplitter::Resize));
	resized().connect(this, &CartoonifierWindow::OnResize);
}

CartoonifierWindow::~CartoonifierWindow ()
{

}

Frame* CartoonifierWindow::CreateToolBoxOnce()
{
	LinearLayout* layout = new LinearLayout(Horizontal);
	layout->SetMargin(Margin(2, 2, 2, 2));
	layout->SetSpace(2);

	Frame* tools = new Frame(layout);
	tools->EnableViewBuffer();

	PushButton* pause = new PushButton(CartoonifierWindow::icons()->icon_32x32(Icons::PAUSE));
	PushButton* play = new PushButton(CartoonifierWindow::icons()->icon_32x32(Icons::PLAY));
	PushButton* stop = new PushButton(CartoonifierWindow::icons()->icon_32x32(Icons::REC));

	Separator* sp1 = new Separator(true);
	Separator* sp2 = new Separator(true);

	tools->AddWidget(sp1);
	tools->AddWidget(pause);
	tools->AddWidget(play);
	tools->AddWidget(stop);
	tools->AddWidget(sp2);

	tools->Resize(tools->GetPreferredSize());

	play->clicked().connect(this, &CartoonifierWindow::OnPlay);
	pause->clicked().connect(this, &CartoonifierWindow::OnPause);
	stop->clicked().connect(this, &CartoonifierWindow::OnStop);

	return tools;
}

void CartoonifierWindow::OnPlay()
{
	DBG_PRINT_MSG("%s", "Start Play");
	cv_view_->OpenCamera(0, 15, Size(640, 480));
	cv_view_->Play();
}

void CartoonifierWindow::OnPause ()
{
	DBG_PRINT_MSG("%s", "Pause");
	cv_view_->Pause();
}

void CartoonifierWindow::OnStop()
{
	DBG_PRINT_MSG("%s", "Stop Play");
	cv_view_->Stop();
}

void CartoonifierWindow::OnResize(const Size& size)
{
	main_frame_->Resize(size);
}

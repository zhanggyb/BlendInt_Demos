/**
 * BlendInt demo
 */

#include <gui/window.hpp>
#include <gui/message-box.hpp>

int main(int argc, char* argv[])
{
	using namespace BlendInt;

	BLENDINT_EVENTS_INIT_ONCE_IN_MAIN;

	if(Window::Initialize()) {

		Window win(240, 180, "Tutorial 01");

		MessageBox* msg = new MessageBox("Hello World!", "Click the \"close\" button.");
	    // 'message' will be destroyed when the window is closed.
		win.AddFrame(msg);
		msg->MoveTo(
				(win.size().width() - msg->size().width()) / 2,
				(win.size().height() - msg->size().height()) / 2);

		win.Exec();
		Window::Terminate();
	}

	return 0;
}


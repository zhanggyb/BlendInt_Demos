/**
 * BlendInt demo
 */

#include <BlendInt/Gui/Window.hpp>
#include <BlendInt/Gui/FrameSplitter.hpp>
#include <BlendInt/Gui/Viewport.hpp>
#include "CartoonifierContext.hpp"

using namespace BlendInt;
using namespace std;

int main(int argc, char* argv[])
{
	BLENDINT_EVENTS_INIT_ONCE_IN_MAIN;

	if(Window::Initialize()) {

		Window win(1280, 800, "UI Editor");

		FrameSplitter* splitter = new FrameSplitter;

		Viewport* vp1 = new Viewport;
		Viewport* vp2 = new Viewport;

		splitter->AddFrame(vp1);
		splitter->AddFrame(vp2);

		splitter->Resize(win.size());

		win.AddFrame(splitter);

		win.Exec();

		Window::Terminate();
	}

	return 0;
}

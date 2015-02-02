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

		CartoonifierContext win(1280, 800, "Cartoonifier");

		win.Exec();
		Window::Terminate();
	}

	return 0;
}

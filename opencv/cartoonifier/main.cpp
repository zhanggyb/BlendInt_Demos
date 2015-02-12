/**
 * BlendInt demo
 */

#include <gui/window.hpp>
#include <gui/frame-splitter.hpp>
#include <gui/viewport.hpp>
#include "cartoonifiercontext.hpp"

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

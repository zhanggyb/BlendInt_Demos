/**
 * BlendInt demo
 */

#include <core/types.hpp>

#include "studio-window.hpp"

int main(int argc, char* argv[])
{
	using namespace BlendInt;
	BLENDINT_EVENTS_INIT_ONCE_IN_MAIN;

	if(StudioWindow::Initialize()) {

		StudioWindow win(1280, 800, "Studio");

		win.Exec();
		StudioWindow::Terminate();
	}

	return 0;
}


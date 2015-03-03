/**
 * BlendInt demo
 */

#include <Cpp/Events.hpp>
#include <core/types.hpp>

#include "mbar-window.hpp"

using namespace BlendInt;
using namespace std;

int main(int argc, char* argv[])
{
	BLENDINT_EVENTS_INIT_ONCE_IN_MAIN;

	if(Window::Initialize()) {

		MBARWindow win(1280, 800, "MarkerBasedAR");

		win.Exec();
		Window::Terminate();
	}

	return 0;
}

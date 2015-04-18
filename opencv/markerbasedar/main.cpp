/**
 * BlendInt demo
 */

#include <core/types.hpp>

#include "mbar-window.hpp"

using namespace BlendInt;
using namespace std;

int main(int argc, char* argv[])
{
	if(Window::Initialize()) {

		MBARWindow win(1280, 800, "MarkerBasedAR");

		win.Exec();
		Window::Terminate();
	}

	return 0;
}

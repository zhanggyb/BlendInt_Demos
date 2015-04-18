/**
 * BlendInt demo
 */

#include <core/types.hpp>

#include "hpe-window.hpp"

using namespace BlendInt;
using namespace std;

int main(int argc, char* argv[])
{
	if(Window::Initialize()) {

		HPEWindow win(1280, 800, "HeadPoseEstimation");

		win.Exec();
		Window::Terminate();
	}

	return 0;
}

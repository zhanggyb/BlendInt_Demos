/**
 * BlendInt demo
 */

#include <Cpp/Events.hpp>
#include <BlendInt/Core/Types.hpp>

#include "HPEContext.hpp"

using namespace BlendInt;
using namespace std;

int main(int argc, char* argv[])
{
	BLENDINT_EVENTS_INIT_ONCE_IN_MAIN;

	if(Window::Initialize()) {

		HPEContext win(1280, 800, "HeadPoseEstimation");

		win.Exec();
		Window::Terminate();
	}

	return 0;
}

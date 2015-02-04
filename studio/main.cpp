/**
 * BlendInt demo
 */

#include <BlendInt/Core/Types.hpp>

#include "StudioContext.hpp"

int main(int argc, char* argv[])
{
	using namespace BlendInt;
	BLENDINT_EVENTS_INIT_ONCE_IN_MAIN;

	if(StudioContext::Initialize()) {

		StudioContext win(1280, 800, "Studio");

		win.Exec();
		StudioContext::Terminate();
	}

	return 0;
}


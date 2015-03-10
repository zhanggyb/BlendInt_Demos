/**
 * BlendInt demo
 */

#include "node-editor-window.hpp"

int main(int argc, char* argv[])
{
	using namespace BlendInt;

	BLENDINT_EVENTS_INIT_ONCE_IN_MAIN;

	if(Window::Initialize()) {

		NodeEditorWindow win(1280, 800, "Node Editor Demo");

		win.Exec();
		Window::Terminate();
	}

	return 0;
}


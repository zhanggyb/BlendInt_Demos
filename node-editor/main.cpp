/**
 * BlendInt demo
 */

#include "node-editor-window.hpp"

int main(int argc, char* argv[])
{
	using namespace BlendInt;

	if(Window::Initialize()) {

		NodeEditorWindow win(1280, 800, "Node Editor Demo");

		win.Exec();
		Window::Terminate();
	}

	return 0;
}


/**
 * BlendInt demo
 */

#include <gui/window.hpp>
#include <gui/frame-splitter.hpp>
#include <gui/model-viewport.hpp>
#include "cartoonifier-window.hpp"

using namespace BlendInt;
using namespace std;

int main(int argc, char* argv[])
{
	if(Window::Initialize()) {

		CartoonifierWindow win(640, 700, "Cartoonifier");

		win.Exec();
		Window::Terminate();
	}

	return 0;
}

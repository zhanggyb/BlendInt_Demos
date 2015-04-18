/**
 * BlendInt demo
 */

#include <core/types.hpp>

#include "font-viewer-window.hpp"

int main (int argc, char* argv[])
{
  using namespace BlendInt;

  if (Window::Initialize()) {

    FontViewerWindow win(1280, 800, "Font Viewer");

    win.Exec();
    Window::Terminate();
  }

  return 0;
}


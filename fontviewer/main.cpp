/**
 * BlendInt demo
 */

#include <core/types.hpp>

#include "font-viewer-window.hpp"

int main (int argc, char* argv[])
{
  using namespace BlendInt;

  BLENDINT_EVENTS_INIT_ONCE_IN_MAIN;

  if (Window::Initialize()) {

    FontViewerWindow win(1280, 800, "Font Viewer");

    win.Exec();
    Window::Terminate();
  }

  return 0;
}


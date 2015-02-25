/*
 * GLFWContext.cpp
 */

#include "font-viewer-window.hpp"

#include <gui/abstract-round-frame.hpp>
#include <gui/menu-button.hpp>
#include <gui/clock.hpp>
#include <gui/scroll-area.hpp>
#include <gui/tabheader.hpp>
#include <gui/dialog.hpp>
#include <gui/cv-image-view.hpp>

using namespace BI;

FontViewerWindow::FontViewerWindow(int width, int height, const char* name)
: BI::Window(width, height, name),
  menubar_(nullptr)
{
	menubar_ = CreateMenuBar();
	AddFrame(menubar_);

	OnResize(this, size());

	events()->connect(resized(), this, &FontViewerWindow::OnResize);
}

FontViewerWindow::~FontViewerWindow ()
{

}

void FontViewerWindow::OnResize(BI::Window* window, const BI::Size& size)
{
	Size menubar_size = menubar_->GetPreferredSize();

	menubar_->MoveTo(0, size.height() - menubar_size.height());
	menubar_->Resize(size.width(), menubar_size.height());
}

BI::ToolBox* FontViewerWindow::CreateMenuBar()
{
	LinearLayout* layout = new LinearLayout(Horizontal);
	layout->SetMargin(Margin(0, 0, 0, 0));

	ToolBox* menubar = new ToolBox(layout);
	menubar->MoveTo(0, size().height() - menubar->size().height());

	MenuButton* menubtn1 = new MenuButton("Open");
	menubar->AddWidget(menubtn1);
	events()->connect(menubtn1->clicked(), this, &FontViewerWindow::OnOpen);

	MenuButton* menubtn2 = new MenuButton("Test CVImageView");
	menubar->AddWidget(menubtn2);

#ifdef __USE_OPENCV__
	events()->connect(menubtn2->clicked(), this, &FontViewerWindow::OnOpenCVImageView);
#endif

	return menubar;
}

void FontViewerWindow::OnOpen(AbstractButton* sender)
{
	Dialog* dialog = new Dialog("Font Viewer");

	TextureView* textureview = new TextureView;
	textureview->MoveTo(50, 50);

	Font font;

	// textureview->SetTexture(font.GetTexture(L'A'));

	LinearLayout* layout = new LinearLayout(Vertical);
	layout->AddWidget(textureview);

	// dialog->SetLayout(layout);

	dialog->Resize(textureview->size().width() + 100, textureview->size().height() + 100);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);
//	dialog->AddWidget(textureview);

	dialog->Resize(520, 520);

	AddFrame(dialog);

	AbstractWindow* off_screen = CreateSharedContext(size().width(), size().height(), false);

	assert(off_screen);

	delete off_screen;
}

#ifdef __USE_OPENCV__

void FontViewerWindow::OnOpenCVImageView(AbstractButton* sender)
{
	Dialog* dlg = new Dialog("CV Image", new LinearLayout(Vertical));

	CVImageView* view = new CVImageView;
	dlg->AddWidget(view);

	AddFrame(dlg);
}

#endif

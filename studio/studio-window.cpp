/*
 * GLFWContext.cpp
 */

#include "studio-window.hpp"

#include <gui/abstract-round-frame.hpp>
#include <gui/menu-button.hpp>
#include <gui/clock.hpp>
#include <gui/scroll-area.hpp>
#include <gui/tab-header.hpp>
#include <gui/adaptive-layout.hpp>

using namespace BI;

StudioWindow::StudioWindow(int width, int height, const char* name)
: BI::Window(width, height, name),
  button_(0),
 // pop_(0),
  toolbar_(nullptr)
{
	toolbar_ = CreateToolBar();
	AddFrame(toolbar_);

	OnResize(size());
	events()->connect(resized(), this, &StudioWindow::OnResize);
}

StudioWindow::~StudioWindow ()
{

}

BI::Frame* StudioWindow::CreateToolBar()
{
	LinearLayout* layout = new LinearLayout(Horizontal);

	Frame* tools = new Frame(layout);
	tools->EnableViewBuffer();

	Button* b1 = new Button;
	b1->SetIcon(icons()->icon_16x16(Icons::MESH_PLANE));

	Button* b2 = new Button;
	b2->SetIcon(icons()->icon_16x16(Icons::FULLSCREEN));

	Button* b3 = new Button;
	b3->SetIcon(icons()->icon_16x16(Icons::SPLITSCREEN));

	Separator* sp1 = new Separator;

	Button* b4 = new Button;
	b4->SetIcon(icons()->icon_16x16(Icons::OUTLINER_DATA_CAMERA));

	tools->AddWidget(b1);
	tools->AddWidget(b2);
	tools->AddWidget(b3);
	tools->AddWidget(sp1);
	tools->AddWidget(b4);

	tools->Resize(tools->GetPreferredSize());

	events()->connect(b1->clicked(), this, &StudioWindow::OnOpenDialogForButtons);
	events()->connect(b2->clicked(), this, &StudioWindow::OnOpenDialogForNumericalSlider);
  events()->connect(b3->clicked(), this, &StudioWindow::OnTestAdaptiveLayout);
	events()->connect(b4->clicked(), this, &StudioWindow::OnTakeScreenshot);

	return tools;
}

void StudioWindow::OnTakeScreenshot ()
{
	DBG_PRINT_MSG("TODO: %s", "check the focused frame and save the view buffer to a image file");
}

void StudioWindow::OnOpenDialogForButtons()
{
	Dialog* dialog = Manage(new Dialog("Test", new LinearLayout(Horizontal)));

	Button* btn = Manage(new Button("Button"));
	btn->MoveTo(100, 50);

	ToggleButton* toggle_btn = Manage(new ToggleButton("ToggleButton"));
	toggle_btn->MoveTo(100, 100);

	TabButton* tab_btn = Manage(new TabButton("TabButton"));
	tab_btn->MoveTo(100, 150);

	dialog->AddWidget(btn);
	dialog->AddWidget(toggle_btn);
	dialog->AddWidget(tab_btn);

	dialog->Resize(dialog->GetPreferredSize());
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	AddFrame(dialog);
}

void StudioWindow::OnOpenDialogForTextureView()
{
	Dialog* dialog = Manage(new Dialog("ButtonTest1"));
	TextureView* textureview = Manage(new TextureView);
	textureview->MoveTo(50, 50);
	dialog->Resize(textureview->size().width() + 100, textureview->size().height() + 100);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);
	dialog->AddWidget(textureview);
	AddFrame(dialog);
}

void StudioWindow::OnOpenModalDialog()
{
	Dialog * dialog = Manage(new Dialog("Hello"));
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);
	AddFrame(dialog);
}

void StudioWindow::OnOpenFileSelector()
{
	FileSelector * fs = Manage(new FileSelector);
	fs->Resize(800, 600);
	fs->MoveTo((size().width() - fs->size().width()) / 2, (size().height() - fs->size().height()) / 2);

	AddFrame(fs);
}

void StudioWindow::OnResize(const BI::Size& size)
{
	toolbar_->MoveTo((size.width() - toolbar_->size().width()) / 2,
			size.height() - toolbar_->size().height());
}

void StudioWindow::OnOpenDialogForScrollView()
{
	Dialog * dialog = Manage(new Dialog("ScrollView"));
	dialog->Resize(500, 400);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	ScrollView* scroll = Manage(new ScrollView);
	Button* test_btn = Manage(new Button("Test test"));
	scroll->Setup(test_btn);

	scroll->MoveTo(50, 25);
	//scroll->Resize(500, 24);

	dialog->AddWidget(scroll);

	AddFrame(dialog);
}

void StudioWindow::OnOpenDialogForNumericalSlider()
{
	Dialog * dialog = Manage(new Dialog("NumericalSlider", new LinearLayout(Vertical)));
	dialog->Resize(500, 400);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	Block* block = new Block(Vertical);

	NumericalSlider* ns1 = Manage(new NumericalSlider);
  NumericalSlider* ns2 = Manage(new NumericalSlider);
  NumericalSlider* ns3 = Manage(new NumericalSlider);

  block->AddWidget(ns1);
  block->AddWidget(ns2);
  block->AddWidget(ns3);

	dialog->AddWidget(block);

	TextEntry* text = new TextEntry;

	//ScrollBar* sb = new ScrollBar(Horizontal);
	dialog->AddWidget(text);

	AddFrame(dialog);
}

void StudioWindow::OnOpenPanel (AbstractButton* btn)
{
	FrameSplitter* splitter = new FrameSplitter;

	Button* btn1 = new Button("Button1");
	Button* btn2 = new Button("Button2");

	Frame* f1 = new Frame(new LinearLayout(Vertical, AlignCenter));
//	f1->EnableViewBuffer();
	Frame* f2 = new Frame(new LinearLayout(Vertical, AlignCenter));
//	f2->EnableViewBuffer();

	f1->AddWidget(btn1);
	f2->AddWidget(btn2);

	splitter->AddFrame(f1);
	splitter->AddFrame(f2);

	splitter->Resize(600, 200);

	AddFrame(splitter);

}

void StudioWindow::OnOpenDialogForBlocks()
{
	Dialog * dialog = Manage(new Dialog("ScrollView"));
	dialog->Resize(500, 400);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	Block* main_block = Manage(new Block(Vertical));
	DBG_SET_NAME(main_block, "MainBlock");

	Block* block1 = Manage(new Block(Horizontal));
	DBG_SET_NAME(block1, "Block1");
	Button* btn1 = Manage(new Button("Button1"));
	Button* btn2 = Manage(new Button("Button2"));
	Button* btn3 = Manage(new Button("Button3"));
	block1->AddWidget(btn1);
	block1->AddWidget(btn2);
	block1->AddWidget(btn3);

	Block* block2 = Manage(new Block(Horizontal));
	DBG_SET_NAME(block2, "Block2");
	Button* btn4 = Manage(new Button("Button4"));
	Button* btn5 = Manage(new Button("Button5"));
	Button* btn6 = Manage(new Button("Button6"));
	block2->AddWidget(btn4);
	block2->AddWidget(btn5);
	block2->AddWidget(btn6);

	main_block->AddWidget(block1);
	main_block->AddWidget(block2);
	main_block->Resize(main_block->GetPreferredSize());
	main_block->MoveTo(100, 100);

	DBG_PRINT_MSG("main block size: (%d, %d)", main_block->size().width(), main_block->size().height());

	dialog->AddWidget(main_block);

	AddFrame(dialog);
}

void StudioWindow::OnOpenDialogForClock()
{
	Dialog * dialog = Manage(new Dialog("Clock"));
	dialog->Resize(500, 400);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	Clock* clock = Manage(new Clock);
	clock->Start();

	dialog->AddWidget(clock);
	clock->MoveTo((dialog->size().width() - clock->size().width()) / 2, (dialog->size().height() - clock->size().height()) / 2);

	AddFrame(dialog);
}

void StudioWindow::OnOpenMenu1()
{
	Menu* menu1 = Manage(new Menu);

	menu1->AddAction("MenuItem1");
	menu1->AddWidget(Manage(new Button("Test")));

  menu1->Resize(menu1->GetPreferredSize());
  menu1->MoveTo((size().width() - menu1->size().width()) / 2, (size().height() - menu1->size().height()) / 2);

	AddFrame(menu1);
}

void StudioWindow::OnOpenDialogForTab()
{
	Tab* tab = Manage(new Tab);
	tab->AddWidget("test1", Manage(new Button("Button1")));
	tab->AddWidget("test2", Manage(new Button("Button2")));

	Dialog * dialog = Manage(new Dialog("Tab"));
	dialog->Resize(500, 400);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	tab->MoveTo(10, 10);

	dialog->AddWidget(tab);

	AddFrame(dialog);
}

void StudioWindow::OnOpenDialogForScrollArea()
{
	ScrollArea* area = Manage(new ScrollArea);

	Dialog * dialog = Manage(new Dialog("Tab"));
	dialog->Resize(500, 400);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	area->MoveTo(10, 10);

	dialog->AddWidget(area);

	AddFrame(dialog);
}

void StudioWindow::OnOpenDialogForTabHeader()
{
	TabHeader* header = Manage(new TabHeader);
	header->AddButton(Manage(new TabButton("tab1")));
	header->AddButton(Manage(new TabButton("tab2")));
	header->AddButton(Manage(new TabButton("tab3")));

	Dialog * dialog = Manage(new Dialog("Tab"));
	dialog->Resize(500, 400);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	header->MoveTo(100, 100);

	dialog->AddWidget(header);

	AddFrame(dialog);
}

void StudioWindow::OnTestAdaptiveLayout ()
{
  Dialog * dialog1 = Manage(
      new Dialog("Horizontal AdaptiveLayout", new AdaptiveLayout(Horizontal)));
  dialog1->Resize(500, 400);
  dialog1->MoveTo(100, (size().height() - dialog1->size().height()) / 2);

  NumericalSlider* ns1 = Manage(new NumericalSlider);
  NumericalSlider* ns2 = Manage(new NumericalSlider);
  NumericalSlider* ns3 = Manage(new NumericalSlider);

  dialog1->AddWidget(ns1);
  dialog1->AddWidget(ns2);
  dialog1->AddWidget(ns3);

  TextEntry* text = new TextEntry;

  //ScrollBar* sb = new ScrollBar(Horizontal);
  dialog1->AddWidget(text);

  AddFrame(dialog1);

  Dialog * dialog2 = Manage(
      new Dialog("Vertical AdaptiveLayout", new AdaptiveLayout(Vertical, AlignLeft)));
  dialog2->Resize(500, 400);
  dialog2->MoveTo(100 + dialog1->size().width() + 50,
                  (size().height() - dialog2->size().height()) / 2);

  NumericalSlider* ns4 = Manage(new NumericalSlider);
  NumericalSlider* ns5 = Manage(new NumericalSlider);
  NumericalSlider* ns6 = Manage(new NumericalSlider);

  dialog2->AddWidget(ns4);
  dialog2->AddWidget(ns5);
  dialog2->AddWidget(ns6);

  Button* btn = new Button;

  //ScrollBar* sb = new ScrollBar(Horizontal);
  dialog2->AddWidget(btn);

  AddFrame(dialog2);

  Dialog * dialog3 = Manage(
      new Dialog("Test Expander", new LinearLayout(Vertical)));
  dialog3->Resize(500, 400);
  dialog3->MoveTo((size().width() - dialog1->size().width()) / 2,
                  (size().height() - dialog2->size().height()) / 2);

  Expander* exp = new Expander("Test Expander");
  Button* btn2 = new Button("Hello World!");
  exp->AddWidget(btn2);

  //ScrollBar* sb = new ScrollBar(Horizontal);
  dialog3->AddWidget(exp);

  AddFrame(dialog3);

}

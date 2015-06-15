/*
 * GLFWContext.cpp
 */

#include "studio-window.hpp"

#include <blendint/gui/abstract-round-frame.hpp>
#include <blendint/gui/menu-button.hpp>
#include <blendint/gui/clock.hpp>
#include <blendint/gui/scroll-area.hpp>
#include <blendint/gui/tab-header.hpp>
#include <blendint/gui/adaptive-layout.hpp>

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
	resized().connect(this, &StudioWindow::OnResize);
}

StudioWindow::~StudioWindow ()
{

}

BI::Frame* StudioWindow::CreateToolBar()
{
	LinearLayout* layout = new LinearLayout(Horizontal);

	Frame* tools = new Frame(layout);
	tools->EnableViewBuffer();

	PushButton* b1 = new PushButton;
	b1->SetIcon(icons()->pixel_icon(Icons::MESH_PLANE));

	PushButton* b2 = new PushButton;
	b2->SetIcon(icons()->pixel_icon(Icons::FULLSCREEN));

	PushButton* b3 = new PushButton;
	b3->SetIcon(icons()->pixel_icon(Icons::SPLITSCREEN));

	Separator* sp1 = new Separator;

	PushButton* b4 = new PushButton;
	b4->SetIcon(icons()->pixel_icon(Icons::OUTLINER_DATA_CAMERA));

	tools->AddWidget(b1);
	tools->AddWidget(b2);
	tools->AddWidget(b3);
	tools->AddWidget(sp1);
	tools->AddWidget(b4);

	tools->Resize(tools->GetPreferredSize());

	b1->clicked().connect(this, &StudioWindow::OnOpenDialogForButtons);
	b2->clicked().connect(this, &StudioWindow::OnOpenDialogForNumericalSlider);
  b3->clicked().connect(this, &StudioWindow::OnTestAdaptiveLayout);
	b4->clicked().connect(this, &StudioWindow::OnTakeScreenshot);

	return tools;
}

void StudioWindow::OnTakeScreenshot ()
{
	DBG_PRINT_MSG("TODO: %s", "check the focused frame and save the view buffer to a image file");
}

void StudioWindow::OnOpenDialogForButtons()
{
	Dialog* dialog = new Dialog("Test", new LinearLayout(Horizontal));

	PushButton* btn = new PushButton("PushButton");
	btn->MoveTo(100, 50);

	ToggleButton* toggle_btn = new ToggleButton("ToggleButton");
	toggle_btn->MoveTo(100, 100);

	TabButton* tab_btn = new TabButton("TabButton");
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
	Dialog* dialog = new Dialog("ButtonTest1");
	TextureView* textureview = new TextureView;
	textureview->MoveTo(50, 50);
	dialog->Resize(textureview->size().width() + 100, textureview->size().height() + 100);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);
	dialog->AddWidget(textureview);
	AddFrame(dialog);
}

void StudioWindow::OnOpenModalDialog()
{
	Dialog * dialog = new Dialog("Hello");
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);
	AddFrame(dialog);
}

void StudioWindow::OnOpenFileSelector()
{
	FileSelector * fs = new FileSelector;
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
	Dialog * dialog = new Dialog("ScrollView");
	dialog->Resize(500, 400);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	ScrollView* scroll = new ScrollView;
	PushButton* test_btn = new PushButton("Test test");
	scroll->Setup(test_btn);

	scroll->MoveTo(50, 25);
	//scroll->Resize(500, 24);

	dialog->AddWidget(scroll);

	AddFrame(dialog);
}

void StudioWindow::OnOpenDialogForNumericalSlider()
{
	Dialog * dialog = new Dialog("NumericalSlider", new LinearLayout(Vertical));
	dialog->Resize(500, 400);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	Block* block = new Block(Vertical);

	NumericalSlider* ns1 = new NumericalSlider;
  NumericalSlider* ns2 = new NumericalSlider;
  NumericalSlider* ns3 = new NumericalSlider;

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

	PushButton* btn1 = new PushButton("Button1");
	PushButton* btn2 = new PushButton("Button2");

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
	Dialog * dialog = new Dialog("ScrollView");
	dialog->Resize(500, 400);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	Block* main_block = new Block(Vertical);
	DBG_SET_NAME(main_block, "MainBlock");

	Block* block1 = new Block(Horizontal);
	DBG_SET_NAME(block1, "Block1");
	PushButton* btn1 = new PushButton("Button1");
	PushButton* btn2 = new PushButton("Button2");
	PushButton* btn3 = new PushButton("Button3");
	block1->AddWidget(btn1);
	block1->AddWidget(btn2);
	block1->AddWidget(btn3);

	Block* block2 = new Block(Horizontal);
	DBG_SET_NAME(block2, "Block2");
	PushButton* btn4 = new PushButton("Button4");
	PushButton* btn5 = new PushButton("Button5");
	PushButton* btn6 = new PushButton("Button6");
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
	Dialog * dialog = new Dialog("Clock");
	dialog->Resize(500, 400);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	Clock* clock = new Clock;
	clock->Start();

	dialog->AddWidget(clock);
	clock->MoveTo((dialog->size().width() - clock->size().width()) / 2, (dialog->size().height() - clock->size().height()) / 2);

	AddFrame(dialog);
}

void StudioWindow::OnOpenMenu1()
{
	Menu* menu1 = new Menu;

	menu1->AddAction("MenuItem1");
	menu1->AddWidget(new PushButton("Test"));

  menu1->Resize(menu1->GetPreferredSize());
  menu1->MoveTo((size().width() - menu1->size().width()) / 2, (size().height() - menu1->size().height()) / 2);

	AddFrame(menu1);
}

void StudioWindow::OnOpenDialogForTab()
{
	Tab* tab = new Tab;
	tab->AddWidget("test1", new PushButton("Button1"));
	tab->AddWidget("test2", new PushButton("Button2"));

	Dialog * dialog = new Dialog("Tab");
	dialog->Resize(500, 400);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	tab->MoveTo(10, 10);

	dialog->AddWidget(tab);

	AddFrame(dialog);
}

void StudioWindow::OnOpenDialogForScrollArea()
{
	ScrollArea* area = new ScrollArea;

	Dialog * dialog = new Dialog("Tab");
	dialog->Resize(500, 400);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	area->MoveTo(10, 10);

	dialog->AddWidget(area);

	AddFrame(dialog);
}

void StudioWindow::OnOpenDialogForTabHeader()
{
	TabHeader* header = new TabHeader;
	header->AddButton(new TabButton("tab1"));
	header->AddButton(new TabButton("tab2"));
	header->AddButton(new TabButton("tab3"));

	Dialog * dialog = new Dialog("Tab");
	dialog->Resize(500, 400);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	header->MoveTo(100, 100);

	dialog->AddWidget(header);

	AddFrame(dialog);
}

void StudioWindow::OnTestAdaptiveLayout ()
{
  Dialog * dialog1 =
      new Dialog("Horizontal AdaptiveLayout", new AdaptiveLayout(Horizontal));
  dialog1->Resize(500, 400);
  dialog1->MoveTo(100, (size().height() - dialog1->size().height()) / 2);

  NumericalSlider* ns1 = new NumericalSlider;
  NumericalSlider* ns2 = new NumericalSlider;
  NumericalSlider* ns3 = new NumericalSlider;

  dialog1->AddWidget(ns1);
  dialog1->AddWidget(ns2);
  dialog1->AddWidget(ns3);

  TextEntry* text = new TextEntry;

  //ScrollBar* sb = new ScrollBar(Horizontal);
  dialog1->AddWidget(text);

  AddFrame(dialog1);

  Dialog * dialog2 =
      new Dialog("Vertical AdaptiveLayout", new AdaptiveLayout(Vertical, AlignLeft));
  dialog2->Resize(500, 400);
  dialog2->MoveTo(100 + dialog1->size().width() + 50,
                  (size().height() - dialog2->size().height()) / 2);

  NumericalSlider* ns4 = new NumericalSlider;
  NumericalSlider* ns5 = new NumericalSlider;
  NumericalSlider* ns6 = new NumericalSlider;

  dialog2->AddWidget(ns4);
  dialog2->AddWidget(ns5);
  dialog2->AddWidget(ns6);

  PushButton* btn = new PushButton;

  //ScrollBar* sb = new ScrollBar(Horizontal);
  dialog2->AddWidget(btn);

  AddFrame(dialog2);

  Dialog * dialog3 =
      new Dialog("Test Expander", new LinearLayout(Vertical));
  dialog3->Resize(500, 400);
  dialog3->MoveTo((size().width() - dialog1->size().width()) / 2,
                  (size().height() - dialog2->size().height()) / 2);

  Expander* exp = new Expander("Test Expander");
  PushButton* btn2 = new PushButton("Hello World!");
  exp->AddWidget(btn2);

  //ScrollBar* sb = new ScrollBar(Horizontal);
  dialog3->AddWidget(exp);

  AddFrame(dialog3);

}

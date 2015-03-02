/*
 * GLFWContext.cpp
 */

#include "studio-window.hpp"

#include <gui/abstract-round-frame.hpp>
#include <gui/menu-button.hpp>
#include <gui/clock.hpp>
#include <gui/scroll-area.hpp>
#include <gui/tabheader.hpp>

using namespace BI;

StudioWindow::StudioWindow(int width, int height, const char* name)
: BI::Window(width, height, name),
  button_(0),
 // pop_(0),
  toolbar_(nullptr)
{
	toolbar_ = CreateToolBar();
	AddFrame(toolbar_);

	OnResize(this, size());
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
	b1->SetIcon(icons->icon_16x16(Icons::MESH_PLANE));

	Button* b2 = new Button;
	b2->SetIcon(icons->icon_16x16(Icons::FULLSCREEN));

	Button* b3 = new Button;
	b3->SetIcon(icons->icon_16x16(Icons::SPLITSCREEN));

	Separator* sp1 = new Separator;

	Button* b4 = new Button;
	b4->SetIcon(icons->icon_16x16(Icons::OUTLINER_DATA_CAMERA));

	tools->AddWidget(b1);
	tools->AddWidget(b2);
	tools->AddWidget(b3);
	tools->AddWidget(sp1);
	tools->AddWidget(b4);

	tools->Resize(tools->GetPreferredSize());

	events()->connect(b1->clicked(), this, &StudioWindow::OnOpenDialogForButtons);
	events()->connect(b4->clicked(), this, &StudioWindow::OnTakeScreenshot);

	return tools;
}

void StudioWindow::OnTakeScreenshot (BI::AbstractButton* sender)
{
	DBG_PRINT_MSG("TODO: %s", "check the focused frame and save the view buffer to a image file");
}

Panel* StudioWindow::CreateButtonsForWidgets()
{
	Panel* panel = Manage(new Panel);

	LinearLayout* vlayout = Manage(new LinearLayout(Vertical));

	Block * group1 = Manage(new Block(Horizontal));

	Button* btn = nullptr;

	btn = Manage(new Button("Buttons"));
	events()->connect(btn->clicked(), this, &StudioWindow::OnOpenDialogForButtons);
	group1->AddWidget(btn);

	vlayout->AddWidget(group1);

	Block * group2 = Manage(new Block(Horizontal));

	btn = Manage(new Button("TextEntry"));
	group2->AddWidget(btn);

	btn = Manage(new Button("Tab"));
	events()->connect(btn->clicked(), this, &StudioWindow::OnOpenDialogForTab);
	group2->AddWidget(btn);

	btn = Manage(new Button("NumericalSlider"));
	events()->connect(btn->clicked(), this, &StudioWindow::OnOpenDialogForNumericalSlider);
	group2->AddWidget(btn);

	vlayout->AddWidget(group2);

	Block * group3 = Manage(new Block(Horizontal));

	btn = Manage(new Button("TextureView"));
	events()->connect(btn->clicked(), this, &StudioWindow::OnOpenDialogForTextureView);
	group3->AddWidget(btn);

	btn = Manage(new Button("ScrollArea"));
	events()->connect(btn->clicked(), this, &StudioWindow::OnOpenDialogForScrollArea);
	group3->AddWidget(btn);

	btn = Manage(new Button("FileSelector"));
	events()->connect(btn->clicked(), this, &StudioWindow::OnOpenFileSelector);
	group3->AddWidget(btn);

	vlayout->AddWidget(group3);

	Block * group4 = Manage(new Block(Horizontal));

	btn = Manage(new Button("TabHeader"));
	events()->connect(btn->clicked(), this, &StudioWindow::OnOpenDialogForTabHeader);
	group4->AddWidget(btn);

	btn = Manage(new Button("Decoration"));
	//events()->connect(btn->clicked(), this, &StudioWindow::OnOpenDialogForDecoration);
	group4->AddWidget(btn);

	btn = Manage(new Button("Modal Dialog"));
	events()->connect(btn->clicked(), this, &StudioWindow::OnOpenModalDialog);
	group4->AddWidget(btn);

	vlayout->AddWidget(group4);

	Block * group5 = Manage(new Block(Horizontal));

	btn = Manage(new Button("ScrollView"));
	events()->connect(btn->clicked(), this, &StudioWindow::OnOpenDialogForScrollView);
	group5->AddWidget(btn);

	btn = Manage(new Button("Blocks"));
	events()->connect(btn->clicked(), this, &StudioWindow::OnOpenDialogForBlocks);
	group5->AddWidget(btn);

	vlayout->AddWidget(group5);

	panel->SetLayout(vlayout);

	return panel;
}

Panel* StudioWindow::CreateButtonsForMenuTest()
{
	Panel* panel = Manage(new Panel);

	LinearLayout* vlayout = Manage(new LinearLayout(Vertical));

	Block * group1 = Manage(new Block(Horizontal));

	Button* btn1 = Manage(new Button("Menu1"));
	Button* btn2 = Manage(new Button("Clock"));
	Button* btn3 = Manage(new Button("Menu3"));

	events()->connect(btn1->clicked(), this, &StudioWindow::OnOpenMenu1);
	events()->connect(btn2->clicked(), this, &StudioWindow::OnOpenDialogForClock);

	group1->AddWidget(btn1);
	group1->AddWidget(btn2);
	group1->AddWidget(btn3);

	vlayout->AddWidget(group1);

	panel->SetLayout(vlayout);

	return panel;
}

void StudioWindow::OnSaveTextureToFile()
{
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

void StudioWindow::OnResize(Window* window, const BI::Size& size)
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
	Dialog * dialog = Manage(new Dialog("NumericalSlider"));
	dialog->Resize(500, 400);
	dialog->MoveTo((size().width() - dialog->size().width()) / 2, (size().height() - dialog->size().height()) / 2);

	Panel* panel1 = Manage(new Panel);
	panel1->MoveTo(20, 20);

	Panel* panel2 = Manage(new Panel);
	panel2->MoveTo(20, 20);
	panel2->Resize(250, 250);

	NumericalSlider* ns = Manage(new NumericalSlider("X:"));
	ns->Resize(150, ns->size().height());
	ns->MoveTo(50, 50);
	ns->SetValue(50.0);

	panel2->AddWidget(ns);
	panel1->AddWidget(panel2);

	dialog->AddWidget(panel1);

	AddFrame(dialog);
}

void StudioWindow::OnOpenPanel1 (AbstractButton* btn)
{
	Panel* panel1 = CreateButtonsForWidgets();
	panel1->Resize(240, 320);
	panel1->MoveTo(20, 20);

	/*
	pop_ = Manage(new PopupFrame);
	pop_->Resize(280, 360);
	pop_->MoveTo(size().width() - pop_->size().width(), 400);

	pop_->AddWidget(panel1);

	AddFrame(pop_);
	*/
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
	menu1->Resize(menu1->GetPreferredSize());
	menu1->MoveTo((size().width() - menu1->size().width()) / 2, (size().height() - menu1->size().height()) / 2);

	menu1->AddAction("MenuItem1");
	menu1->AddButton(Manage(new Button("Test")));

	AddFrame(menu1);
}

void StudioWindow::OnOpenPanel2(BI::AbstractButton* btn)
{
	Panel* panel = CreateButtonsForMenuTest();
	panel->Resize(240, 320);
	panel->MoveTo(20, 20);

	/*
	pop_ = Manage(new PopupFrame);
	pop_->Resize(280, 360);
	pop_->MoveTo(size().width() - pop_->size().width(), 400);

	pop_->AddWidget(panel);

	AddFrame(pop_);
	*/
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
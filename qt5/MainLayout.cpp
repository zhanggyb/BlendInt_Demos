/**
 * Main Layout
 */

#include <gui/abstract-round-widget.hpp>
#include <core/string.hpp>
#include <gui/menu.hpp>
#include <stock/icons.hpp>

#include "MainLayout.hpp"

MainLayout::MainLayout ()
	: m_view3d(0), m_ok(0)
{
	InitOnce();
}

MainLayout::~MainLayout ()
{

}

void MainLayout::InitOnce ()
{
	using namespace BI;

	m_view3d = Manage(new BI::Viewport3D);
	DBG_SET_NAME(m_view3d, "Viewport3D");
	m_view3d->Resize(630, 445);
	m_view3d->SetPosition(5, 30);

	m_ok = Manage(new BI::PushButton("OK"));
	DBG_SET_NAME(m_ok, "OK");

	Append(m_view3d);
	Append(m_ok);
}

void MainLayout::OnOpenClick()
{
}

void MainLayout::OnResize (AbstractWidget* context, int type)
{
	Resize(context->size());
}

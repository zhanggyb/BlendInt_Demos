/**
 * Main Layout
 */

#ifndef _BLENDINT_DEMO_IMGPROC_MAIN_LAYOUT_HPP_
#define _BLENDINT_DEMO_IMGPROC_MAIN_LAYOUT_HPP_

#include <BlendInt/Gui/VLayout.hpp>

#include <blendint/gui/viewport3d.hpp>
#include <blendint/gui/push-button.hpp>

namespace BI = BlendInt;

class MainLayout: public BI::VLayout
{
public:

	MainLayout ();
	
	virtual ~MainLayout ();

private:

	void InitOnce ();

	void OnOpenClick ();

	void OnResize (AbstractWidget* context, int type);

	BI::Viewport3D* m_view3d;
	BI::PushButton* m_ok;
};

#endif

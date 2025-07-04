#ifndef FPV_MENUVIEW_HPP
#define FPV_MENUVIEW_HPP

#include <gui_generated/fpv_menu_screen/FPV_menuViewBase.hpp>
#include <gui/fpv_menu_screen/FPV_menuPresenter.hpp>

class FPV_menuView : public FPV_menuViewBase
{
public:
    FPV_menuView();
    virtual ~FPV_menuView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // FPV_MENUVIEW_HPP

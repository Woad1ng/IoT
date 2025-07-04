#ifndef ABOUT_MENUVIEW_HPP
#define ABOUT_MENUVIEW_HPP

#include <gui_generated/about_menu_screen/about_menuViewBase.hpp>
#include <gui/about_menu_screen/about_menuPresenter.hpp>

class about_menuView : public about_menuViewBase
{
public:
    about_menuView();
    void AboutGetBlueToothCode(char* Data);
    virtual ~about_menuView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ABOUT_MENUVIEW_HPP

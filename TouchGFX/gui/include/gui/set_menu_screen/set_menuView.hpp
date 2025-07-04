#ifndef SET_MENUVIEW_HPP
#define SET_MENUVIEW_HPP

#include <gui_generated/set_menu_screen/set_menuViewBase.hpp>
#include <gui/set_menu_screen/set_menuPresenter.hpp>

class set_menuView : public set_menuViewBase
{
public:
    set_menuView();
    void SetGetBlueToothCode(char* Data);
    virtual ~set_menuView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SET_MENUVIEW_HPP

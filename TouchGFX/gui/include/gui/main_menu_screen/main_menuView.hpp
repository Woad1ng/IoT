#ifndef MAIN_MENUVIEW_HPP
#define MAIN_MENUVIEW_HPP

#include <gui_generated/main_menu_screen/main_menuViewBase.hpp>
#include <gui/main_menu_screen/main_menuPresenter.hpp>

class main_menuView : public main_menuViewBase
{
public:
    main_menuView();
    void MainGetBlueToothCode(char* Data);
    virtual ~main_menuView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MAIN_MENUVIEW_HPP

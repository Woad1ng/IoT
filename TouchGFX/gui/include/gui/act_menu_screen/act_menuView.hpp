#ifndef ACT_MENUVIEW_HPP
#define ACT_MENUVIEW_HPP

#include <gui_generated/act_menu_screen/act_menuViewBase.hpp>
#include <gui/act_menu_screen/act_menuPresenter.hpp>

class act_menuView : public act_menuViewBase
{
public:
    act_menuView();
    void ActGetBlueToothCode(char* Data);
    virtual ~act_menuView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void Get_Angle(float angle);
protected:
};

#endif // ACT_MENUVIEW_HPP

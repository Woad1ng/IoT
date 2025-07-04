#include <gui/set_menu_screen/set_menuView.hpp>
#include <gui/set_menu_screen/set_menuPresenter.hpp>

set_menuPresenter::set_menuPresenter(set_menuView& v)
    : view(v)
{

}

void set_menuPresenter::activate()
{

}

void set_menuPresenter::deactivate()
{

}

void set_menuPresenter::SetGetBlueToothCode(char* Data)
{
    view.SetGetBlueToothCode(Data);
}


#include <gui/act_menu_screen/act_menuView.hpp>
#include <gui/act_menu_screen/act_menuPresenter.hpp>

act_menuPresenter::act_menuPresenter(act_menuView& v)
    : view(v)
{

}

void act_menuPresenter::activate()
{

}

void act_menuPresenter::deactivate()
{

}


void act_menuPresenter::Get_Angle(float angle)
{
    view.Get_Angle(angle);
}

void act_menuPresenter::ActGetBlueToothCode(char* Data)
{
    view.ActGetBlueToothCode(Data);
}



#include <gui/about_menu_screen/about_menuView.hpp>
#include <gui/about_menu_screen/about_menuPresenter.hpp>

about_menuPresenter::about_menuPresenter(about_menuView& v)
    : view(v)
{

}

void about_menuPresenter::activate()
{

}

void about_menuPresenter::deactivate()
{

}

void about_menuPresenter::AboutGetBlueToothCode(char* Data)
{
    view.AboutGetBlueToothCode(Data);
}


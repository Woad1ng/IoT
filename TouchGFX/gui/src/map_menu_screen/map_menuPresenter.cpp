#include <gui/map_menu_screen/map_menuView.hpp>
#include <gui/map_menu_screen/map_menuPresenter.hpp>

map_menuPresenter::map_menuPresenter(map_menuView& v)
    : view(v)
{

}

void map_menuPresenter::activate()
{

}

void map_menuPresenter::deactivate()
{

}

void map_menuPresenter::MapGetBlueToothCode(char* Data)
{
    view.MapGetBlueToothCode(Data);
}


#ifndef MAP_MENUVIEW_HPP
#define MAP_MENUVIEW_HPP

#include <gui_generated/map_menu_screen/map_menuViewBase.hpp>
#include <gui/map_menu_screen/map_menuPresenter.hpp>

class map_menuView : public map_menuViewBase
{
public:
    map_menuView();
    void MapGetBlueToothCode(char* Data);
    virtual ~map_menuView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MAP_MENUVIEW_HPP

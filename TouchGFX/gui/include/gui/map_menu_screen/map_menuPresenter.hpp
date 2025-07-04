#ifndef MAP_MENUPRESENTER_HPP
#define MAP_MENUPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class map_menuView;

class map_menuPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    map_menuPresenter(map_menuView& v);
    virtual void MapGetBlueToothCode(char* Data);
    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~map_menuPresenter() {}

private:
    map_menuPresenter();

    map_menuView& view;
};

#endif // MAP_MENUPRESENTER_HPP

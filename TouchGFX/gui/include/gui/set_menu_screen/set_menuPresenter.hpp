#ifndef SET_MENUPRESENTER_HPP
#define SET_MENUPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class set_menuView;

class set_menuPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    set_menuPresenter(set_menuView& v);
    virtual void SetGetBlueToothCode(char* Data);
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

    virtual ~set_menuPresenter() {}

private:
    set_menuPresenter();

    set_menuView& view;
};

#endif // SET_MENUPRESENTER_HPP

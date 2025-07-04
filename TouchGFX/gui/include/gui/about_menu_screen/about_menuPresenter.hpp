#ifndef ABOUT_MENUPRESENTER_HPP
#define ABOUT_MENUPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class about_menuView;

class about_menuPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    about_menuPresenter(about_menuView& v);
    virtual void AboutGetBlueToothCode(char* Data);
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

    virtual ~about_menuPresenter() {}

private:
    about_menuPresenter();

    about_menuView& view;
};

#endif // ABOUT_MENUPRESENTER_HPP

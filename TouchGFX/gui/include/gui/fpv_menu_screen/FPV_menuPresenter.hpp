#ifndef FPV_MENUPRESENTER_HPP
#define FPV_MENUPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class FPV_menuView;

class FPV_menuPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    FPV_menuPresenter(FPV_menuView& v);

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

    virtual ~FPV_menuPresenter() {}

private:
    FPV_menuPresenter();

    FPV_menuView& view;
};

#endif // FPV_MENUPRESENTER_HPP

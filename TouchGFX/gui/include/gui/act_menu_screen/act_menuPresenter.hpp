#ifndef ACT_MENUPRESENTER_HPP
#define ACT_MENUPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class act_menuView;

class act_menuPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    act_menuPresenter(act_menuView& v);
    virtual void Get_Angle(float angle);
    virtual void ActGetBlueToothCode(char* Data);
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

    virtual ~act_menuPresenter() {}

private:
    act_menuPresenter();

    act_menuView& view;
};

#endif // ACT_MENUPRESENTER_HPP

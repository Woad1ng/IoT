#include <gui/act_menu_screen/act_menuView.hpp>
#include "MyHFile.h"
act_menuView::act_menuView()
{

}

void act_menuView::setupScreen()
{
    act_menuViewBase::setupScreen();
}

void act_menuView::tearDownScreen()
{
    act_menuViewBase::tearDownScreen();
}

void act_menuView::Get_Angle(float angle)
{
    //compass1.setMoveAnimationDelay(1);
    //printf("%f\r\n",angle);
    
    compass1.startMoveAnimation(-angle, 103, 36, touchgfx::EasingEquations::linearEaseIn, touchgfx::EasingEquations::linearEaseIn);

}

void act_menuView::ActGetBlueToothCode(char* Data)
{
    if ((uint8_t)Data[0]==0xAA&&(uint8_t)Data[1]==0xBB&&(uint8_t)Data[2]==0x05&&(uint8_t)Data[3]==0xBB&&(uint8_t)Data[4]==0xAA)
    {
        printf("back\r\n");
        screennum=0;
        application().gotomain_menuScreenCoverTransitionSouth();
    }
}

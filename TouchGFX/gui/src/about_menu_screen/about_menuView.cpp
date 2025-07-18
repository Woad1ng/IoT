#include <gui/about_menu_screen/about_menuView.hpp>
#include "MyHFile.h"
about_menuView::about_menuView()
{

}

void about_menuView::setupScreen()
{
    about_menuViewBase::setupScreen();
}

void about_menuView::tearDownScreen()
{
    about_menuViewBase::tearDownScreen();
}

void about_menuView::AboutGetBlueToothCode(char* Data)
{
    if((uint8_t)Data[0]==0x00&&(uint8_t)Data[1]==0x00)
    {
        printf("backabout\r\n");
        screennum=0;
    }
    if ((uint8_t)Data[0]==0xAA&&(uint8_t)Data[1]==0xBB&&(uint8_t)Data[2]==0x05&&(uint8_t)Data[3]==0xBB&&(uint8_t)Data[4]==0xAA)
    {
        printf("backabout\r\n");
        screennum=0;
        //application().gotomain_menuScreenCoverTransitionNorth();
    }
}


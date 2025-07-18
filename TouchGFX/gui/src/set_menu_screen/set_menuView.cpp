#include <gui/set_menu_screen/set_menuView.hpp>
#include "MyHFile.h"
set_menuView::set_menuView()
{

}

void set_menuView::setupScreen()
{
    set_menuViewBase::setupScreen();
}

void set_menuView::tearDownScreen()
{
    set_menuViewBase::tearDownScreen();
}

void set_menuView::SetGetBlueToothCode(char* Data)
{
    if ((uint8_t)Data[0]==0x00&&(uint8_t)Data[1]==0x00)
    {
        printf("back\r\n");
        screennum=0;
        application().gotomain_menuScreenCoverTransitionEast();
    }
    if ((uint8_t)Data[0]==0xAA&&(uint8_t)Data[1]==0xBB&&(uint8_t)Data[2]==0x05&&(uint8_t)Data[3]==0xBB&&(uint8_t)Data[4]==0xAA)
    {
        printf("back\r\n");
        screennum=0;
        application().gotomain_menuScreenCoverTransitionEast();
    }
}


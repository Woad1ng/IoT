#include <gui/map_menu_screen/map_menuView.hpp>
#include "MyHFile.h"
map_menuView::map_menuView()
{

}

void map_menuView::setupScreen()
{
    map_menuViewBase::setupScreen();
}

void map_menuView::tearDownScreen()
{
    map_menuViewBase::tearDownScreen();
}


void map_menuView::MapGetBlueToothCode(char* Data)
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


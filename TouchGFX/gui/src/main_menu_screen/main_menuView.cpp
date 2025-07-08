#include <gui/main_menu_screen/main_menuView.hpp>


#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/main_menu_screen/main_menuPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>
#include <touchgfx/Color.hpp>
#include "MyHFile.h"
#include <texts/TextKeysAndLanguages.hpp>

main_menuView::main_menuView()
{

}

void main_menuView::setupScreen()
{
    main_menuViewBase::setupScreen();
    main_menuView::MainGetBlueToothCode(RxBuffer);
}

void main_menuView::tearDownScreen()
{
    main_menuViewBase::tearDownScreen();
}



int8_t X=0,Y=0;
void main_menuView::MainGetBlueToothCode(char* Data)
{
    //上
    if((uint8_t)Data[0]==0xAA&&(uint8_t)Data[1]==0xBB&&(uint8_t)Data[2]==0x01&&(uint8_t)Data[3]==0xBB&&(uint8_t)Data[4]==0xAA)
    {
        Y--;if(Y<0){Y=0;}
        printf("%d,%d\r\n",X,Y);
    }
    //下
    else if((uint8_t)Data[0]==0xAA&&(uint8_t)Data[1]==0xBB&&(uint8_t)Data[2]==0x02&&(uint8_t)Data[3]==0xBB&&(uint8_t)Data[4]==0xAA)
    {
        Y++;if(Y>1){Y=1;}
        printf("%d,%d\r\n",X,Y);
    }
    //左
    else if((uint8_t)Data[0]==0xAA&&(uint8_t)Data[1]==0xBB&&(uint8_t)Data[2]==0x03&&(uint8_t)Data[3]==0xBB&&(uint8_t)Data[4]==0xAA)
    {
        X--;if(X<0){X=0;}
        printf("%d,%d\r\n",X,Y);
    }
    //右
    else if((uint8_t)Data[0]==0xAA&&(uint8_t)Data[1]==0xBB&&(uint8_t)Data[2]==0x04&&(uint8_t)Data[3]==0xBB&&(uint8_t)Data[4]==0xAA)
    {
        X++;if(X>2){X=2;}
        printf("%d,%d\r\n",X,Y);
    }
    //确认
    else if((uint8_t)Data[0]==0xAA&&(uint8_t)Data[1]==0xBB&&(uint8_t)Data[2]==0x05&&(uint8_t)Data[3]==0xBB&&(uint8_t)Data[4]==0xAA)
    {
        printf("%d,%d\r\n",X,Y);
        if(X==1&&Y==1)
        {
						modalWindow1.setVisible(true);
						modalWindow1.invalidate();
            Emergency();
					  screennum=5;
        }
        if (X==0&&Y==1)
        {
            application().gotoset_menuScreenCoverTransitionWest();screennum=4;
        }
        if(X==0&&Y==0)
        {
            application().gotomap_menuScreenCoverTransitionWest();screennum=1;
        }
        if(X==1&&Y==0)
        {
            application().gotoact_menuScreenCoverTransitionNorth();screennum=2;
        }
        if(X==2&&Y==0)
        {
            application().gotosensor_menuScreenCoverTransitionEast();screennum=3;
        }
    }
    map_name.setXY(139, 229);
    map_name.setColor(touchgfx::Color::getColorFromRGB(18, 150, 219));
    map_name.setLinespacing(0);
    map_name.setTypedText(touchgfx::TypedText(T___SINGLEUSE_39GU));
    act_name.setXY(370, 229);
    act_name.setColor(touchgfx::Color::getColorFromRGB(18, 150, 219));
    act_name.setLinespacing(0);
    act_name.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZPUA));
    sensor_name.setXY(560, 229);
    sensor_name.setColor(touchgfx::Color::getColorFromRGB(18, 150, 219));
    sensor_name.setLinespacing(0);
    sensor_name.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Y7JC));
    set_name.setXY(139, 422);
    set_name.setColor(touchgfx::Color::getColorFromRGB(18, 150, 219));
    set_name.setLinespacing(0);
    set_name.setTypedText(touchgfx::TypedText(T___SINGLEUSE_JNTJ));
    FPV_name.setXY(578, 422);
    FPV_name.setColor(touchgfx::Color::getColorFromRGB(18, 150, 219));
    FPV_name.setLinespacing(0);
    FPV_name.setTypedText(touchgfx::TypedText(T___SINGLEUSE_UOQU));
    about_name.setXY(370, 422);
    about_name.setColor(touchgfx::Color::getColorFromRGB(18, 150, 219));
    about_name.setLinespacing(0);
    about_name.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YXYQ));
    map_name.invalidate();
    act_name.invalidate();
    sensor_name.invalidate();
    set_name.invalidate();
    about_name.invalidate();
    FPV_name.invalidate();
    if(X==0&&Y==0)
    {
        map_name.setXY(139, 229);
        map_name.setColor(touchgfx::Color::getColorFromRGB(255,0,0));//红色
        map_name.setLinespacing(0);
        map_name.setTypedText(touchgfx::TypedText(T___SINGLEUSE_39GU));
        map_name.invalidate();
    }
    else if(X==1&&Y==0)
    {
        act_name.setXY(370, 229);
        act_name.setColor(touchgfx::Color::getColorFromRGB(255,0,0));//红色
        act_name.setLinespacing(0);
        act_name.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZPUA));
        act_name.invalidate();
    }
    else if(X==2&&Y==0)
    {
        sensor_name.setXY(560, 229);
        sensor_name.setColor(touchgfx::Color::getColorFromRGB(255,0,0));//红色
        sensor_name.setLinespacing(0);
        sensor_name.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Y7JC));
        sensor_name.invalidate();
        
    }
    else if(X==0&&Y==1)
    {
        set_name.setXY(139, 422);
        set_name.setColor(touchgfx::Color::getColorFromRGB(255,0,0));//红色
        set_name.setLinespacing(0);
        set_name.setTypedText(touchgfx::TypedText(T___SINGLEUSE_JNTJ));
        set_name.invalidate();
    }
    else if(X==1&&Y==1)
    {
        about_name.setXY(370, 422);
        about_name.setColor(touchgfx::Color::getColorFromRGB(255,0,0));//红色
        about_name.setLinespacing(0);
        about_name.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YXYQ));
        about_name.invalidate();
    }
    else if(X==2&&Y==1)
    {
        FPV_name.setXY(578, 422);FPV_name.setXY(578, 422);
        FPV_name.setColor(touchgfx::Color::getColorFromRGB(255,0,0));//红色
        FPV_name.setLinespacing(0);
        FPV_name.setTypedText(touchgfx::TypedText(T___SINGLEUSE_UOQU));
        FPV_name.invalidate();
    }

      // // ?? 关键点：强制刷新
}

void main_menuView::Emergency()
{
	
	
		

}



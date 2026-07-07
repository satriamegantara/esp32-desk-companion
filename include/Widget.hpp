#pragma once

#include "LGFX_Config.hpp"

class Widget
{
public:

    virtual void draw(LGFX& lcd)=0;

    virtual void update(LGFX& lcd)=0;

    virtual ~Widget()=default;
};

class ClockWidget : public Widget
{
public:

    void draw(LGFX& lcd) override;

    void update(LGFX& lcd) override;

private:

    String lastTime;
};
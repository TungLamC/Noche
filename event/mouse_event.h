#ifndef NOCHE_MOUSE_EVENT_H
#define NOCHE_MOUSE_EVENT_H

#include <common/alias.h>
#include <event/event.h>

namespace Noche
{
using MouseCode = uint16_t;
enum : MouseCode
{
    // From glfw3.h
    Button0                = 0,
    Button1                = 1,
    Button2                = 2,
    Button3                = 3,
    Button4                = 4,
    Button5                = 5,
    Button6                = 6,
    Button7                = 7,

    ButtonLast             = Button7,
    ButtonLeft             = Button0,
    ButtonRight            = Button1,
    ButtonMiddle           = Button2
};

class MouseMoveEvent: inherit Event
{
public:
    MouseMoveEvent(const real32 x, const real32 y): x(x), y(y) { }

    float GetX() const { return x; }
    float GetY() const { return y; }

    virtual string ToString() const override
    {
        stringstream stream;
        stream << "MouseMove:" << x << "," << y;
        return stream.str();
    }

    EVENT_TYPE(MouseMove)
    EVENT_CATEGORY(Mouse)

private:
    real32 x;
    real32 y;
};

class MouseClickEvent: inherit Event
{
public:
    MouseClickEvent(const MouseCode mousecode): mousecode(mousecode) { }
 
    virtual string ToString() const override
    {
        stringstream stream;
        stream << "MouseClick:" << mousecode;
        return stream.str();
    }

    EVENT_TYPE(MouseClick)
    EVENT_CATEGORY(Mouse)

private:
    MouseCode mousecode;
};

class MouseReleaseEvent: inherit Event
{
public:
    MouseReleaseEvent(const MouseCode mousecode): mousecode(mousecode) { }
 
    virtual string ToString() const override
    {
        stringstream stream;
        stream << "MouseRelease:" << mousecode;
        return stream.str();
    }

     EVENT_TYPE(MouseRelease)
     EVENT_CATEGORY(Mouse)

private:
    MouseCode mousecode;
};

class MouseScrollEvent: inherit Event
{
public:
    MouseScrollEvent(const real32 x, const real32 y): x(x), y(y) { }

    real32 GetOffsetX() const { return x; }
    real32 GetOffsetY() const { return y; }

    virtual string ToString() const override
    {
        stringstream stream;
        stream << "MouseScroll:" << x << ":" << y;
        return stream.str();
    }

    EVENT_TYPE(MouseScroll)
    EVENT_CATEGORY(Mouse)

private:
    real32 x;
    real32 y;
};
}

#endif //NOCHE_MOUSE_EVENT_H

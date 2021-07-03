#ifndef NOCHE_WINDOW_EVENT_H
#define NOCHE_WINDOW_EVENT_H

#include <common/alias.h>
#include <event/event.h>
#include <sstream>

namespace Noche
{
class WindowResizeEvent: inherit Event
{
public:
    WindowResizeEvent(uint32_t width, uint32_t height): width(width), height(height) {}

    uint32_t GetWidth() const { return width; }
    uint32_t GetHeight() const { return height; }

    virtual string ToString() const override
    {
        stringstream stream;
        stream << "WindowResize: " << width << "," << height;
        return stream.str();
    }

    EVENT_TYPE(WindowResize)
    EVENT_CATEGORY(Window)

private:
    uint32_t width;
    uint32_t height;
};

class WindowCloseEvent: inherit Event
{
public:
    WindowCloseEvent() = default;

    EVENT_TYPE(WindowClose)
    EVENT_CATEGORY(Window)

};
}

#endif //NOCHE_WINDOW_EVENT_H

#ifndef NOCHE_EVENT_H
#define NOCHE_EVENT_H

#include <string>
#include <ostream>

namespace Noche
{
using namespace std;

enum class EventType
{
    None,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMove,
    KeyPress, KeyRelease, KeyType,
    MouseClick, MouseRelease, MouseMove, MouseScroll
};

enum class EventCategory
{
    None     = 1 << 0,
    Window   = 1 << 1,
    Keyboard = 1 << 2,
    Mouse    = 1 << 3,
};


#define EVENT_TYPE(TYPE)                                     \
    public: static constexpr EventType type = EventType::TYPE;     \
    virtual EventType GetType() const override { return type; }    \
    virtual const char* GetName() const override { return #TYPE; }

#define EVENT_CATEGORY(CATEGORY) virtual EventCategory GetCategory() const override { return EventCategory::CATEGORY; }

class EventDispatcher;

class Event
{
    friend class EventDispatcher;
public:
    virtual ~Event() = default;

    virtual EventType GetType() const = 0;
    virtual const char* GetName() const = 0;
    virtual EventCategory GetCategory() const = 0;
    virtual string ToString() const { return GetName(); }

    bool IsInCategory(EventCategory category) const { return (int)GetCategory() & (int)category; }

public:
    static constexpr EventType type = EventType::None;

    bool handled = false;
};

class EventDispatcher
{
public:
    EventDispatcher(Event& event): event(event) { }

    template<typename T, typename F>
    bool Dispatch(const F& handler) const
    {
        if (event.GetType() != T::type) return false;
        event.handled |= handler(static_cast<T&>(event));
        return true;
    }

private:
    Event& event;
};

inline ostream& operator<<(ostream& stream, const Event& event)
{
    return stream << event.ToString();
}
}

#endif //NOCHE_EVENT_H

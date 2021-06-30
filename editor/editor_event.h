#ifndef NOCHE_EDITOR_EVENT_H
#define NOCHE_EDITOR_EVENT_H

#include <string>
#include <debug/log.h>

namespace Noche
{
using namespace std;

enum class EditorEventType
{
  None,
  WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMove,
  KeyPressed, KeyReleased,
  MousePressed, MouseReleased, MouseMoved, MouseScrolled
};

enum class EditorEventCategory
{
  None        = 1 << 0,
  Application = 1 << 1,
  Keyboard    = 1 << 2,
  Mouse       = 1 << 3,
};

class EditorEvent
{
  
};
}

#endif //NOCHE_EDITOR_EVENT_H

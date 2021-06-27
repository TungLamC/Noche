#ifndef NOCHE_EDITOR_EVENT_H
#define NOCHE_EDITOR_EVENT_H

#include <string>
#include <debug/log.h>

namespace Noche
{
using namespace std;

enum class EditorEventKind
{
  None        = 1 << 0,
  Application = 1 << 1,
  Input       = 1 << 2,
  Keyboard    = 1 << 3,
  Mouse       = 1 << 4,
  Click       = 1 << 5,
};

enum class EditorEventType
{
  None,
  WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
  KeyPressed, KeyReleased,
  MousePressed, MouseReleased, MouseMoved, MouseScrolled
};

class EditorEvent
{
public:
  virtual const char* Name() const = 0;

  virtual string ToString() const { return Name(); }

  virtual EditorEventType Type() const = 0;

  virtual EditorEventKind Kind() const = 0;
  
  inline bool IsKind(EditorEventKind kind) const { return Kind() && kind; }

protected:
  bool handled = false
};

class EditorKeyEvent: public EditorEvent
{
public:
  inline int KeyCode() const { return keycode; }

protected:
  EditorKeyEvent(int keycode): keycode(keycode) {}
  
  int keycode;
};

class EditorEventDispatcher
{
  
};
}

#endif //NOCHE_EDITOR_EVENT_H

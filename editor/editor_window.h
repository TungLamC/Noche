#ifndef NOCHE_EDITOR_WINDOW_H
#define NOCHE_EDITOR_WINDOW_H

#include <std/alias.h>

namespace Noche
{

class EditorWindow
{
public:
  using EventCallback = Function<void()>;

  virtual ~EditorWindow() = default;

  virtual void OnUpdate() = 0;
  virtual void SetEventCallback(const EventCallback& callback) = 0;
  virtual float GetWidth() const = 0;
  virtual float GetHeight() const = 0;
};
}

#endif //NOCHE_EDITOR_WINDOW_H

#ifndef NOCHE_APPLICATION_H
#define NOCHE_APPLICATION_H

namespace Noche
{
class Application
{
public:
  Application() = default;
  ~Application() = default;
  
  virtual void Run();
};
}

#endif //NOCHE_APPLICATION_H

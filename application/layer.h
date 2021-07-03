#ifndef NOCHE_LAYER_H
#define NOCHE_LAYER_H

#include <noche.h>
#include <event/event.h>

namespace Noche
{
using namespace std;

class Layer
{
public:
    Layer(const string& name = "Layer"): name(name) { }
    virtual ~Layer() = default;

    virtual void OnAttach() { }
    virtual void OnDetach() { }
    virtual void OnUpdate() { }
    virtual void OnEvent(const Event& event) { }

    inline const string& GetName() const { return name; }

protected:
    string name;
};
}

#endif //NOCHE_LAYER_H

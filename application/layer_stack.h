#ifndef NOCHE_LAYER_STACK_H
#define NOCHE_LAYER_STACK_H

#include <vector>
#include <noche.h>
#include <application/layer.h>

namespace Noche
{
using namespace std;

class LayerStack
{
public:
    LayerStack();
    ~LayerStack();

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* layer);
    void PopLayer(Layer* layer);
    void PopOverlay(Layer* layer);

    inline vector<Layer*>::iterator begin() { return layers.begin(); }
    inline vector<Layer*>::iterator end() { return layers.end(); }

private:
    vector<Layer*> layers;
    vector<Layer*>::iterator insert_position;
};
}

#endif //NOCHE_LAYER_STACK_H

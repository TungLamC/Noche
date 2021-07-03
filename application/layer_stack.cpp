#include <application/layer_stack.h>

namespace Noche
{

LayerStack::LayerStack()
{
    insert_position = layers.begin();
}

LayerStack::~LayerStack()
{
    for (Layer* layer: layers)
        delete layer;
}

void LayerStack::PushLayer(Layer* layer)
{
    insert_position = layers.emplace(insert_position, layer);
    layer->OnAttach();
}

void LayerStack::PushOverlay(Layer* layer)
{
    layers.emplace_back(layer);
    layer->OnAttach();
}

void LayerStack::PopLayer(Layer* layer)
{
    auto iterator = find(layers.begin(), layers.end(), layer);
    if (iterator != layers.end())
    {
        layers.erase(iterator);
        insert_position--;
    }
}
void LayerStack::PopOverlay(Layer* layer)
{
    auto iterator = find(layers.begin(), layers.end(), layer);
    if (iterator != layers.end())
        layers.erase(iterator);
}

} 

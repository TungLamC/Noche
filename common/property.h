#ifndef NOCHE_PROPERTY_H
#define NOCHE_PROPERTY_H

#include<functional>

namespace Noche
{

#define property_setter(variableType) [&](variableType value)
#define property_getter(variableType) [&]()->variableType

template <typename ValueType>
class property_rw
{
public:
    typedef std::function<void(ValueType value)> Setter;
    typedef std::function<ValueType(void)> Getter;
    explicit property_rw(Setter setter, Getter getter) : m_setter(setter), m_getter(getter) {}
    property_rw& operator=(ValueType value)
    {
        this->value = value;
        m_setter(this->value);
        return *this;
    }
    property_rw& operator=(const property_rw & instance)
    {
        this->value = instance.m_getter();
        m_setter(this->value);
        return *this;
    }
    operator ValueType()
    {
        return m_getter();
    }
private:
    ValueType value;
    Setter m_setter;
    Getter m_getter;
};
template class property_r
{
public:
    typedef std::functionvoid(ValueType value)> Setter;
    typedef std::functionvoid)> Getter;
    explicit property_r(Getter getter) : m_getter(getter) {}
    operator ValueType()
    {
        return m_getter();
    }
private:
    ValueType value;
    Getter m_getter;
};
template class property_w
{
public:
    typedef std::functionvoid(ValueType value)> Setter;
    explicit property_w(Setter setter) : m_setter(setter) {}
    property_w& operator=(ValueType value)
    {
        this->value = value;
        m_setter(this->value);
        return *this;
    }
    property_w& operator=(const property_w & instance)
    {
        this->value = instance.m_getter();
        m_setter(this->value);
        return *this;
    }
private:
    ValueType value;
    Setter m_setter;
};
}

#endif //NOCHE_PROPERTY_H

#include <debug/log.h>
#include <iostream>
#include <tref/Tref.hpp>

#include <std/reflection.h>
#include <tuple>

using namespace std;
using namespace Noche;

namespace Noche
{
struct Top
{
  friend constexpr auto get_type_info(Top*)
  {
    return type_info("Top", (Top*)0, (tuple<>*)0, sizeof(Top), nullptr);
  }
};

struct Object {};
constexpr auto get_type_info(Object*)
{
  return type_info("Object", (Object*)0, (tuple<Top>*)0, sizeof(Object), nullptr);
}
struct Asset {};
constexpr auto get_type_info(Asset*)
{
  return type_info("Asset", (Asset*)0, (tuple<>*)0, sizeof(Asset), nullptr);
}
struct Component: Object, Asset {};
constexpr auto get_type_info(Component*)
{
  return type_info("Component", (Component*)0, (tuple<Object, Asset>*)0, sizeof(Component), nullptr);
}

template<>
constexpr auto type_of<Component> = get_type_info((Component *) 0);

template<typename T> struct fuck {};
template<typename... Ts>
constexpr auto get_type_info(fuck<Ts...>*)
{
  return type_info("fuck", (fuck<Ts...>*)0, (tuple<>*)0, sizeof(fuck<Ts...>), nullptr);
}

template<typename Ts>
struct template_class: fuck<Ts>, Asset
{
  Ts i;
};
template<typename... Ts>
constexpr auto get_type_info(template_class<Ts...>*)
{
  return type_info("template_class", (template_class<Ts...>*)0, (tuple<fuck<Ts...>, Asset>*)0, sizeof(template_class<Ts...>), nullptr);
}

template<typename... Ts>
constexpr auto type_of<template_class<Ts...>> = get_type_info((template_class<Ts...>*) 0);
}

template<typename T>
struct base {};

template<typename T>
struct derive: base<T>
{
};


int main()
{
  return 0;
}
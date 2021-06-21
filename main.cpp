#include <debug/log.h>
#include <iostream>
#include <tref/Tref.hpp>
#include <core/meta.h>

using namespace lam;

//struct Fuck
//{
//private:
//  using __base_t = typename tref::imp::get_parent<Fuck>::type;
//private:
//  using self_t = Fuck;
//public:
//  using __parent_t = self_t;
//  friend constexpr auto _tref_class_info(Fuck**)
//  {
//    return tref::imp::ClassInfo{(Fuck*)0, "Fuck", sizeof(Fuck), tref::imp::Type<__base_t>{}, nullptr};
//  };;
//
//  int i;
//
//  friend constexpr auto _tref_state(self_t**, tref::imp::FieldTag, 
//    tref::imp::Id<std::tuple_element_t<0, decltype(_tref_state((self_t**)0, tref::imp::FieldTag{}, tref::imp::Id<>{}))>::value + 1> id) ->
//  decltype(std::tuple(id, tref::imp::FieldInfo{id.value, "i", &self_t::i, nullptr}))
//  {
//    return std::tuple(id, tref::imp::FieldInfo{id.value, "i", &self_t::i, nullptr});
//  }
//};
//
//constexpr auto _tref_state(typename tref::imp::get_parent<Fuck>::type**, tref::imp::SubclassTag, tref::imp::Id<
//  std::tuple_element_t<0,
//                       decltype(_tref_state((typename tref::imp::get_parent<Fuck>::type**)0, tref::imp::SubclassTag{},
//                                            tref::imp::Id<>{}))>::value + 1> id) -> decltype(std::tuple(id,
//                                                                                                        tref::imp::Type<
//                                                                                                          Fuck>{}))
//{
//  return std::tuple(id, tref::imp::Type<Fuck>{});
//}
//
//struct Fuck2: Fuck
//{
//  TrefType(Fuck2);
//};
//constexpr auto _tref_state(typename tref::imp::get_parent<Fuck2>::type**, tref::imp::SubclassTag, tref::imp::Id<
//  std::tuple_element_t<0,
//                       decltype(_tref_state((typename tref::imp::get_parent<Fuck2>::type**)0, tref::imp::SubclassTag{},
//                                            tref::imp::Id<>{}))>::value + 1> id) -> decltype(std::tuple(id,
//                                                                                                        tref::imp::Type<
//                                                                                                          Fuck2>{}))
//{
//return std::tuple(id, tref::imp::Type<Fuck2>{});
//}

template<typename F>
void fuck(F&& f)
{
}

int main()
{
  int i = 2;
  return 0;
}
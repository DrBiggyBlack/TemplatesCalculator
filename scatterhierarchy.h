#ifndef SCATTERHIERARCHY_H
#define SCATTERHIERARCHY_H

#include "resourcesinit.h"

#define TYPELIST_1(Type01) TypeList<Type01, NullType>
#define TYPELIST_2(Type01, Type02) TypeList<Type01, TYPELIST_1(Type02)>
#define TYPELIST_3(Type01, Type02, Type03) TypeList<Type01, TYPELIST_2(Type02, Type03)>

#define TYPE_CONVERTION_RESULT(resultValue) (static_cast<ValueHolder<QString>&>(resultValue)).value_


class NullType {};
struct EmptyType {};

template<typename T, typename U> struct TypeList
{
    T Head;
    U Tail;
};


template <typename TList, template<typename> class Unit> class GenScatterHierarchy;

template <typename T1, typename T2, template<typename> class Unit> class GenScatterHierarchy<TypeList<T1, T2>, Unit>
        : public GenScatterHierarchy<T1, Unit>, public GenScatterHierarchy<T2, Unit>
{
public:
    typedef TypeList<T1, T2> TList;
    typedef GenScatterHierarchy<T1, Unit> LeftBase;
    typedef GenScatterHierarchy<T2, Unit> RightBase;
};
template <typename AtomicType, template <typename> class Unit> class GenScatterHierarchy
        :public Unit<AtomicType>
{
    typedef Unit<AtomicType> LeftBase;
};
template <template<typename> class Unit> class GenScatterHierarchy<NullType, Unit>
{

};


template <typename T> struct ValueHolder
{
    T value_;
};

typedef GenScatterHierarchy <TYPELIST_3(int, double, QString), ValueHolder> baseTypesValue;

#endif // SCATTERHIERARCHY_H

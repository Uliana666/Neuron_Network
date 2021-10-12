
#ifndef NEURON_NETWORK_APPLY_HPP
#define NEURON_NETWORK_APPLY_HPP

#include "Functions.hpp"

template<size_t deep = 0, class TFunction, CTensor TArgument>
constexpr void ActivateInline(TArgument &arg, TFunction &&function) {
    if constexpr(TArgument::dim == deep) arg = function(arg);
    else for (size_t i = 0; i < arg.size(); ++i) { ActivateInline<deep>(arg[i], function); }
}

template<size_t deep = 0, class TFunction, CTensor TArgument>
constexpr auto Activate(TArgument arg, TFunction &&function) {
    ActivateInline<deep>(arg, function);
    return arg;
}
template<size_t deep = 0, class TFunction, CTensor TArgument>
constexpr void ForwardFunctionInline(TArgument &arg, TFunction &&function) {
    if constexpr(TArgument::dim == deep) arg = function.Forward(arg);
    else for (size_t i = 0; i < arg.size(); ++i) { ForwardFunctionInline<deep>(arg[i], function); }
}

template<size_t deep = 0, class TFunction, CTensor TArgument>
constexpr auto ForwardFunction(TArgument arg, TFunction &&function) {
    ForwardFunctionInline<deep>(arg, function);
    return arg;
}
template<size_t deep = 0, class TFunction, CTensor TArgument>
constexpr void BackwardFunctionInline(TArgument &arg, TFunction &&function) {
    if constexpr(TArgument::dim == deep) arg = function.Backward(arg);
    else for (size_t i = 0; i < arg.size(); ++i) { BackwardFunctionInline<deep>(arg[i], function); }
}

template<size_t deep = 0, class TFunction, CTensor TArgument>
constexpr auto BackwardFunction(TArgument arg, TFunction &&function) {
    BackwardFunctionInline<deep>(arg, function);
    return arg;
}
#endif

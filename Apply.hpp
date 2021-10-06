
#ifndef NEURON_NETWORK_APPLY_H
#define NEURON_NETWORK_APPLY_H

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
#endif

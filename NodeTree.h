#ifndef NEURON_NETWORK_NODETREE_H
#define NEURON_NETWORK_NODETREE_H


struct NodeTree {
    virtual double Calc(const std::unordered_map<string, double> &data) = 0;

    virtual ~NodeTree() {}
};


#endif

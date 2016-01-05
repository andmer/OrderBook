//
// Created by amermegas on 1/4/2016.
//

#ifndef ORDERBOOK_ORDERBOOK_H
#define ORDERBOOK_ORDERBOOK_H

#include <map>

class OrderBook {
    std::map<int, int> bids;
    std::map<int, int> asks;
public:
    inline bool is_empty() const {
        return bids.empty() && asks.empty();
    }
};


#endif //ORDERBOOK_ORDERBOOK_H

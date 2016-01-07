//
// Created by amermegas on 1/4/2016.
//

#include "OrderBook.h"

bool
OrderBook::is_empty() const {
    return bids.empty() && asks.empty();
}

void
OrderBook::add_bid(int price, int amount) {
    add(price, amount, true);
}

void
OrderBook::add_ask(int price, int amount) {
    add(price, amount, false);
}

void
OrderBook::add(int price, int amount, bool bid) {
    (bid ? bids : asks)[price] += amount;
}

std::ostream&
operator<<(std::ostream& os, const OrderBook& book) {
    if (book.is_empty()) {
        os << "ORDER BOOK EMPTY";
    } else {
        for (auto it = book.asks.rbegin(); it != book.asks.rend(); ++it) {
            os << it->first << "\t" << it->second << std::endl;
        }
        os << std::endl;
        for (auto it = book.bids.rbegin(); it != book.bids.rend(); ++it) {
            os << it->first << "\t" << it->second << std::endl;
        }
    }
    return os;
}

OrderBook::BidAsk
OrderBook::get_bid_ask() const {
    BidAsk result;
    auto best_bid = bids.rbegin();
    if (best_bid != bids.rend()) {
        result.bid = *best_bid;
    }
    auto best_ask = asks.begin();
    if (best_ask != asks.end()) {
        result.ask = *best_ask;
    }
    return result;
}

void
OrderBook::remove_bid(int price, int amount) {
    remove(price, amount, true);
}

void
OrderBook::remove_ask(int price, int amount) {
    remove(price, amount, false);
}

void
OrderBook::remove(int price, int amount, bool bid) {
    auto& map = bid ? bids : asks;
    auto it = map.find(price);
    if (it != map.end()) {
        it->second -= amount;
        if (it->second == 0) {
            map.erase(it);
        }
    }
}

boost::optional<int>
OrderBook::BidAsk::spread() const {
    auto result = boost::optional<int>();
    if (bid.is_initialized() && ask.is_initialized()) {
        result = ask.get().first - bid.get().first;
    }
    return result;
}

//
// Created by amermegas on 1/4/2016.
//

#include "SomeTests.h"

TEST(tests, OrderBookEmptyByDefault) {
    OrderBook book;
    EXPECT_TRUE(book.is_empty());
}

TEST(tests, OrderBookAdd) {
    OrderBook book;
    book.add_bid(123, 456);
    auto bidask = book.get_bid_ask();
    EXPECT_TRUE(bidask.bid.is_initialized());
    auto bid = bidask.bid.get();
    EXPECT_EQ(123, bid.first);
    EXPECT_EQ(456, bid.second);
}

TEST(tests, OrderBookRemove) {
    OrderBook book;
    book.add_bid(123, 456);

    auto bidask = book.get_bid_ask();
    EXPECT_TRUE(bidask.bid.is_initialized());
    auto bid = bidask.bid.get();
    EXPECT_EQ(123, bid.first);
    EXPECT_EQ(456, bid.second);

    book.remove_bid(123, 1);
    bidask = book.get_bid_ask();
    bid = bidask.bid.get();
    EXPECT_EQ(123, bid.first);
    EXPECT_EQ(455, bid.second);

    book.remove_bid(123, 455);
    EXPECT_TRUE(book.is_empty());
}

TEST(tests, Spread) {
    OrderBook book;
    book.add_ask(100, 100);
    book.add_bid(98, 100);

    auto spread = book.get_bid_ask().spread();
    EXPECT_EQ(2, spread.get());
}

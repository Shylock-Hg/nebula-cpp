/* Copyright (c) 2020 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#include <glog/logging.h>
#include <gtest/gtest.h>
#include <gtest/gtest_prod.h>

#include <nebula/client/ConnectionPool.h>
#include <nebula/client/Init.h>
#include <nebula/client/Session.h>

#include "./ClientTest.h"

// Require a nebula server could access

#define kServerHost "graphd"

class AddressTest : public ClientTest {};

TEST_F(AddressTest, One) {
    nebula::ConnectionPool pool;
    pool.init({kServerHost ":3699"}, nebula::Config{});
}

TEST_F(AddressTest, Multiple) {
    nebula::ConnectionPool pool;
    pool.init({"graphd1:3699"}, nebula::Config{});
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    nebula::init(&argc, &argv);
    google::SetStderrLogging(google::INFO);

    return RUN_ALL_TESTS();
}

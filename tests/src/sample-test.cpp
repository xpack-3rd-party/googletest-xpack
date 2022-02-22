/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/platform.h>
#include "gtest/gtest.h"
// #include <unistd.h>
// #include <stdio.h>

// using namespace micro_os_plus;

// ----------------------------------------------------------------------------

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
// #pragma GCC diagnostic ignored "-Waggregate-return"

// ----------------------------------------------------------------------------

// Simple examples of functions to be tested.
static int
compute_one (void)
{
  return 1;
}

static const char*
compute_aaa (void)
{
  return "aaa";
}


TEST(Suite, Case1) {
  EXPECT_EQ(1, compute_one());
  EXPECT_STREQ("aaa", compute_aaa());
}

static bool
compute_condition (void)
{
  return true;
}

TEST(Suite, Case2) {
  EXPECT_TRUE(compute_condition());
}

// ----------------------------------------------------------------------------

class MyFixture : public ::testing::Test {
 protected:
  void SetUp() override {
    one = 1;
    aaa = const_cast<char*>("aaa");
    printf("%s\n", __PRETTY_FUNCTION__);
  }

  void TearDown() override {
    printf("%s\n", __PRETTY_FUNCTION__);
  }

  int one;
  char* aaa;
};

TEST_F(MyFixture, CaseOne) {
  EXPECT_EQ(1, one);
}

TEST_F(MyFixture, CaseTwo) {
  EXPECT_STREQ("aaa", aaa);
}

// ----------------------------------------------------------------------------

class MyEnvironment : public ::testing::Environment {
 public:
  ~MyEnvironment() override {}

  // Override this to define how to set up the environment.
  void SetUp() override {
    printf("%s\n", __PRETTY_FUNCTION__);
  }

  // Override this to define how to tear down the environment.
  void TearDown() override {
    printf("%s\n", __PRETTY_FUNCTION__);
  }
};

int
main ([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);

  [[maybe_unused]] testing::Environment* const meEnv =
    testing::AddGlobalTestEnvironment(new MyEnvironment);

  return RUN_ALL_TESTS();
}

// ----------------------------------------------------------------------------

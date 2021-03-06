/**
 *  Copyright (c) 2014-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed in accordance with the terms specified in
 *  the LICENSE file found in the root directory of this source tree.
 */

// Sanity check integration test for mounts
// Spec file: specs/posix/mounts.table

#include <osquery/tests/integration/tables/helper.h>

namespace osquery {
namespace table_tests {

class mounts : public testing::Test {
 protected:
  void SetUp() override {
    setUpEnvironment();
  }
};

TEST_F(mounts, test_sanity) {
  ValidationMap row_map = {
      {"device", NormalType},
      {"device_alias", NormalType},
      {"path", NormalType},
      {"type", NormalType},
      {"blocks_size", IntType},
      {"blocks", IntType},
      {"blocks_free", IntType},
      {"blocks_available", IntType},
      {"inodes", IntType},
      {"inodes_free", IntType},
      {"flags", NormalType},
  };

  auto const data = execute_query("select * from mounts");
  ASSERT_FALSE(data.empty());
  validate_rows(data, row_map);
}

} // namespace table_tests
} // namespace osquery

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "gtest/gtest.h"

#include "BlackRoot/Pubc/Tuple.h"

using tuple_i1 = BlackRoot::Math::Tuple1dDef<int, 1>::Tuple1dAbstract;
using tuple_i2 = BlackRoot::Math::Tuple1dDef<int, 2>::Tuple1dAbstract;
using tuple_i3 = BlackRoot::Math::Tuple1dDef<int, 3>::Tuple1dAbstract;
using tuple_i4 = BlackRoot::Math::Tuple1dDef<int, 4>::Tuple1dAbstract;

TEST(Tuple1dDef, Tuple_Abstract) {
        // sizeof(...) returns >= 1
    EXPECT_EQ(sizeof(BlackRoot::Math::Tuple1dDef<int, 1>), 1);
    EXPECT_EQ(sizeof(BlackRoot::Math::Tuple1dDef<int, 2>), 1);
    EXPECT_EQ(sizeof(BlackRoot::Math::Tuple1dDef<int, 3>), 1);
    EXPECT_EQ(sizeof(BlackRoot::Math::Tuple1dDef<int, 4>), 1);

    EXPECT_EQ(tuple_i1::Size, 1);
    EXPECT_EQ(tuple_i2::Size, 2);
    EXPECT_EQ(tuple_i3::Size, 3);
    EXPECT_EQ(tuple_i4::Size, 4);

    EXPECT_EQ(sizeof(tuple_i1::e), sizeof(int)*1);
    EXPECT_EQ(sizeof(tuple_i2::e), sizeof(int)*2);
    EXPECT_EQ(sizeof(tuple_i3::e), sizeof(int)*3);
    EXPECT_EQ(sizeof(tuple_i4::e), sizeof(int)*4);
}

TEST(Tuple1dDef, Tuple_i3_Operators) {
    tuple_i3 a = { 1, 2, 3 };
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 2);
    EXPECT_EQ(a[2], 3);

    tuple_i3 b = a;
    EXPECT_TRUE(a == b);
    EXPECT_TRUE(b == a);

    a.set_to(4);
    EXPECT_EQ(a[0], 4);
    EXPECT_EQ(a[1], 4);
    EXPECT_EQ(a[2], 4);

    EXPECT_TRUE(a != b);
    EXPECT_TRUE(b != a);

    EXPECT_TRUE(a.is_real());
}
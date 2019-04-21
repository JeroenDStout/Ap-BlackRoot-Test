/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "gtest/gtest.h"

#include "BlackRoot/Pubc/Tensor.h"
#include "BlackRoot/Pubc/Rotor.h"

using quat_f = BlackRoot::Math::QuaternionDef<float>::QuaternionAbstract;

TEST(QuaternionDef, Quaternion_Abstract) {
        // sizeof(...) returns >= 1
    EXPECT_EQ(sizeof(BlackRoot::Math::QuaternionDef<float>), 1);

    EXPECT_EQ(quat_f::Size, 4);

    EXPECT_EQ(sizeof(quat_f), sizeof(float)*4);

    EXPECT_EQ(quat_f::Operating_Dimensionality, 3);
    EXPECT_EQ(quat_f::EquivalentMatrixType::Column_Count, 3);
    EXPECT_EQ(quat_f::EquivalentMatrixType::Row_Count, 3);
}
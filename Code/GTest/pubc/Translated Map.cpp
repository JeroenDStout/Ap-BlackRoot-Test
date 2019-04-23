/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "gtest/gtest.h"

#include "BlackRoot/Pubc/Tensor.h"
#include "BlackRoot/Pubc/Transformation.h"

using mat_1x1   = BlackRoot::Math::MatrixDef<double, 1, 1>::MatrixAbstract;
using mat_2x2   = BlackRoot::Math::MatrixDef<double, 2, 2>::MatrixAbstract;
using mat_3x3   = BlackRoot::Math::MatrixDef<double, 3, 3>::MatrixAbstract;
using mat_4x4   = BlackRoot::Math::MatrixDef<double, 4, 4>::MatrixAbstract;
using mat_10x10 = BlackRoot::Math::MatrixDef<double, 10, 10>::MatrixAbstract;

using vec_1     = BlackRoot::Math::VectorDef<double, 1>::VectorAbstract;
using vec_2     = BlackRoot::Math::VectorDef<double, 2>::VectorAbstract;
using vec_3     = BlackRoot::Math::VectorDef<double, 3>::VectorAbstract;
using vec_4     = BlackRoot::Math::VectorDef<double, 4>::VectorAbstract;
using vec_10    = BlackRoot::Math::VectorDef<double, 10>::VectorAbstract;

using trmap_mv1   = BlackRoot::Math::TranslatedMap<mat_1x1, vec_1>;
using trmap_mv2   = BlackRoot::Math::TranslatedMap<mat_2x2, vec_2>;
using trmap_mv3   = BlackRoot::Math::TranslatedMap<mat_3x3, vec_3>;
using trmap_mv4   = BlackRoot::Math::TranslatedMap<mat_4x4, vec_4>;
using trmap_mv10  = BlackRoot::Math::TranslatedMap<mat_10x10, vec_10>;

TEST(TranslatedMap, TrMap_Abstract) {
    EXPECT_EQ(trmap_mv1::Size, 2);
    EXPECT_EQ(trmap_mv2::Size, 6);
    EXPECT_EQ(trmap_mv3::Size, 12);
    EXPECT_EQ(trmap_mv4::Size, 20);
    EXPECT_EQ(trmap_mv10::Size, 110);

    EXPECT_EQ(sizeof(trmap_mv1),  sizeof(double)*trmap_mv1::Size);
    EXPECT_EQ(sizeof(trmap_mv2),  sizeof(double)*trmap_mv2::Size);
    EXPECT_EQ(sizeof(trmap_mv3),  sizeof(double)*trmap_mv3::Size);
    EXPECT_EQ(sizeof(trmap_mv4),  sizeof(double)*trmap_mv4::Size);
    EXPECT_EQ(sizeof(trmap_mv10), sizeof(double)*trmap_mv10::Size);

    EXPECT_EQ(trmap_mv1::Operating_Dimensionality, 1);
    EXPECT_EQ(trmap_mv2::Operating_Dimensionality, 2);
    EXPECT_EQ(trmap_mv3::Operating_Dimensionality, 3);
    EXPECT_EQ(trmap_mv4::Operating_Dimensionality, 4);
    EXPECT_EQ(trmap_mv10::Operating_Dimensionality, 10);
}
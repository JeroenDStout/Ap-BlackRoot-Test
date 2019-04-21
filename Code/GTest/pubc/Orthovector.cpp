/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "gtest/gtest.h"

#include "BlackRoot/Pubc/Tensor.h"

using vector_f1 = BlackRoot::Math::OrthoVectorDef<float, 1>::OrthovectorAbstract;
using vector_f2 = BlackRoot::Math::OrthoVectorDef<float, 2>::OrthovectorAbstract;
using vector_f3 = BlackRoot::Math::OrthoVectorDef<float, 3>::OrthovectorAbstract;
using vector_f4 = BlackRoot::Math::OrthoVectorDef<float, 4>::OrthovectorAbstract;

TEST(OrthovectorDef, Orthovector_Abstract) {
    EXPECT_EQ(sizeof(BlackRoot::Math::OrthoVectorDef<int, 1>), 1);
    EXPECT_EQ(sizeof(BlackRoot::Math::OrthoVectorDef<int, 2>), 1);
    EXPECT_EQ(sizeof(BlackRoot::Math::OrthoVectorDef<int, 3>), 1);
    EXPECT_EQ(sizeof(BlackRoot::Math::OrthoVectorDef<int, 4>), 1);

    EXPECT_EQ(vector_f1::Size, 1);
    EXPECT_EQ(vector_f2::Size, 2);
    EXPECT_EQ(vector_f3::Size, 3);
    EXPECT_EQ(vector_f4::Size, 4);

    EXPECT_EQ(sizeof(vector_f1), sizeof(float)*1);
    EXPECT_EQ(sizeof(vector_f2), sizeof(float)*2);
    EXPECT_EQ(sizeof(vector_f3), sizeof(float)*3);
    EXPECT_EQ(sizeof(vector_f4), sizeof(float)*4);
    
    EXPECT_TRUE(vector_f1::Is_Vector);
    EXPECT_TRUE(vector_f2::Is_Vector);
    EXPECT_TRUE(vector_f3::Is_Vector);
    EXPECT_TRUE(vector_f4::Is_Vector);
    
    EXPECT_EQ(vector_f1::Operating_Dimensionality, 1);
    EXPECT_EQ(vector_f2::Operating_Dimensionality, 2);
    EXPECT_EQ(vector_f3::Operating_Dimensionality, 3);
    EXPECT_EQ(vector_f4::Operating_Dimensionality, 4);
}

TEST(OrthovectorDef, Orthovector_Operators) {
    vector_f3 a(1.f, 1.f, 1.f);
    EXPECT_FLOAT_EQ(a.length(), sqrt(3.f));
    EXPECT_FLOAT_EQ(a.length_squared(), 3.f);
    
    vector_f3 b(2.f, 2.f, 2.f);
    EXPECT_FLOAT_EQ(b.length(), sqrt(12.f));
    EXPECT_FLOAT_EQ(b.length_squared(), 12.f);

    a.normalise(1.f);
    EXPECT_FLOAT_EQ(a.length(), 1.f);

    a.normalise(2.f);
    EXPECT_FLOAT_EQ(a.length(), 2.f);

    a.normalise(0.f);
    EXPECT_FLOAT_EQ(a.length(), 0.f);

    a.normalise_safe(1.f);
    EXPECT_TRUE(a.is_real());
    EXPECT_FLOAT_EQ(a.length(), 0.f);

    a.normalise(1.f);
    EXPECT_FALSE(a.is_real());
    
    vector_f3 o1(1.f,  3.f,  2.f);
    vector_f3 o2(3.f, -1.f,  0.f);
    vector_f3 o3(1.f,  3.f, -5.f);
    
    EXPECT_EQ(o1 * o2, o2 * o1);
    EXPECT_EQ(o1 * o3, o3 * o1);
    EXPECT_EQ(o1 * o2, o2 * o1);
    EXPECT_EQ(o3 * o2, o2 * o3);

    EXPECT_FLOAT_EQ(o1 * o2, 0.f);
    EXPECT_FLOAT_EQ(o1 * o3, 0.f);
    EXPECT_FLOAT_EQ(o2 * o3, 0.f);
    
    vector_f3 c1(2.f, 3.f, 4.f);
    vector_f3 c2(5.f, 6.f, 7.f);

    auto q = c1.as_ortho_vector() ^ c2.as_ortho_vector();

    auto cr1 = c1 ^ c2;
    auto cr2 = c2 ^ c1;

    EXPECT_FLOAT_EQ(
        (cr1 - vector_f3(-3.f,  6.f, -3.f)).length_squared(), 0.f);
    EXPECT_FLOAT_EQ(
        (cr2 - vector_f3( 3.f, -6.f,  3.f)).length_squared(), 0.f);

    cr1 -= c1.cross(c2);
    EXPECT_EQ(cr1.length(), 0.f);
}
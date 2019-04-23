/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "gtest/gtest.h"

#include "BlackRoot/Pubc/Tensor.h"

using vector_i1 = BlackRoot::Math::VectorDef<int, 1>::VectorAbstract;
using vector_i2 = BlackRoot::Math::VectorDef<int, 2>::VectorAbstract;
using vector_i3 = BlackRoot::Math::VectorDef<int, 3>::VectorAbstract;
using vector_i4 = BlackRoot::Math::VectorDef<int, 4>::VectorAbstract;

using vector_f1 = BlackRoot::Math::VectorDef<float, 1>::VectorAbstract;
using vector_f2 = BlackRoot::Math::VectorDef<float, 2>::VectorAbstract;
using vector_f3 = BlackRoot::Math::VectorDef<float, 3>::VectorAbstract;
using vector_f4 = BlackRoot::Math::VectorDef<float, 4>::VectorAbstract;

using covector_i1 = BlackRoot::Math::CovectorDef<int, 1>::VectorAbstract;
using covector_i2 = BlackRoot::Math::CovectorDef<int, 2>::VectorAbstract;
using covector_i3 = BlackRoot::Math::CovectorDef<int, 3>::VectorAbstract;
using covector_i4 = BlackRoot::Math::CovectorDef<int, 4>::VectorAbstract;

TEST(VectorDef, Vector_Abstract) {
    EXPECT_EQ(sizeof(BlackRoot::Math::VectorDef<int, 1>), 1);
    EXPECT_EQ(sizeof(BlackRoot::Math::VectorDef<int, 2>), 1);
    EXPECT_EQ(sizeof(BlackRoot::Math::VectorDef<int, 3>), 1);
    EXPECT_EQ(sizeof(BlackRoot::Math::VectorDef<int, 4>), 1);

    EXPECT_EQ(vector_i1::Size, 1);
    EXPECT_EQ(vector_i2::Size, 2);
    EXPECT_EQ(vector_i3::Size, 3);
    EXPECT_EQ(vector_i4::Size, 4);

    EXPECT_EQ(vector_f1::Size, 1);
    EXPECT_EQ(vector_f2::Size, 2);
    EXPECT_EQ(vector_f3::Size, 3);
    EXPECT_EQ(vector_f4::Size, 4);

    EXPECT_EQ(sizeof(vector_i1), sizeof(int)*1);
    EXPECT_EQ(sizeof(vector_i2), sizeof(int)*2);
    EXPECT_EQ(sizeof(vector_i3), sizeof(int)*3);
    EXPECT_EQ(sizeof(vector_i4), sizeof(int)*4);

    EXPECT_EQ(sizeof(vector_f1), sizeof(float)*1);
    EXPECT_EQ(sizeof(vector_f2), sizeof(float)*2);
    EXPECT_EQ(sizeof(vector_f3), sizeof(float)*3);
    EXPECT_EQ(sizeof(vector_f4), sizeof(float)*4);
    
    EXPECT_TRUE(vector_i1::Is_Vector);
    EXPECT_TRUE(vector_i2::Is_Vector);
    EXPECT_TRUE(vector_i3::Is_Vector);
    EXPECT_TRUE(vector_i4::Is_Vector);
    
    EXPECT_TRUE(vector_f1::Is_Vector);
    EXPECT_TRUE(vector_f2::Is_Vector);
    EXPECT_TRUE(vector_f3::Is_Vector);
    EXPECT_TRUE(vector_f4::Is_Vector);
    
    EXPECT_EQ(vector_i1::Operating_Dimensionality, 1);
    EXPECT_EQ(vector_i2::Operating_Dimensionality, 2);
    EXPECT_EQ(vector_i3::Operating_Dimensionality, 3);
    EXPECT_EQ(vector_i4::Operating_Dimensionality, 4);
    
    EXPECT_EQ(vector_f1::Operating_Dimensionality, 1);
    EXPECT_EQ(vector_f2::Operating_Dimensionality, 2);
    EXPECT_EQ(vector_f3::Operating_Dimensionality, 3);
    EXPECT_EQ(vector_f4::Operating_Dimensionality, 4);
}

TEST(VectorDef, Vector_i3_Operators_Inherited) {
    vector_i3 a = { 1, 2, 3 };

    EXPECT_EQ(a.elem<0>(), 1);
    EXPECT_EQ(a.elem<1>(), 2);
    EXPECT_EQ(a.elem<2>(), 3);

    vector_i3 b = a;
    EXPECT_TRUE(a == b);
    EXPECT_TRUE(b == a);

    a.set_to(4);
    EXPECT_EQ(a.elem<0>(), 4);
    EXPECT_EQ(a.elem<1>(), 4);
    EXPECT_EQ(a.elem<2>(), 4);

    EXPECT_TRUE(a != b);
    EXPECT_TRUE(b != a);

    EXPECT_TRUE(a.is_real());

    auto copy = a.as_tuple().as<vector_i3>();
    EXPECT_TRUE(a == copy);
}

TEST(VectorDef, Vector_i3_Operators) {
    vector_i3 a = { 1, 2, 3 };
    vector_i3 b = { 5, 5, 5 };
    vector_i3 z = { 9, 8, 7 };
    
    EXPECT_EQ(a+b, b+a);
    EXPECT_EQ(a+(b+z), (a+b)+z);

    vector_i3 c = a+b;
    EXPECT_EQ(c, vector_i3(6, 7, 8));

    vector_i3 d = b-a;
    EXPECT_EQ(d, vector_i3(4, 3, 2));
    
    vector_i3 e = { 0, 0, 0 };
    e += a;
    EXPECT_EQ(e, a);
    e += b;
    EXPECT_EQ(e, a+b);
    
    e -= a;
    EXPECT_EQ(e, b);
    e -= b;
    EXPECT_EQ(e, vector_i3(0, 0, 0));
    
    vector_i3 f = { 2, 4, 6 };
    vector_i3 g = f * 2;
    EXPECT_EQ(g, f+f);
    g *= 4;
    EXPECT_EQ(g, f+f+f+f+f+f+f+f);

    g /= 2;
    EXPECT_EQ(g, f+f+f+f);
    g = f / 2;
    EXPECT_EQ(g, vector_i3(1, 2, 3));
}

TEST(VectorDef, Vector_f3_Operators) {
    vector_f3 a = { 1.f, 2.f, 3.f };
    vector_f3 b = { 5.f, 5.f, 5.f };
    vector_f3 z = { 9.f, 8.f, 7.f };
    
    EXPECT_EQ(a+b, b+a);
    EXPECT_EQ(a+(b+z), (a+b)+z);

    vector_f3 c = a+b;
    EXPECT_EQ(c, vector_f3(6.f, 7.f, 8.f));

    vector_f3 d = b-a;
    EXPECT_EQ(d, vector_f3(4.f, 3.f, 2.f));
    
    vector_f3 e = { 0.f, 0.f, 0.f };
    e += a;
    EXPECT_EQ(e, a);
    e += b;
    EXPECT_EQ(e, a+b);
    
    e -= a;
    EXPECT_EQ(e, b);
    e -= b;
    EXPECT_EQ(e, vector_f3(0.f, 0.f, 0.f));
    
    vector_f3 f = { 2.f, 4.f, 6.f };
    vector_f3 g = f * 2.f;
    EXPECT_EQ(g, f+f);
    g *= 4.f;
    EXPECT_EQ(g, f+f+f+f+f+f+f+f);

    g /= 2.f;
    EXPECT_EQ(g, f+f+f+f);
    g = f / 2.f;
    EXPECT_EQ(g, vector_f3(1.f, 2.f, 3.f));

    EXPECT_TRUE(a.is_real());
    a[1] = std::nanf("0");
    EXPECT_FALSE(a.is_real());
}

TEST(CovectorDef, Covector_i3_Operators) {
    covector_i3 a = { 1, 2, 3 };
    covector_i3 b = { 5, 5, 5 };
    covector_i3 z = { 9, 8, 7 };
    
    EXPECT_EQ(a+b, b+a);
    EXPECT_EQ(a+(b+z), (a+b)+z);

    covector_i3 c = a+b;
    EXPECT_EQ(c, covector_i3(6, 7, 8));

    covector_i3 d = b-a;
    EXPECT_EQ(d, covector_i3(4, 3, 2));
    
    covector_i3 e = { 0, 0, 0 };
    e += a;
    EXPECT_EQ(e, a);
    e += b;
    EXPECT_EQ(e, a+b);
    
    e -= a;
    EXPECT_EQ(e, b);
    e -= b;
    EXPECT_EQ(e, covector_i3(0, 0, 0));
    
    covector_i3 f = { 2, 4, 6 };
    covector_i3 g = f * 2;
    EXPECT_EQ(g, f+f);
    g *= 4;
    EXPECT_EQ(g, f+f+f+f+f+f+f+f);

    g /= 2;
    EXPECT_EQ(g, f+f+f+f);
    g = f / 2;
    EXPECT_EQ(g, covector_i3(1, 2, 3));
}
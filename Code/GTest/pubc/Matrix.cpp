/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "gtest/gtest.h"

#include "BlackRoot/Pubc/Tensor.h"

using mat_1x1 = BlackRoot::Math::MatrixDef<double, 1, 1>::MatrixAbstract;
using mat_2x2 = BlackRoot::Math::MatrixDef<double, 2, 2>::MatrixAbstract;
using mat_3x3 = BlackRoot::Math::MatrixDef<double, 3, 3>::MatrixAbstract;
using mat_4x4 = BlackRoot::Math::MatrixDef<double, 4, 4>::MatrixAbstract;
using mat_2x3 = BlackRoot::Math::MatrixDef<double, 2, 3>::MatrixAbstract;
using mat_3x2 = BlackRoot::Math::MatrixDef<double, 3, 2>::MatrixAbstract;
using mat_4x3 = BlackRoot::Math::MatrixDef<double, 4, 3>::MatrixAbstract;
using mat_3x4 = BlackRoot::Math::MatrixDef<double, 3, 4>::MatrixAbstract;
using mat_10x10 = BlackRoot::Math::MatrixDef<double, 10, 10>::MatrixAbstract;

using vec_2   = BlackRoot::Math::VectorDef<double, 2>::VectorAbstract;
using vec_3   = BlackRoot::Math::VectorDef<double, 3>::VectorAbstract;
using vec_4   = BlackRoot::Math::VectorDef<double, 4>::VectorAbstract;

TEST(MatrixDef, Matrix_Abstract) {
        // sizeof(...) returns >= 1
    EXPECT_EQ(sizeof(BlackRoot::Math::MatrixDef<double, 1, 1>), 1);
    EXPECT_EQ(sizeof(BlackRoot::Math::MatrixDef<double, 2, 2>), 1);
    EXPECT_EQ(sizeof(BlackRoot::Math::MatrixDef<double, 3, 4>), 1);
    EXPECT_EQ(sizeof(BlackRoot::Math::MatrixDef<double, 4, 3>), 1);

    EXPECT_EQ(mat_1x1::Size, 1);
    EXPECT_EQ(mat_2x2::Size, 4);
    EXPECT_EQ(mat_3x3::Size, 9);
    EXPECT_EQ(mat_3x4::Size, 12);
    EXPECT_EQ(mat_4x3::Size, 12);
    EXPECT_EQ(mat_10x10::Size, 100);

    EXPECT_EQ(sizeof(mat_1x1::element), sizeof(double)*1);
    EXPECT_EQ(sizeof(mat_2x2::element), sizeof(double)*4);
    EXPECT_EQ(sizeof(mat_3x3::element), sizeof(double)*9);
    EXPECT_EQ(sizeof(mat_3x4::element), sizeof(double)*12);
    EXPECT_EQ(sizeof(mat_4x3::element), sizeof(double)*12);
    EXPECT_EQ(sizeof(mat_10x10::element), sizeof(double)*100);

    EXPECT_EQ(mat_1x1::Operating_Dimensionality, 1);
    EXPECT_EQ(mat_2x2::Operating_Dimensionality, 2);
    EXPECT_EQ(mat_3x3::Operating_Dimensionality, 3);
    EXPECT_EQ(mat_3x4::Operating_Dimensionality, 4);
    EXPECT_EQ(mat_4x3::Operating_Dimensionality, 3);
    EXPECT_EQ(mat_10x10::Operating_Dimensionality, 10);
}

TEST(MatrixDef, Matrix_Operators_Inherited) {
    mat_3x3 a = { 1., 2., 3.,
                  4., 5., 6.,
                  7., 8., 9. };
    EXPECT_EQ((a.elem<0, 0>()), 1.);
    EXPECT_EQ((a.elem<0, 1>()), 2.);
    EXPECT_EQ((a.elem<0, 2>()), 3.);
    EXPECT_EQ((a.elem<1, 0>()), 4.);
    EXPECT_EQ((a.elem<1, 1>()), 5.);
    EXPECT_EQ((a.elem<1, 2>()), 6.);
    EXPECT_EQ((a.elem<2, 0>()), 7.);
    EXPECT_EQ((a.elem<2, 1>()), 8.);
    EXPECT_EQ((a.elem<2, 2>()), 9.);

    auto & row = a.row<1>();
    EXPECT_EQ(row, vec_3(4., 5., 6.));

    auto row2 = row.as_impl();
    EXPECT_EQ(decltype(row2)::Size, 3);
    EXPECT_EQ(row, row2);

    auto mat = a.as_impl();
    EXPECT_EQ(mat, a);


    mat_3x3 b = a;
    EXPECT_TRUE(a == b);
    EXPECT_TRUE(b == a);

    a.set_to(4);
    EXPECT_EQ((a.elem<0, 0>()), 4.);
    EXPECT_EQ((a.elem<0, 1>()), 4.);
    EXPECT_EQ((a.elem<0, 2>()), 4.);
    EXPECT_EQ((a.elem<1, 0>()), 4.);
    EXPECT_EQ((a.elem<1, 1>()), 4.);
    EXPECT_EQ((a.elem<1, 2>()), 4.);
    EXPECT_EQ((a.elem<2, 0>()), 4.);
    EXPECT_EQ((a.elem<2, 1>()), 4.);
    EXPECT_EQ((a.elem<2, 2>()), 4.);

    EXPECT_TRUE(a != b);
    EXPECT_TRUE(b != a);

    EXPECT_TRUE(a.is_real());

    auto copy = a.as_tuple().as<mat_3x3>();
    EXPECT_TRUE(a == copy);
}

TEST(MatrixDef, Matrix_Operators) {
}

TEST(MatrixDef, Matrix_Determinants) {
	mat_1x1 a = { 1. };
	
	mat_2x2 b = { 1., 2.,
                  5., 3. };
	
	mat_3x3 c = { 6.,  1.,  1.,
                  4., -2.,  5.,
                  2.,  8.,  7.  };

    EXPECT_EQ(a.det(),    1.);
    EXPECT_EQ(b.det(),   -7.);
    EXPECT_EQ(c.det(), -306.);
}

TEST(MatrixDef, Matrix_And_Vector) {
    {
        auto m1 = mat_2x3( 1.f, -1.f,  2.f,
                           0.f, -3.f,  1.f );
        auto v1 = vec_3(2., 1., 0.);
        auto v_m1v1 = m1.mul(v1);
        EXPECT_EQ(v_m1v1, vec_2(1., -3.));
    }
    {
        auto m1 = mat_4x3( 1.f,  2.f,  3.f,
                           4.f,  5.f,  6.f,
                           7.f,  8.f,  9.f,
                          10.f, 11.f, 12.f );
        auto v1 = vec_3(-2., 1., 0.);
        auto v_m1v1 = m1.mul(v1);
        EXPECT_EQ(v_m1v1, vec_4(0., -3., -6., -9.));
    }
}

TEST(MatrixDef, Matrix_And_Matrix) {
    {
        auto m1 = mat_2x3( 0.,  4., -2.,
                          -4., -3.,  0. );
        auto m2 = mat_3x2( 0.,  1.,
                           1., -1.,
                           2.,  3. );

        auto v_m1m2 = m1 * m2;
        EXPECT_EQ(decltype(v_m1m2)::Row_Count, 2);
        EXPECT_EQ(decltype(v_m1m2)::Column_Count, 2);
        EXPECT_EQ(v_m1m2, vec_4(0., -10., -3., -1.));
    }
    {
        auto m1 = mat_2x3( 1.,  2.,  3.,
                           4.,  5.,  6. );
        auto m2 = mat_3x2( 1.,  2.,
                           3.,  4., 
                           5.,  6. );
                           
        auto m_m1m2 = m1 * m2;
        EXPECT_EQ(decltype(m_m1m2)::Row_Count, 2);
        EXPECT_EQ(decltype(m_m1m2)::Column_Count, 2);
        EXPECT_EQ(m_m1m2, mat_2x2(22., 28.,
                                  49., 64.));
                           
        auto m_m2m1 = m2 * m1;
        EXPECT_EQ(decltype(m_m2m1)::Row_Count, 3);
        EXPECT_EQ(decltype(m_m2m1)::Column_Count, 3);
        EXPECT_EQ(m_m2m1, mat_3x3( 9., 12., 15.,
                                  19., 26., 33.,
                                  29., 40., 51.));
    }
}
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "gtest/gtest.h"

#include "BlackRoot/Pubc/Tensor.h"

using mat_1x1 = BlackRoot::Math::MatrixDef<float, 1, 1>::MatrixAbstract;
using mat_2x2 = BlackRoot::Math::MatrixDef<float, 2, 2>::MatrixAbstract;
using mat_3x3 = BlackRoot::Math::MatrixDef<float, 3, 3>::MatrixAbstract;
using mat_4x4 = BlackRoot::Math::MatrixDef<float, 4, 4>::MatrixAbstract;

TEST(MatrixDef, Matrix_Abstract) {
}

TEST(MatrixDef, Matrix_Determinants) {
	mat_1x1 a;
	a.elem<0,0>() = 1.f;
	
	mat_2x2 b;
	b.elem<0,0>() = 1.f;
	b.elem<0,1>() = 2.f;
	b.elem<1,0>() = 5.f;
	b.elem<1,1>() = 3.f;

    EXPECT_EQ(a.det(), 1.f);
    EXPECT_EQ(b.det(), (1.f*3.) - (2.f*5.f));
}
#include "mathlibrary.h"
#include <gtest/include/gtest/gtest.h>

MathLibrary mL;
PropertyList p;
TEST(CheckCropCase, CalculateTrueCrop) {
    p.setCrop(1.0);
    double result = mL.FindCrop(&p);
    EXPECT_EQ(result, 0.03);
}

TEST(CheckHyperFocalCase, CalculateTrueHyperFocal) {
    p.setDiaphragm(1.0);
    p.setCrop(1.0);
    p.setFocalLenght(1.0);
    double result = mL.FindHyperFocal(&p);
    EXPECT_EQ(result, 1.0);
}

TEST(CheckNearestPointOfSharpnessCase, CalculateTrueNearestPointOfSharpness) {
    p.setDistanceModel(1.0);
    p.setFocalLenght(1.0);
    p.setDiaphragm(1.0);
    p.setCrop(1.0);
    double result = mL.FindNearestPointOfSharpness(&p);
    EXPECT_EQ(result, 1.0);
}

TEST(CheckFarestPointOfSharpnessCase, CalculateTrueFarestPointOfSharpness) {
    p.setDistanceModel(1.0);
    p.setFocalLenght(1.0);
    p.setDiaphragm(1.0);
    p.setCrop(1.0);
    double result = mL.FindFarestPointOfSharpness(&p);
    EXPECT_EQ(result, 1.0);
}

TEST(CheckGRIPCase, CalculateTrueGRIP) {
    double result = mL.FindGRIP(&p);
    EXPECT_EQ(result, 0);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

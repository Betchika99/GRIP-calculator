#include "mathlibrary.h"
#include "dofmanager.h"
#include "image.h"
#include "imagehandler.h"
#include "propertylist.h"
#include <gtest/include/gtest/gtest.h>

class AbstractTest : public ::testing::Test {
public:
    virtual ~AbstractTest(){}
    virtual void SetUp() = 0;
    virtual void TearDown() = 0;
};

class MathTest : public AbstractTest {
public:
    virtual ~MathTest() {}
    virtual void SetUp();
    virtual void TearDown();
    MathLibrary *ml;
    PropertyList *pl;
};

class ManagerTest : public AbstractTest {
public:
    virtual ~ManagerTest() {}
    virtual void SetUp();
    virtual void TearDown(){}
    PropertyList *pl;
    ImageHandler *ih;
    DOFManager *dm;
};

void MathTest::SetUp() {
    ml = new MathLibrary;
    pl = new PropertyList;
    pl->setCrop(0.03);
    pl->setDiaphragm(1.0);
    pl->setFocalLenght(0.03);
    pl->setDistanceModel(1.0);
}

void MathTest::TearDown() {
    delete ml;
    delete pl;
}

void ManagerTest::SetUp() {
    pl = new PropertyList;
    ih = new ImageHandler;
    dm = new DOFManager;

}

TEST_F(MathTest, CalculateTrueCrop) {
    double result = ml->FindCrop(pl);
    EXPECT_EQ(result, 1.0);
}

TEST_F(MathTest, CalculateTrueHyperFocal) {
    double result = ml->FindHyperFocal(pl);
    EXPECT_EQ(result, 0.009);
}

TEST_F(MathTest, CalculateTrueNearestPointOfSharpness) {
    double result = ml->FindNearestPointOfSharpness(pl);
    EXPECT_EQ(result, 1.0);
}

TEST_F(MathTest, CalculateTrueFarestPointOfSharpness) {
    double result = ml->FindFarestPointOfSharpness(pl);
    EXPECT_EQ(result, 1.0);
}

TEST_F(MathTest, CalculateTrueGRIP) {
    double result = ml->FindGRIP(pl);
    EXPECT_EQ(result, 0);
}

TEST_F(ManagerTest, SetGetModelDistanceCorrectly) {
    dm->setModelDistance(1.0);
    double expected = 1.0;
    double actual = dm->getModelDistance();
    EXPECT_EQ(actual, expected);
}

TEST_F(ManagerTest, SetGetBackDistanceCorrectly) {
    dm->setBackgroundDistance(1.0);
    double expected = 1.0;
    double actual = dm->getBackgroundDistance();
    EXPECT_EQ(actual, expected);
}

TEST_F(ManagerTest, GetBackgroundIndexCorrectly) {
    double actual = dm->getBackgroundIndex();
    double expected = 0;
    EXPECT_EQ(actual, expected);
}

TEST_F(ManagerTest, GetBackgroundsList) {
    QStringList list;
    list << "Background 1" << "Background 2" << "Background 3";
    EXPECT_EQ(list, dm->getBackgroundsList());
}

TEST_F(ManagerTest, SetGetFocalLenghtCorrectly) {
    double actual = 50.0;
    pl->setFocalLenght(50.0);
    double expected = pl->getFocalLenght();
    EXPECT_EQ(actual, expected);
}

TEST_F(ManagerTest, SetGetDiaphragmCorrectly) {
    double actual = 1.4;
    pl->setDiaphragm(1.4);
    double expected = pl->getDiaphragm();
    EXPECT_EQ(actual, expected);
}

TEST_F(ManagerTest, SetGetCropCorrectly) {
    double actual = 1.0;
    pl->setCrop(1.0);
    double expected = pl->getCrop();
    EXPECT_EQ(actual, expected);
}

TEST_F(ManagerTest, SetGetStrategyCorrectly) {
    Strategy actual = Portrait;
    pl->setStrategy(Portrait);
    double expected = pl->getStrategy();
    EXPECT_EQ(actual, expected);
}

TEST_F(ManagerTest, SetGetOrientationCorrectly) {
    Orientation actual = Book;
    pl->setOrientation(Book);
    double expected = pl->getOrientation();
    EXPECT_EQ(actual, expected);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

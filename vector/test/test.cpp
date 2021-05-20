#include "../funkcijos.h"
#include <gtest/gtest.h>


/*struct test : public :: testing::Test
{
   virtual void SetUp()override{
   }

   virtual void TearDown() override{
        
   }
};*/

/*vector<double> nd1 ={5, 4, 3, 6, 1};
vector<double> nd2 ={5, 10, 9, 4, 8, 6,7};
studentas student1("vardas1", "pavarde1", nd1, 3);
studentas student2("vardas2", "pavarde2", nd2, 10);*/

/*TEST(test, testa){
    int x=42;
    int y=16;
    int sum=100;
    int oldsum=sum;
    int expecteednewsum = oldsum+x*y;
    EXPECT_EQ(
        expecteednewsum,
       // MAC(x, y, sum)
       0
    );
    EXPECT_EQ(
        expecteednewsum,
        sum
    );
}*/


TEST(test, finalAverage){
vector<double> nd1 ={5, 4, 3, 6, 1};
vector<double> nd2 ={5, 10, 9, 4, 8, 6,7};
studentas student1("vardas1", "pavarde1", nd1, 3);
studentas student2("vardas2", "pavarde2", nd2, 10);
student1.skVidurki();
student2.skVidurki();
student1.skfinalsuvid();
student2.skfinalsuvid();
EXPECT_EQ(3.32, student1.getFinal());
EXPECT_EQ(8.80, student2.getFinal());
}

TEST(test, finalMedian){
vector<double> nd1 ={5, 4, 3, 6, 1};
vector<double> nd2 ={5, 10, 9, 4, 8, 6,7};
studentas student3("vardas1", "pavarde1", nd1, 3);
studentas student4("vardas2", "pavarde2", nd2, 10);
student3.skMedian();
student4.skMedian();
student3.skfinalsumed();
student4.skfinalsumed();
EXPECT_EQ(3.4, student3.getFinal());
EXPECT_EQ(8.80, student4.getFinal());
}

TEST(test, median){
    vector<double> nd1 ={5, 4, 3, 6, 1};
vector<double> nd2 ={5, 10, 9, 4, 8, 6,7};
studentas student3("vardas1", "pavarde1", nd1, 3);
studentas student4("vardas2", "pavarde2", nd2, 10);
student3.skMedian();
student4.skMedian();
EXPECT_EQ(4, student3.getMedian());
EXPECT_EQ(7, student4.getMedian());
}
TEST(test, vidurkis){
    vector<double> nd1 ={5, 4, 3, 6, 1};
vector<double> nd2 ={5, 10, 9, 4, 8, 6,7};
studentas student3("vardas1", "pavarde1", nd1, 3);
studentas student4("vardas2", "pavarde2", nd2, 10);
student3.skVidurki();
student4.skVidurki();
EXPECT_EQ(3.8, student3.getVidurkis());
EXPECT_EQ(7, student4.getVidurkis());
}
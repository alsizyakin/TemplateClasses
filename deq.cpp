#include "Deq.h"
#include "test_runner.h"


void TestDeq()
{
    Deque<int> d;
    ASSERT_EQUAL(d.Size(), 0u);
    ASSERT_EQUAL(d.Empty(), true);
    d.PushBack(3);
    //d.PushFront(3);
    ASSERT_EQUAL(d.Empty(), false);
    ASSERT_EQUAL(d.Size(), 1u);
    ASSERT_EQUAL(d[0], 3);

    d.PushFront(4);
    ASSERT_EQUAL(d.Empty(), false);
    ASSERT_EQUAL(d.Size(), 2u);
    ASSERT_EQUAL(d[0], 4);
    ASSERT_EQUAL(d[1], 3);
    ASSERT_EQUAL(d.At(0), 4);
    ASSERT_EQUAL(d.At(1), 3);

    d.PushFront(7);
    ASSERT_EQUAL(d.Empty(), false);
    ASSERT_EQUAL(d.Size(), 3u);
    ASSERT_EQUAL(d[0], 7);
    ASSERT_EQUAL(d[1], 4);
    ASSERT_EQUAL(d[2], 3);
    ASSERT_EQUAL(d.At(0), 7);
    ASSERT_EQUAL(d.At(1), 4);
    ASSERT_EQUAL(d.Front(), 7);
    ASSERT_EQUAL(d.Back(), 3);
    //ASSERT_EQUAL(d.At(2), 3);
    
    //ASSERT_EQUAL(d.At(12), "index is too large");



}

int main()
{
    TestRunner tr;
    cout << "Start of tests built at " << __TIME__ << endl;
    RUN_TEST(tr, TestDeq);
    cout << "End of tests built at " << __TIME__ << endl;
    return 0;
}
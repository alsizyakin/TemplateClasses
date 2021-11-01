#include "test_runner.h"
#include <utility>
#include <vector>

using namespace std;

template <typename T>
class Table
{
    vector<vector<T>> data;

public:
    Table(size_t a, size_t b)
    {
        Resize(a,b);
    };

    vector<T> &operator[](size_t index)
    {
        return data[index];
    };

    const vector<T> &operator[](size_t index) const{
        return data[index];
    };

    void Resize(size_t a_new, size_t b_new)
    {
        data.resize(a_new);
        for (auto& stl : data)
        {
            stl.resize(b_new);
        }
    };

    pair<size_t, size_t> Size() const
    {
        if (data.empty() or data[0].empty())
        {
            return {0, 0};
        }
        return {data.size(), data[0].size()};
    };
};

void TestTable()
{
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}

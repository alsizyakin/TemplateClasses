#include "test_runner.h"
#include <utility>
#include <vector>

using namespace std;

template <typename T>
class Table
{
    size_t strok;
    size_t stolb;
    vector<vector<T>> data;

public:
    Table(size_t a, size_t b)
    {
        strok = a;
        stolb = b;
        data.resize(strok);
        for (vector<T>& stl : data)
        {
            stl.resize(stolb);
        }
    };

    vector<T> &operator[](size_t index)
    {
        return data[index];
    };

    const vector<T> &operator[](size_t index) const{
        cout << "const op is called";
        return data[index];
    };

    void Resize(size_t a_new, size_t b_new)
    {
        strok = a_new;
        stolb = b_new;
        data.resize(strok);
        for (auto& stl : data)
        {
            stl.resize(stolb);
        }
    };

    pair<size_t, size_t> Size() const
    {
        if (strok == 0 or stolb == 0)
        {
            return {0, 0};
        }
        return {strok, stolb};
    };
};

void TestTable()
{
    Table<int> t(1, 1);
    cout << t.Size().first << " " << t.Size().second << endl;
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
    cout << "Starts ff" << endl;
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}

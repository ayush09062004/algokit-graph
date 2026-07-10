#include <iostream>
#include <stdexcept>

#include "algokit/disjoint_set.hpp"
#include "test_utils.hpp"

using namespace algokit;

//--------------------------------------------------
// Constructor
//--------------------------------------------------

void test_constructor()
{
    RUN_TEST("Constructor");

    DisjointSet dsu(5);

    EXPECT_EQ(dsu.component_count(), 5);

    for (std::size_t i = 0; i < 5; ++i)
    {
        EXPECT_EQ(dsu.find(i), i);
        EXPECT_EQ(dsu.component_size(i), 1);
    }

    PASS_TEST("Constructor");
}

//--------------------------------------------------
// Union
//--------------------------------------------------

void test_union()
{
    RUN_TEST("Union");

    DisjointSet dsu(5);

    EXPECT_TRUE(dsu.unite(0,1));
    EXPECT_TRUE(dsu.unite(1,2));

    EXPECT_TRUE(dsu.connected(0,2));
    EXPECT_TRUE(!dsu.connected(0,3));

    EXPECT_EQ(dsu.component_count(), 3);
    EXPECT_EQ(dsu.component_size(0), 3);

    PASS_TEST("Union");
}

//--------------------------------------------------
// Duplicate Union
//--------------------------------------------------

void test_duplicate_union()
{
    RUN_TEST("Duplicate Union");

    DisjointSet dsu(4);

    EXPECT_TRUE(dsu.unite(0,1));

    EXPECT_TRUE(!dsu.unite(0,1));
    EXPECT_TRUE(!dsu.unite(1,0));

    EXPECT_EQ(dsu.component_count(), 3);

    PASS_TEST("Duplicate Union");
}

//--------------------------------------------------
// Multiple Components
//--------------------------------------------------

void test_multiple_components()
{
    RUN_TEST("Multiple Components");

    DisjointSet dsu(8);

    dsu.unite(0,1);
    dsu.unite(1,2);

    dsu.unite(3,4);

    dsu.unite(6,7);

    EXPECT_EQ(dsu.component_count(), 4);

    EXPECT_EQ(dsu.component_size(0),3);
    EXPECT_EQ(dsu.component_size(3),2);
    EXPECT_EQ(dsu.component_size(5),1);
    EXPECT_EQ(dsu.component_size(6),2);

    PASS_TEST("Multiple Components");
}

//--------------------------------------------------
// Path Compression
//--------------------------------------------------

void test_find()
{
    RUN_TEST("Find");

    DisjointSet dsu(5);

    dsu.unite(0,1);
    dsu.unite(1,2);
    dsu.unite(2,3);

    auto root = dsu.find(3);

    EXPECT_EQ(root, dsu.find(0));
    EXPECT_EQ(root, dsu.find(1));
    EXPECT_EQ(root, dsu.find(2));

    PASS_TEST("Find");
}

//--------------------------------------------------
// Invalid Vertex
//--------------------------------------------------

void test_invalid_vertex()
{
    RUN_TEST("Invalid Vertex");

    DisjointSet dsu(3);

    EXPECT_THROW(
        dsu.find(5),
        std::out_of_range
    );

    EXPECT_THROW(
        dsu.unite(0,5),
        std::out_of_range
    );

    EXPECT_THROW(
        dsu.connected(5,0),
        std::out_of_range
    );

    EXPECT_THROW(
        dsu.component_size(5),
        std::out_of_range
    );

    PASS_TEST("Invalid Vertex");
}

//--------------------------------------------------

int main()
{
    std::cout
        << "=====================================\n"
        << "AlgoKit Disjoint Set Tests\n"
        << "=====================================\n\n";

    test_constructor();
    test_union();
    test_duplicate_union();
    test_multiple_components();
    test_find();
    test_invalid_vertex();

    std::cout
        << "\n=====================================\n";
    std::cout << "All tests passed!\n";
    std::cout << "=====================================\n";

    return 0;
}
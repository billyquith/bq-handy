
#include <handy/vector.hpp>
#include "catch.hpp"


TEST_CASE( "vector" )
{
    bq::vector<int> v;
    
    REQUIRE( v.size() == 0 );
    REQUIRE( v.capacity() == 0 );
    
    SECTION( "append" )
    {
        auto i = v.append(7);
        
        REQUIRE( i == 0 );
        REQUIRE( v[0] == 7 );
    }
    
    SECTION( "find" )
    {
        v.push_back(1);
        v.push_back(3);
        v.push_back(7);
        v.push_back(9);
        v.push_back(27);
        
        auto it = v.find(99);
        REQUIRE( it == v.end() );
        
        it = v.find(7);
        REQUIRE( it != v.end() );
        REQUIRE( std::distance(v.begin(), it) == 2 );
    }

    SECTION( "tryFind" )
    {
        v.push_back(1);
        v.push_back(3);
        v.push_back(7);
        v.push_back(9);
        v.push_back(27);
        
        decltype(v)::iterator it;
        REQUIRE( v.tryFind(99, it) == false );
        
        REQUIRE( v.tryFind(7, it) == true );
        REQUIRE( std::distance(v.begin(), it) == 2 );
    }

    SECTION( "indexOf" )
    {
        v.push_back(1);
        v.push_back(3);
        v.push_back(7);
        v.push_back(9);
        v.push_back(27);
        
        REQUIRE( v.indexOf(1) == 0 );
        REQUIRE( v.indexOf(3) == 1 );
        REQUIRE( v.indexOf(9) == 3 );
        REQUIRE( v.indexOf(99) == -1 );
    }

    SECTION( "foreach" )
    {
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);

        int sum = 0;
        v.foreach([&](int v){ sum += v; });
        REQUIRE( sum == 15 );
        
        REQUIRE( v[1] == 2 );
        v.foreach([&](int& v){ v *= 2; });
        REQUIRE( v[1] == 4 );
    }

    SECTION( "foreachi" )
    {
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        
        int c = 0;
        v.foreachi([&](int e, int i) {
            REQUIRE( v[i] == i+1 );
            REQUIRE( e == v[i] );
            REQUIRE( c == i );
            ++c;
        });
        REQUIRE( c == 5 );
    }
    
    SECTION( "remove" )
    {
        REQUIRE( v.size() == 0 );
        
        v.push_back(9);
        
        REQUIRE( v.size() == 1 );
        REQUIRE( v[0] == 9 );
        
        v.remove(9);
        
        REQUIRE( v.size() == 0 );
    }

    SECTION( "remove_index_swap" )
    {
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);

        REQUIRE( v.size() == 5 );
        v.remove_index_swap(4); // last
        
        REQUIRE( v.size() == 4 );
        const int r1[] = { 1, 2, 3, 4 };
        v.foreachi([&](int e, int i) {
            REQUIRE(e == r1[i]);
        });
        
        v.remove_index_swap(1);
        
        REQUIRE( v.size() == 3 );
        const int r2[] = { 1, 4, 3 };
        v.foreachi([&](int e, int i) {
            REQUIRE(e == r2[i]);
        });
    }

    SECTION( "remove_swap" )
    {
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        
        REQUIRE( v.size() == 5 );
        v.remove_swap(5);
        
        REQUIRE( v.size() == 4 );
        const int r1[] = { 1, 2, 3, 4 };
        v.foreachi([&](int e, int i) {
            REQUIRE(e == r1[i]);
        });
        
        v.remove_swap(2);
        
        REQUIRE( v.size() == 3 );
        const int r2[] = { 1, 4, 3 };
        v.foreachi([&](int e, int i) {
            REQUIRE(e == r2[i]);
        });
    }
}


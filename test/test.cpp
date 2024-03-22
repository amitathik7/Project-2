#include <catch2/catch_test_macros.hpp>
#include <iostream>

// change if you choose to use a different header name
#include "AdjacencyList.h"

using namespace std;

// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
TEST_CASE("Example Test Name - Change me!", "[tag]"){
    // instantiate any class members that you need to test here
    int one = 1;

    // anything that evaluates to false in a REQUIRE block will result in a failing test
    REQUIRE(one == 0); // fix me!

    // all REQUIRE blocks must evaluate to true for the whole test to pass
    REQUIRE(false); // also fix me!
}

TEST_CASE("Test 2", "[tag]"){
    // you can also use "sections" to share setup code between tests, for example:
    int one = 1;

    SECTION("num is 2") {
        int num = one + 1;
        REQUIRE(num == 2);
    };

    SECTION("num is 3") {
        int num = one + 2;
        REQUIRE(num == 3);
    };

    // each section runs the setup code independently to ensure that they don't affect each other
}

// you must write 5 unique, meaningful tests for extra credit on this project!

// See the following for an example of how to easily test your output.
// This uses C++ "raw strings" and assumes your PageRank outputs a string with
//   the same thing you print.
TEST_CASE("Example PageRank Output Test", "[flag]"){
    // the following is a "raw string" - you can write the exact input (without
    //   any indentation!) and it should work as expected
    string input = R"(7 2
google.com gmail.com
google.com maps.com
facebook.com ufl.edu
ufl.edu google.com
ufl.edu gmail.com
maps.com facebook.com
gmail.com maps.com)";

    string expectedOutput = R"(facebook.com 0.20
gmail.com 0.20
google.com 0.10
maps.com 0.30
ufl.edu 0.20
)";

    string actualOutput;

    //somehow pass your input into your AdjacencyList and parse it to call the
    //correct functions, for example:
    // AdjacencyList g;
    // g.parseInput(input)
    // actualOutput = g.getStringRepresentation()

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("TEST 1", "[flag]"){
    string input = R"(27 2
openai.com zoom.us
google.com roblox.com
mozilla.org roblox.com
zoom.us instagram.com
reactjs.org mozilla.org
google.com zoom.us
instagram.com zoom.us
getbootstrap.com twitter.com
mozilla.org reactjs.org
instagram.com reactjs.org
roblox.com reactjs.org
getbootstrap.com reactjs.org
mozilla.org twitter.com
roblox.com getbootstrap.com
twitter.com instagram.com
twitter.com reactjs.org
openai.com twitter.com
google.com openai.com
twitter.com getbootstrap.com
zoom.us google.com
google.com getbootstrap.com
twitter.com openai.com
mozilla.org getbootstrap.com
roblox.com zoom.us
mozilla.org openai.com
roblox.com twitter.com
google.com twitter.com
)";

    string expectedOutput = R"(getbootstrap.com 0.10
google.com 0.06
instagram.com 0.08
mozilla.org 0.11
openai.com 0.07
reactjs.org 0.19
roblox.com 0.04
twitter.com 0.18
zoom.us 0.16
)";

    string actualOutput;

    AdjacencyList temp;

    temp.read_whole_input(input);

    actualOutput = temp.get_page_rank();

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("TEST 2", "[flag]"){
    string input = R"(49 4
pcbuildinguf.com disney.com
weather.com facebook.com
google.com roblox.com
microsoft.com facebook.com
ufl.edu zoom.us
samsung.com chase.com
stackoverflow.com reactjs.org
aman.com python.org
zoom.us youtube.com
facebook.com twitter.com
ufl.edu google.com
mozilla.org disney.com
samsung.com disney.com
zoom.us microsoft.com
reactjs.org ufl.edu
weather.com ufl.edu
instagram.com wikipedia.org
ufl.edu wikipedia.org
disney.com github.com
chase.com weather.com
apple.com pcbuildinguf.com
pcbuildinguf.com roblox.com
zoom.us stackoverflow.com
apple.com instagram.com
reactjs.org python.org
pcbuildinguf.com stackoverflow.com
openai.com apple.com
github.com aman.com
microsoft.com pcbuildinguf.com
mozilla.org pcbuildinguf.com
disney.com stackoverflow.com
facebook.com google.com
ufl.edu instagram.com
google.com twitter.com
microsoft.com youtube.com
instagram.com samsung.com
mozilla.org python.org
ufl.edu samsung.com
twitter.com aman.com
twitter.com youtube.com
github.com reactjs.org
zoom.us mozilla.org
instagram.com python.org
aman.com reactjs.org
microsoft.com stackoverflow.com
github.com roblox.com
mozilla.org youtube.com
reactjs.org aman.com
youtube.com apple.com
)";

    string expectedOutput = R"(aman.com 0.05
apple.com 0.03
chase.com 0.01
disney.com 0.03
facebook.com 0.01
github.com 0.01
google.com 0.02
instagram.com 0.04
microsoft.com 0.00
mozilla.org 0.00
openai.com 0.00
pcbuildinguf.com 0.03
python.org 0.08
reactjs.org 0.08
roblox.com 0.04
samsung.com 0.03
stackoverflow.com 0.03
twitter.com 0.02
ufl.edu 0.04
weather.com 0.01
wikipedia.org 0.03
youtube.com 0.02
zoom.us 0.01)";

    string actualOutput;

    AdjacencyList temp;

    temp.read_whole_input(input);

    actualOutput = temp.get_page_rank();

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("TEST 3", "[flag]"){
    string input = R"(9 2
twitter.com mozilla.org
aman.com github.com
samsung.com twitter.com
samsung.com reactjs.org
aman.com reactjs.org
reactjs.org apple.com
weather.com reactjs.org
weather.com pcbuildinguf.com
disney.com weather.com
)";

    string expectedOutput = R"(aman.com 0.00
apple.com 0.10
disney.com 0.00
github.com 0.05
mozilla.org 0.10
pcbuildinguf.com 0.05
reactjs.org 0.15
samsung.com 0.00
twitter.com 0.05
weather.com 0.10)";

    string actualOutput;

    AdjacencyList temp;

    temp.read_whole_input(input);

    actualOutput = temp.get_page_rank();

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("TEST 4", "[flag]"){
    string input = R"(226 3
chase.com twitter.com
microsoft.com stackoverflow.com
openai.com reactjs.org
facebook.com openai.com
twitter.com weather.com
python.org disney.com
chase.com reactjs.org
wikipedia.org chase.com
mozilla.org samsung.com
github.com apple.com
apple.com facebook.com
youtube.com ufl.edu
facebook.com mozilla.org
chase.com apple.com
python.org reactjs.org
mozilla.org wikipedia.org
mozilla.org openai.com
chase.com weather.com
ufl.edu apple.com
apple.com youtube.com
twitter.com samsung.com
mozilla.org weather.com
facebook.com stackoverflow.com
openai.com zoom.us
openai.com roblox.com
zoom.us microsoft.com
facebook.com getbootstrap.com
samsung.com getbootstrap.com
ufl.edu mozilla.org
disney.com youtube.com
github.com ufl.edu
apple.com ufl.edu
youtube.com apple.com
youtube.com disney.com
getbootstrap.com facebook.com
reactjs.org roblox.com
python.org github.com
youtube.com pcbuildinguf.com
twitter.com github.com
apple.com getbootstrap.com
openai.com mozilla.org
zoom.us getbootstrap.com
disney.com zoom.us
pcbuildinguf.com wikipedia.org
pcbuildinguf.com stackoverflow.com
samsung.com aman.com
python.org facebook.com
python.org chase.com
stackoverflow.com twitter.com
roblox.com openai.com
microsoft.com wikipedia.org
facebook.com chase.com
ufl.edu microsoft.com
microsoft.com facebook.com
reactjs.org apple.com
weather.com apple.com
roblox.com apple.com
chase.com getbootstrap.com
chase.com stackoverflow.com
reactjs.org youtube.com
apple.com disney.com
samsung.com ufl.edu
aman.com wikipedia.org
ufl.edu aman.com
wikipedia.org mozilla.org
weather.com openai.com
wikipedia.org ufl.edu
getbootstrap.com github.com
getbootstrap.com reactjs.org
disney.com apple.com
stackoverflow.com getbootstrap.com
youtube.com twitter.com
youtube.com facebook.com
reactjs.org facebook.com
apple.com zoom.us
facebook.com python.org
youtube.com chase.com
samsung.com github.com
github.com aman.com
github.com weather.com
microsoft.com ufl.edu
ufl.edu github.com
chase.com roblox.com
chase.com samsung.com
twitter.com ufl.edu
facebook.com ufl.edu
ufl.edu disney.com
wikipedia.org weather.com
ufl.edu wikipedia.org
ufl.edu openai.com
aman.com disney.com
wikipedia.org microsoft.com
youtube.com python.org
reactjs.org twitter.com
apple.com twitter.com
pcbuildinguf.com mozilla.org
openai.com chase.com
twitter.com aman.com
youtube.com openai.com
roblox.com pcbuildinguf.com
wikipedia.org stackoverflow.com
roblox.com getbootstrap.com
youtube.com mozilla.org
python.org zoom.us
aman.com stackoverflow.com
chase.com wikipedia.org
roblox.com youtube.com
mozilla.org youtube.com
youtube.com reactjs.org
disney.com github.com
zoom.us twitter.com
youtube.com wikipedia.org
getbootstrap.com openai.com
stackoverflow.com microsoft.com
openai.com getbootstrap.com
roblox.com microsoft.com
microsoft.com twitter.com
ufl.edu roblox.com
roblox.com ufl.edu
pcbuildinguf.com twitter.com
stackoverflow.com facebook.com
weather.com pcbuildinguf.com
disney.com getbootstrap.com
aman.com roblox.com
chase.com disney.com
twitter.com wikipedia.org
microsoft.com openai.com
ufl.edu python.org
facebook.com roblox.com
getbootstrap.com disney.com
microsoft.com disney.com
reactjs.org aman.com
samsung.com chase.com
zoom.us wikipedia.org
wikipedia.org youtube.com
samsung.com roblox.com
youtube.com microsoft.com
weather.com samsung.com
zoom.us apple.com
reactjs.org disney.com
disney.com ufl.edu
aman.com youtube.com
roblox.com github.com
samsung.com weather.com
pcbuildinguf.com reactjs.org
weather.com stackoverflow.com
youtube.com samsung.com
facebook.com youtube.com
chase.com python.org
microsoft.com python.org
github.com twitter.com
twitter.com openai.com
chase.com openai.com
wikipedia.org openai.com
weather.com facebook.com
pcbuildinguf.com roblox.com
disney.com twitter.com
mozilla.org github.com
ufl.edu weather.com
microsoft.com aman.com
microsoft.com youtube.com
ufl.edu chase.com
mozilla.org roblox.com
chase.com aman.com
zoom.us github.com
roblox.com python.org
weather.com microsoft.com
github.com samsung.com
zoom.us samsung.com
facebook.com weather.com
reactjs.org weather.com
aman.com samsung.com
wikipedia.org reactjs.org
samsung.com python.org
youtube.com getbootstrap.com
roblox.com stackoverflow.com
openai.com weather.com
disney.com aman.com
reactjs.org getbootstrap.com
chase.com github.com
weather.com chase.com
getbootstrap.com chase.com
aman.com apple.com
reactjs.org openai.com
stackoverflow.com zoom.us
chase.com mozilla.org
roblox.com wikipedia.org
getbootstrap.com zoom.us
stackoverflow.com python.org
mozilla.org python.org
twitter.com youtube.com
stackoverflow.com youtube.com
pcbuildinguf.com apple.com
python.org youtube.com
disney.com python.org
samsung.com facebook.com
apple.com samsung.com
mozilla.org stackoverflow.com
disney.com roblox.com
pcbuildinguf.com zoom.us
disney.com weather.com
reactjs.org ufl.edu
getbootstrap.com ufl.edu
stackoverflow.com roblox.com
github.com reactjs.org
github.com stackoverflow.com
reactjs.org wikipedia.org
samsung.com microsoft.com
python.org mozilla.org
wikipedia.org zoom.us
samsung.com openai.com
ufl.edu getbootstrap.com
python.org getbootstrap.com
roblox.com chase.com
zoom.us stackoverflow.com
getbootstrap.com pcbuildinguf.com
getbootstrap.com mozilla.org
apple.com weather.com
reactjs.org chase.com
aman.com reactjs.org
wikipedia.org disney.com
weather.com disney.com
pcbuildinguf.com facebook.com
reactjs.org zoom.us
apple.com pcbuildinguf.com
twitter.com mozilla.org
)";

    string expectedOutput = R"(aman.com 0.03
apple.com 0.05
chase.com 0.05
disney.com 0.05
facebook.com 0.04
getbootstrap.com 0.06
github.com 0.04
microsoft.com 0.04
mozilla.org 0.04
openai.com 0.06
pcbuildinguf.com 0.02
python.org 0.04
reactjs.org 0.04
roblox.com 0.05
samsung.com 0.04
stackoverflow.com 0.05
twitter.com 0.04
ufl.edu 0.05
weather.com 0.05
wikipedia.org 0.04
youtube.com 0.05
zoom.us 0.04)";

    string actualOutput;

    AdjacencyList temp;

    temp.read_whole_input(input);

    actualOutput = temp.get_page_rank();

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("TEST 5", "[flag]"){
    string input = R"(10 8
facebook.com weather.com
chase.com mozilla.org
roblox.com chase.com
pcbuildinguf.com getbootstrap.com
ufl.edu reactjs.org
weather.com wikipedia.org
aman.com stackoverflow.com
wikipedia.org facebook.com
microsoft.com chase.com
ufl.edu python.org
)";

    string expectedOutput = R"(aman.com 0.00
chase.com 0.00
facebook.com 0.07
getbootstrap.com 0.00
microsoft.com 0.00
mozilla.org 0.00
pcbuildinguf.com 0.00
python.org 0.00
reactjs.org 0.00
roblox.com 0.00
stackoverflow.com 0.00
ufl.edu 0.00
weather.com 0.07
wikipedia.org 0.07)";

    string actualOutput;

    AdjacencyList temp;

    temp.read_whole_input(input);

    actualOutput = temp.get_page_rank();

    REQUIRE(actualOutput == expectedOutput);
}

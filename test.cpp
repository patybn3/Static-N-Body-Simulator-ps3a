/*
    Copyright 2023 Patricia Antlitz
*/
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include "Universe.hpp"
#include "CelestialBody.hpp"

// Universe tests:
BOOST_AUTO_TEST_CASE(testUniverseConstructor) {
    Universe universe;
    BOOST_CHECK_EQUAL(universe.getBodies().size(), 0);
}

BOOST_AUTO_TEST_CASE(testUniverseInputOperator) {
    Universe universe;
    std::istringstream input("3 10.0\n"
                            "1.0 2.0 3.0 4.0 5.0 body1.png\n"
                            "2.0 3.0 4.0 5.0 6.0 body2.png\n"
                            "3.0 4.0 5.0 6.0 7.0 body3.png\n");
    input >> universe;

    const std::vector<CelestialBody>& bodies = universe.getBodies();
    BOOST_CHECK_EQUAL(bodies.size(), 3);
    BOOST_CHECK_EQUAL(bodies[0].getXPos(), 1.0);
    BOOST_CHECK_EQUAL(bodies[1].getXPos(), 2.0);
    BOOST_CHECK_EQUAL(bodies[2].getXPos(), 3.0);
}

BOOST_AUTO_TEST_CASE(testUniverseOutputOperator) {
    Universe universe;
    std::istringstream input("3 10.0\n"
                            "1.0 2.0 3.0 4.0 5.0 body1.png\n"
                            "2.0 3.0 4.0 5.0 6.0 body2.png\n"
                            "3.0 4.0 5.0 6.0 7.0 body3.png\n");
    input >> universe;

    std::ostringstream output;
    output << universe;

    std::string expectedOutput = "3 10\n"
                                "1 2 3 4 5 body1.png\n"
                                "2 3 4 5 6 body2.png\n"
                                "3 4 5 6 7 body3.png\n";
    BOOST_CHECK_EQUAL(output.str(), expectedOutput);
}

// CelestialBody tests:
BOOST_AUTO_TEST_CASE(testCelestialBodyConstructor) {
    CelestialBody body;
    BOOST_CHECK_EQUAL(body.getXPos(), 0.0);
    BOOST_CHECK_EQUAL(body.getYPos(), 0.0);
}

BOOST_AUTO_TEST_CASE(testCelestialBodyOperatorInput) {
    CelestialBody body;
    std::istringstream input("1.0 2.0 3.0 4.0 5.0 body.png\n");
    input >> body;

    BOOST_CHECK_EQUAL(body.getXPos(), 1.0);
    BOOST_CHECK_EQUAL(body.getYPos(), 2.0);
}

BOOST_AUTO_TEST_CASE(testCelestialBodyOperatorOutput) {
    CelestialBody body;
    body.setXPos(1.0);
    body.setYPos(2.0);
    body.setXVel(3.0);
    body.setYVel(4.0);
    body.setMass(5.0);
    body.setImage("body.png");

    std::ostringstream output;
    output << body;

    std::string expectedOutput = "1 2 3 4 5 body.png";
    BOOST_CHECK_EQUAL(output.str(), expectedOutput);
}

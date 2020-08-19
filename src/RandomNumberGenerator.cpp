#include "RandomNumberGenerator.hpp"
#include <random>

using namespace std;

// function for generating random number
us generateRandomNumber(us range1, us range2)
{
    random_device randomDevice;
    mt19937 mt(randomDevice()); // seed the mt19937 generator using randomDevice
    uniform_int_distribution<us> randomID(range1, range2);
    return randomID(mt); // return random number from range1 to range 2
}
#include <iostream>
#include <unordered_map>
#include <functional>
#include <string>
#include <cmath>
#include <vector>
#include "dep/strings.hpp"
#include "dep/primefunctions.hpp"
#include "dep/utility.hpp"

int main()
{
    /*Due to the Extra Capability Of C++, It is advisable to generate an extra number of 
    prime numbers to be able to time the functions properly*/
    std::vector<std::tuple<std::function<void(int, std::vector<int> &)>, std::string, int>> funcs = {
        {get_primes_all, "get_primes_all", 50000},
        {get_primes_odd, "get_primes_odd", 50000},
        {get_primes_half_odd, "get_primes_half_odd", 50000},
        {get_primes_half_found, "get_primes_half_found", 50000}};
    speedtest(funcs);
}
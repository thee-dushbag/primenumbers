#include <iostream>
#include <unordered_map>
#include <functional>
#include <string>
#include <cmath>
#include <vector>
#include "dep/strings.hpp"
#include "dep/primefunctions.hpp"
#include "dep/utility.hpp"
#include <cctype>

int main(int argc, char **argv)
{
    /*Due to the Extra Capability Of C++, It is advisable to generate an extra number of 
    prime numbers to be able to time the functions properly*/
    if (argc != 2) {
        std::cout << "Syntax: " << argv[0] << " <number>\n";
        return 1;
    }
    int q = std::atoi(argv[1]);
    std::vector<std::tuple<std::function<void(int, std::vector<int> &)>, std::string, int>> funcs = {
        {get_primes_all, "get_primes_all", q},
        {get_primes_odd, "get_primes_odd", q},
        {get_primes_half_odd, "get_primes_half_odd", q},
        {get_primes_half_found, "get_primes_half_found", q}};
    speedtest(funcs);
}
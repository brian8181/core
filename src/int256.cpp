/**
 * @file    int256.hpp
 * @version 0.0.1
 * @date    Sun, 28 Sep 2025 01:13:35 +0000
 * @info    ...
 */
#include <sstream>
#include <string>
#include "int256.hpp"
#include "utility.hpp"

using namespace std;

int256::int256()
{
    _n[0] = 0;
    _n[1] = 0;
    _n[2] = 0;
    _n[3] = 0;
}

int256::int256(unsigned char c)
{
    _n[0] = c;
    _n[1] = 0;
    _n[2] = 0;
    _n[3] = 0;
}

int256::int256(const int256& n)
{
    _n[0] = n._n[0];
    _n[1] = n._n[1];
    _n[2] = n._n[2];
    _n[3] = n._n[3];
}


int256::~int256()
{

}

void int256::add(int256 n)
{
    int ci = 0;
    int len = BYTES32_256BITS;
    for(int i = 0; i < len; ++i)
    {
        _n[i] += (n._n[i] + ci);
        if(_n[i] < (n._n[i] + ci))
            ci = _n[i] - (n._n[i] + ci);
    }
}

string int256::to_string()
{
    std::stringstream ss;
    int len = BYTES32_256BITS;
    char* s = new char[1];
    for(int i = len; i < len; ++i)
    {
        int n = (int)_n[i];
        itoa(n, s);
        ss << s;
        delete []  s;
    }
    return ss.str();
}

int main()
{
    int256 n;
    n.add(1);
    return 0;
}

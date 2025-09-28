/**
 * @file    int256.hpp
 * @version 0.0.1
 * @date    Sun, 28 Sep 2025 01:13:35 +0000
 * @info    ...
 */
#ifndef _int256_HPP_
#define _int256_HPP_
#include <iostream>
#include <string>

#define BYTES32_256BITS 32

using std::cout;
using std::cin;
using std::endl;
using std::string;

/**
  * @brief class int256
  */
class int256
{
public:
	int256();
	int256(unsigned char c);
	int256( const int256& src );
	virtual ~int256();
	void add(int256 n);
	string to_string();

	/**
	  * @brief
	  * @brief c++ comment ...
	  * @brief place future addtions here ...
	  *
	*/

private:
    unsigned char _n[BYTES32_256BITS];

};

#endif

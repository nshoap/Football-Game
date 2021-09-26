#ifndef TEXT_FX_H
#define TEXT_FH_H

#include <iostream>
#include <chrono>
#include <thread>

/* Prints out text in delayed fashion to give impression of real-time writing */
/* output defaults to stdout and delay defaults to 50 milliseconds */
void HesitateText(std::istream& in, std::ostream& out = std::cout, const size_t& delay = 50);

#endif

Author: Kristoffer Carlino
Course: CS310 – Advanced C++
Assignment: Chapter 13 – Programming Exercise 17
Description: Demonstrates C++11 RNG and exception handling.

📝 Overview

It generates 25 random real numbers between 10 and 100 using a proper C++11 Random Number Generator (std::random_device, std::mt19937, std::uniform_real_distribution).

The program also includes exception handling to showcase safe and reliable error management. After generating the numbers, it checks how many fall within a user-defined "danger zone." If too many values fall within that range, the program deliberately throws a custom exception (ThresholdException) to demonstrate exception handling and recovery.

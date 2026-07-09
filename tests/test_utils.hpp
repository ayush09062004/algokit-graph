#pragma once

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

inline void print_header(const std::string& title)
{
    std::cout << "=====================================\n";
    std::cout << title << '\n';
    std::cout << "=====================================\n\n";
}

inline void print_success()
{
    std::cout << "\n=====================================\n";
    std::cout << "All tests passed!\n";
    std::cout << "=====================================\n";
}

#define RUN_TEST(test_name)                     \
    std::cout << "[RUN ] " << test_name << '\n';

#define PASS_TEST(test_name)                    \
    std::cout << "[PASS] " << test_name << "\n\n";

#define FAIL_TEST(message)                      \
    do                                          \
    {                                           \
        std::cerr << "[FAIL] " << message       \
                  << '\n';                      \
        std::exit(EXIT_FAILURE);                \
    } while (0)

#define EXPECT_TRUE(condition)                                      \
    do                                                              \
    {                                                               \
        if (!(condition))                                           \
        {                                                           \
            FAIL_TEST("Expected TRUE: " #condition);                \
        }                                                           \
    } while (0)

#define EXPECT_FALSE(condition)                                     \
    do                                                              \
    {                                                               \
        if (condition)                                              \
        {                                                           \
            FAIL_TEST("Expected FALSE: " #condition);               \
        }                                                           \
    } while (0)

#define EXPECT_EQ(actual, expected)                                         \
    do                                                                      \
    {                                                                       \
        if ((actual) != (expected))                                         \
        {                                                                   \
            std::cerr << "[FAIL]\n";                                        \
            std::cerr << "Expected : " << (expected) << '\n';               \
            std::cerr << "Actual   : " << (actual) << '\n';                 \
            std::exit(EXIT_FAILURE);                                        \
        }                                                                   \
    } while (0)

#define EXPECT_THROW(statement, exception_type)                 \
    do                                                          \
    {                                                           \
        bool thrown = false;                                    \
                                                            \
        try                                                     \
        {                                                       \
            statement;                                          \
        }                                                       \
        catch (const exception_type&)                           \
        {                                                       \
            thrown = true;                                      \
        }                                                       \
                                                            \
        if (!thrown)                                            \
        {                                                       \
            FAIL_TEST("Expected exception was not thrown.");     \
        }                                                       \
    } while (0)
    
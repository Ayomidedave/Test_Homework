#include "zipfs.h"
#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <utility>

using namespace Session17and19;

TEST(ZipfsAlgorithms, ReadBook) {
    std::string filename = "test.txt";
    std::ofstream outFile(filename);
    outFile << "Hello World!";
    outFile.close();

    std::vector<char> book = readBook(filename);
    ASSERT_EQ(book.size(), 12);
    EXPECT_EQ(book[0], 'H');
    EXPECT_EQ(book[5], ' ');
}

TEST(ZipfsAlgorithms, SortFrequenciesVector) {
    std::vector<std::pair<std::string, int>> frequencies = {{"Hello", 3}, {"World", 2}};
    sortFrequenciesVector(frequencies);

    ASSERT_EQ(frequencies.size(), 2);
    EXPECT_EQ(frequencies[0].first, "Hello");
    EXPECT_EQ(frequencies[0].second, 3);
}
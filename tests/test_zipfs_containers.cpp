#include "zipfs.h"
#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <map>

using namespace Session17and19;

TEST(ZipfsContainer, ReadBook) {
    std::string filename = "test.txt";
    std::ofstream outFile(filename);
    outFile << "Hello World!";
    outFile.close();

    std::vector<char> book = readBook(filename);
    ASSERT_EQ(book.size(), 12);
    EXPECT_EQ(book[0], 'H');
    EXPECT_EQ(book[5], ' ');
}

TEST(ZipfsContainer, CountUniqueWords) {
    std::vector<char> book = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};
    int uniqueWordCount = countUniqueWords(book);

    EXPECT_EQ(uniqueWordCount, 2);
}
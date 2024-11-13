#pragma once
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
#include <iostream>
namespace Session17and19 {
    /**
     * @brief FOR CONTAINERS
     */
    /**
     * @brief Reads the contents of a text file into a vector of characters, replacing non-alphabet characters with spaces.
     * @param fileName The path to the book file to be read.
     * @return Returns a vector of characters in the book read..
     */
    std::vector<char> readBook(std::string fileName);

    /**
     * @brief This finds the frequency of each unique word in the book text.
     * @param book A vector of characters representing the book text.
     * @return Returns a map where each key is a word and each value is the frequency of that word.
     */
    std::map<std::string, int> computeWordFrequency(const std::vector<char> &book);

    /**
     * @brief Counts the number of unique words in the book text.
     * @param book A vector of characters representing the book text.
     * @return Returns an integer representing the total number of unique words.
     */
    int countUniqueWords(const std::vector<char> &book);

    /**
     * @brief It sorts word frequencies in descending order.
     * @param frequencies A map containing words as keys and their corresponding frequencies as values.
     * @return A multimap where the keys are frequencies and the values are words and it's also sorted in decreasing order.
     */
    std::multimap<int, std::string, std::greater<int>> sortFrequencies(const std::map<std::string, int> &frequencies);

    /**
     * @brief Outputs sorted word frequencies to a file.
     * @param sorted_frequencies A multimap containing frequencies and words sorted in descending order.
     * @param filename The path to the output file.
     */
    void OFTFContainers(const std::multimap<int, std::string, std::greater<int>>& sorted_frequencies, const std::string& filename);

    /**
     * @brief FOR ALGORITHMS
     */

    /**
     * @brief Computes word frequencies from a vector of characters.
     * @param book A vector of characters representing the book text.
     * @return A vector of pairs, where each pair consists of a word and its frequency.
     */
    std::vector<std::pair<std::string, int>> computeWordFrequencyVector(const std::vector<char>& book);

    /**
     * @brief Sorts a vector of word-frequency pairs in descending order of frequency.
     * @param frequencies A vector of pairs, where each pair consists of a word and its frequency.
     */
    void sortFrequenciesVector(std::vector<std::pair<std::string, int>>& frequencies);

    /**
     * @brief Outputs a sorted vector of word frequencies to a file.
     * @param frequencies A vector of pairs, where each pair consists of a word and its frequency, sorted in descending order.
     * @param filename The path to the output file.
     */
    void OFTFAlgorithms(const std::vector<std::pair<std::string, int>>& frequencies, const std::string& filename);
} // namespace Session17and19
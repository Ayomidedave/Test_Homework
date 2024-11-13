#include "zipfs.h"
namespace Session17and19{
    // Function to read the book file and store only alphabetic characters.
    std::vector<char> readBook(std::string fileName){
        std::vector<char> result;
        std::ifstream file(fileName);
        char c;

        while (file.get(c)){
            if (std::isalpha(c)){
                result.push_back(c);
        }
            else
        {
                result.push_back(' ');
        }
    }

        return result;
}
    // Function to compute word frequency from the vector of characters
    std::map<std::string, int> computeWordFrequency(const std::vector<char> &book)
{
        std::map<std::string, int> wordFrequency;
        std::stringstream ss(std::string(book.begin(), book.end()));
        std::string word;

        while (ss >> word)
    {

            ++wordFrequency[word];
    }

        return wordFrequency;
}
    // Function to count unique words
    int countUniqueWords(const std::vector<char> &book)
{
        std::set<std::string> uniqueWords;
        std::stringstream ss(std::string(book.begin(), book.end()));
        std::string word;

        while (ss >> word)
    {
            uniqueWords.insert(word);
    }

        return uniqueWords.size();
}
    // Function to sort frequencies in descending order
    std::multimap<int, std::string, std::greater<int>> sortFrequencies(const std::map<std::string, int> &frequencies)
{
        std::multimap<int, std::string, std::greater<int>> sorted_freq;

        for (const auto &[word, frequency] : frequencies)
    {
            sorted_freq.insert({frequency, word});
    }

        return sorted_freq;
}

    /*void OFTF(const std::multimap<int, std::string, std::greater<int>>& sorted_frequencies, const std::string& filename){
        std::ofstream of(filename);

        if(!of){
            std::cerr<<"Error! cannot open the file"<<std::endl;
            return;
    }

        int rank = 1;
        for (const auto& pair : sorted_frequencies){
            of << rank <<" "<<pair.first <<" "<<pair.second<<" "<<"\n";
            ++rank;

    }*/

    //Modified version using structured binding
    void OFTFContainers(const std::multimap<int, std::string, std::greater<int>>& sorted_frequencies, const std::string& filename){
        std::ofstream of(filename);

        if(!of){
            std::cerr<<"Error! cannot open the file"<<std::endl;
            return;
    }

        int rank = 1;
        for (const auto& [frequency, word] : sorted_frequencies){
            of << rank <<" "<<frequency <<" "<<word<<" "<<"\n";
            ++rank;

    }

}

    int main(){
        std::string filename = "pg2701.txt";
        std::vector<char> book = readBook(filename);

        for (char c : book)
    {
            std::cout << c;
    }
        std::cout << std::endl;

        std::map<std::string, int> word_counts = computeWordFrequency(book);

        std::cout << "Word frequencies:\n";
        for (const auto &pair : word_counts)
    {
            std::cout << pair.first << ": " << pair.second << '\n';
    }

        int UniqueWord_size = countUniqueWords(book);
        std::cout << "Size of unique words: " << UniqueWord_size << std::endl;

        std::multimap<int, std::string, std::greater<int>> sorted_frequencies = sortFrequencies(word_counts);
        std::cout << "Sorted word frequencies:\n";
        for (const auto& pair : sorted_frequencies) {
            std::cout << pair.first << ": " << pair.second << "\n"; 
    }

        std::string outputFilename = "word_frequencies.txt";
        OFTFContainers(sorted_frequencies, outputFilename);

        return 0;
}

}
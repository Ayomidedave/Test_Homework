#include "zipfs.h"
namespace Session17and19 {
    // Function to read the book file and store only alphabetic characters.
    std::vector<char> readBook(std::string fileName)
{
        std::vector<char> result;
        std::ifstream file(fileName);
        char c;

        while (file.get(c))
        {
            if (std::isalpha(c))
            {
                result.push_back(c);
            }
            else
            {
                result.push_back(' ');
            }
        }

        return result;
}


    std::vector<std::pair<std::string, int>> computeWordFrequencyVector(const std::vector<char>& book) {
        std::stringstream ss(std::string(book.begin(), book.end()));
        std::string word;
        std::vector<std::pair<std::string, int>> wordFrequency;

        
        while (ss >> word) {
            auto it = std::find_if(wordFrequency.begin(), wordFrequency.end(),
                                [&word](const std::pair<std::string, int>& p) { return p.first == word; });

            if (it != wordFrequency.end()) {
                ++it->second; 
            } else {
                wordFrequency.emplace_back(word, 1); 
            }
        }
        return wordFrequency;
    }


    void sortFrequenciesVector(std::vector<std::pair<std::string, int>>& frequencies) {
        std::sort(frequencies.begin(), frequencies.end(),
                [](const auto& a, const auto& b) { return a.second > b.second; });
    }

    void OFTFAlgorithms(const std::vector<std::pair<std::string, int>>& frequencies, const std::string& filename) {
        std::ofstream outFile(filename);
        
        if (!outFile) {
            std::cerr << "Error opening file for writing: " << filename << std::endl;
            return;
        }

        int rank = 1;  
        for (const auto& [word, frequency] : frequencies) { 
            outFile << rank << " " << frequency << " " << word << "\n"; 
            ++rank; 
        }
    }

    int main(){
        std::string fileName = "pg2701.txt";  
        std::vector<char> book = readBook(fileName);
        
        auto frequencies = computeWordFrequencyVector(book);
        
        sortFrequenciesVector(frequencies);
        
        std::string outputFilename = "word_freq.txt"; 
        OFTFAlgorithms(frequencies, outputFilename); 
        
        return 0;
    }
}
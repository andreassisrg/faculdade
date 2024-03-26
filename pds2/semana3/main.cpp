#include <fstream>
#include <iostream>
#include <string>

bool badIf(std::ifstream &arq, std::string arq_cam);
bool improveIf(std::ifstream &arq, std::string arq_cam);

int main()
{
    std::ifstream inputFile;
    std::string pathFile = "true_file.txt";

    inputFile.open(pathFile);
    inputFile.seekg(0);

    std::cout << std::boolalpha;
    std::cout << "Bad if: \n" << badIf(inputFile, pathFile) << '\n';
    std::cout << "Improved if: \n" << improveIf(inputFile, pathFile) << std::endl;
}

bool badIf(std::ifstream &arq, std::string arq_cam)
{
    std::string linha;
    if (arq_cam != "")
    {
        if (arq.is_open())
        {
            arq.seekg(0);
            if (std::getline(arq, linha))
            {
                if (linha.find("importante") != std::string::npos)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool improveIf(std::ifstream &arq, std::string arq_cam)
{
    std::string linha;
    if (arq_cam == "")
        return false;
    
    if (!arq.is_open())
        return false;

    arq.seekg(0);

    bool encontrou = false;
    if (std::getline(arq, linha))
    {
        if (linha.find("importante") != std::string::npos)
        {
            encontrou = true;
            return encontrou;
        }
    }
    return encontrou;
}
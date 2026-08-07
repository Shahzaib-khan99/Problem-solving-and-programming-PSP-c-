#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])

  {
    if (argc < 2)
    {
        std::cout << "Usage: display.exe file1 file2 ...";
        return 1;
          }

             for (int i = 1; i < argc; i++)
          {
        std::ifstream file(argv[i]);

           if (!file)
        {
            std::cout << "File not open: " << argv[i] << std::endl;
            continue;
        }
           std::string line;

        while (std::getline(file, line))
        
        {
            std::cout << line << std::endl;
        }

        file.close();
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <array>

using namespace std;

int main(int argc, char** argv) 
{
    if(argc != 3)
    {
        cerr << "Usage: "s << argv[0] << " <in file> <out file>"s << endl;
        return 1;
    }

    ifstream in_file(argv[1], ios::binary);
    if(!in_file)
    {
        cerr << "Can't open input file"s << endl;
        return 2;
    }

    ofstream out_file(argv[2], ios::binary);
    if(!out_file)
    {
        cerr << "Can't open output file"s << endl;
        return 2;
    }

    static const int BUFF_SIZE = 1024;
    std::array<char, BUFF_SIZE> buffer;

    do
    {
        in_file.read(buffer.data(), BUFF_SIZE);
        out_file.write(buffer.data(), BUFF_SIZE);
    } while (in_file);
    

    return 0;
}
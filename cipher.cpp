#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;




char encode_character(char character, int shift)
{
    if (isalpha(character))
    {
        if (islower(character))
        {
            for (int i = 0; i <shift;i++)
            {
                if (character == 'z')
                {
                    character = 'a';
                }
                else
                    character++;
            }

        }
        else if (isupper(character))
        {
            for (int i = 0; i <shift;i++)
            {
                if (character == 'Z')
                {
                    character = 'A';
                }
                else
                    character++;
            }
        }

    }
    return character;
}





string encode(string input_str, int shift)
{
    string line,text;

    for(int i=0; i <input_str.size();i++)
    {
        text = encode_character(input_str[i],shift);
        line.append(text);
    }
    return line;
}






int main ()
{
    string input_file,file_out,input_str,encode_line,text;

    int shift;


    cout << "enter file name" <<endl;
    cin >> input_file;

    cout<< "enter the amount you want to shift your characters by"<<endl;
    cin >> shift;

    cout << "enter your output file (.txt only)"<<endl;
    cin >> file_out;

    ifstream myfile{input_file};

    while (myfile.good () == true)
    {
        getline(myfile,input_str);

        encode_line = encode(input_str,shift);
        text.append(encode_line);
    }
    myfile.close();

    ofstream out_file;
    out_file.open(file_out);
    out_file<<text;
    out_file.close();

}






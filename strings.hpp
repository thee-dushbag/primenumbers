/*

    +-------------------------------------------------------------------+
    |                                                                   |
    |                  [*]                                              |
    |          _______  __  ___________  _______  ________              |
    |         |  _____||  ||     |     ||       ||     |  |             |
    |         |_____  ||  ||  |  |  |  ||  [*]  ||  |  |  |             |
    |         |_______||__||__|_____|__||_______||__|_____|[*]          |
    |         /////////////////////////////////////////////////         |
    |    ________  ______  _________  ________  ______  _________       |
    |   |     |  ||   ___||         ||     |  ||   ___||         |      |
    |   |  |  |  ||  |_  ||   [#]   ||  |  |  ||  |_  ||   [#]   |      |
    |   |__|_____||______||__|   |__||__|_____||______||__|   |__|[*]   |
    |   ///////////////////////////////////////////////////////////     |
    |                                                                   |
    |            Developer Name : Simon Nganga Njoroge                  |
    |                     Email : theedushbag@gmail.com                 |
    |                   Library : theedushbag                           |
    |                  Language : C++                                   |
    |                                                                   |
    +-------------------------------------------------------------------+

*/

#ifndef CMON_STRING_METHODS
#define CMON_STRING_METHODS

// resolve the dependencies automatically
#ifndef NO_INCLUDE
//  resolve dependency vector if unmet
#ifndef _GLIBCXX_VECTOR
#include <vector>
#endif //_GLIBCXX_VECTOR

//  resolve dependency string if unmet
#ifndef _GLIBCXX_STRING
#include <string>
#endif //_GLIBCXX_STRING

#endif // NO_INCLUDE

namespace theedushbag
{
    namespace strings
    {
        /*all available functions in this namespace in this particular file*/
        inline std::vector<std::string> all = {
            "std::vector<std::string> split(std::string str, char sep)",
            "std::string join(bottle container, std::string separater)",
            "bool is_lower_char(int ch)",
            "bool is_upper_char(int ch)",
            "bool is_lowercase(std::string str)",
            "char upper_char(char ch)",
            "char lower_char(char ch)",
            "bool is_uppercase(std::string str)",
            "std::string uppercase(std::string str)",
            "std::string lowercase(std::string str)",
            "std::string title(std::string str)",
            "std::string capitalize(std::string str)",
            "std::string toggle(std::string str)",
            "std::string reverse(std::string str)",
            "bool is_numeric_char(char ch)",
            "int count(char ch, std::string str)",
            "bool is_numeric(std::string str)",
            "int to_number_char(char ch)",
            "template <typename Type> Type to_num(std::string str, std::string type = \"double\")",
            "std::string to_str(double number)"};

        /*split a string into potions sep by passed sep*/
        inline std::vector<std::string>
        split(std::string str, char sep)
        {
            /*split a str(std::string) using a separater sep(char)
            split("simon nganga", ' ')*/
            static std::vector<std::string> words;
            str.push_back(' ');
            std::string word;
            for (int i = 0; i < str.length(); i++)
            {
                if (str.at(i) != sep)
                    word.push_back(str.at(i));
                else
                {
                    words.push_back(word);
                    word = "";
                }
            }
            words.shrink_to_fit();
            return words;
        }
        /*concat elements separated by a passed sep
         in a container (eg vector, array) to form
        one single string*/
        template <typename bottle>
        inline std::string join(bottle container, std::string separater)
        {
            std::string sentence;
            for (int i = 0; i < container.size(); i++)
            {
                for (int j = 0; j < container[i].length(); j++)
                    sentence.insert(sentence.end(), container[i].at(j));
                if ((i + 1) != container.size())
                {
                    for (int h = 0; h < separater.length(); h++)
                        sentence.insert(sentence.end(), separater.at(h));
                }
            }
            return sentence;
        }
        /*check wether a char is an lower char*/
        inline bool is_lower_char(int ch)
        {
            if (ch >= 97)
            {
                if (ch <= 122)
                    return true;
            }
            return false;
        }
        /*check wether a char is an upper char*/
        inline bool is_upper_char(int ch)
        {
            if (ch >= 65)
            {
                if (ch <= 90)
                    return true;
            }
            return false;
        }
        /*check wether a string is in lower chars*/
        inline bool is_lowercase(std::string str)
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (!is_lower_char(str[i]))
                    return false;
            }
            return true;
        }
        /*convert char ch to upper char*/
        char upper_char(char ch)
        {
            if (is_upper_char(ch))
                return ch;
            return (char)(ch - 32);
        }
        /*

            +-------------------------------------------------------------------+
            |                                                                   |
            |                  [*]                                              |
            |          _______  __  ___________  _______  ________              |
            |         |  _____||  ||     |     ||       ||     |  |             |
            |         |_____  ||  ||  |  |  |  ||  [*]  ||  |  |  |             |
            |         |_______||__||__|_____|__||_______||__|_____|[*]          |
            |         /////////////////////////////////////////////////         |
            |    ________  ______  _________  ________  ______  _________       |
            |   |     |  ||   ___||         ||     |  ||   ___||         |      |
            |   |  |  |  ||  |_  ||   [#]   ||  |  |  ||  |_  ||   [#]   |      |
            |   |__|_____||______||__|   |__||__|_____||______||__|   |__|[*]   |
            |   ///////////////////////////////////////////////////////////     |
            |                                                                   |
            |            Developer Name : Simon Nganga Njoroge                  |
            |                     Email : theedushbag@gmail.com                 |
            |                   Library : theedushbag                           |
            |                  Language : C++                                   |
            |                                                                   |
            +-------------------------------------------------------------------+

        */
        /*convert char ch to lower char*/
        char lower_char(char ch)
        {
            if (is_lower_char(ch))
                return ch;
            return (char)(ch + 32);
        }
        /*check wether the passed string is in uppercase*/
        inline bool is_uppercase(std::string str)
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (!is_upper_char(str[i]))
                    return false;
            }
            return true;
        }
        /*convert passed string to uppercase*/
        inline std::string uppercase(std::string str)
        {
            std::string result_str;
            for (int i = 0; i < str.length(); i++)
            {
                if (is_lower_char(str[i]))
                    result_str.push_back(upper_char(str[i]));
                else
                    result_str.push_back(str[i]);
            }
            return result_str;
        }
        /*converts passed string to lowercase*/
        inline std::string lowercase(std::string str)
        {
            std::string result_str;
            for (int i = 0; i < str.length(); i++)
            {
                if (is_upper_char(str[i]))
                    result_str.push_back(lower_char(str[i]));
                else
                    result_str.push_back(str[i]);
            }
            return result_str;
        }
        /*format a string where all char following a space are mde uppercase
        and all others lowercase*/
        inline std::string title(std::string str)
        {
            std::vector<std::string> words = split(str, ' ');
            for (std::string &word : words)
                word[0] = upper_char(word[0]);
            return join(words, " ");
        }
        /*

            +-------------------------------------------------------------------+
            |                                                                   |
            |                  [*]                                              |
            |          _______  __  ___________  _______  ________              |
            |         |  _____||  ||     |     ||       ||     |  |             |
            |         |_____  ||  ||  |  |  |  ||  [*]  ||  |  |  |             |
            |         |_______||__||__|_____|__||_______||__|_____|[*]          |
            |         /////////////////////////////////////////////////         |
            |    ________  ______  _________  ________  ______  _________       |
            |   |     |  ||   ___||         ||     |  ||   ___||         |      |
            |   |  |  |  ||  |_  ||   [#]   ||  |  |  ||  |_  ||   [#]   |      |
            |   |__|_____||______||__|   |__||__|_____||______||__|   |__|[*]   |
            |   ///////////////////////////////////////////////////////////     |
            |                                                                   |
            |            Developer Name : Simon Nganga Njoroge                  |
            |                     Email : theedushbag@gmail.com                 |
            |                   Library : theedushbag                           |
            |                  Language : C++                                   |
            |                                                                   |
            +-------------------------------------------------------------------+

        */

        /*convert the first char of the passed string to upper char and
        all others to lowercase*/
        inline std::string capitalize(std::string str)
        {
            str[0] = upper_char(str[0]);
            return str;
        }
        /*swap the case of the chars in the passed string*/
        inline std::string toggle(std::string str)
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (is_lower_char(str[i]))
                    str[i] = upper_char(str[i]);
                else if (is_upper_char(str[i]))
                    str[i] = lower_char(str[i]);
            }
            return str;
        }
        /*reverse the position of the chars in a string*/
        inline std::string reverse(std::string str)
        {
            std::string reversed;
            for (int i = str.length(); i > 0; i--)
                reversed.push_back(str.at(i - 1));
            return reversed;
        }
        /*returns true if the passed char is numeric*/
        inline bool is_numeric_char(char ch)
        {
            if (ch >= 48)
            {
                if (ch <= 57)
                    return true;
            }
            return false;
        }

        /*counts how many times a char ch appears in the string str*/
        inline int count(char ch, std::string str)
        {
            int counter = 0;
            for (int i = 0; i < str.length(); i++)
                if (str.at(i) == ch)
                    counter++;
            return counter;
        }

        /*returns true if the string (std::string) passed is made of integers*/
        inline bool is_numeric(std::string str)
        {
            if ((count('.', str)) <= 1)
            {
                for (int i = 0; i < str.length(); i++)
                {
                    if (str.at(i) == '.')
                        continue;
                    if (!is_numeric_char(str.at(i)))
                        return false;
                }
                return true;
            }
            return false;
        }
        /*convert a char constant to an int
        NOTE : char constant must be an integer*/
        inline int to_number_char(char ch)
        {
            return (int)(ch - 48);
        }

        int __p(int a, int b)
        {
            int t = 1;
            for (int i = 1; i <= b; i++)
                t *= a;
            return t;
        }
        /*

            +-------------------------------------------------------------------+
            |                                                                   |
            |                  [*]                                              |
            |          _______  __  ___________  _______  ________              |
            |         |  _____||  ||     |     ||       ||     |  |             |
            |         |_____  ||  ||  |  |  |  ||  [*]  ||  |  |  |             |
            |         |_______||__||__|_____|__||_______||__|_____|[*]          |
            |         /////////////////////////////////////////////////         |
            |    ________  ______  _________  ________  ______  _________       |
            |   |     |  ||   ___||         ||     |  ||   ___||         |      |
            |   |  |  |  ||  |_  ||   [#]   ||  |  |  ||  |_  ||   [#]   |      |
            |   |__|_____||______||__|   |__||__|_____||______||__|   |__|[*]   |
            |   ///////////////////////////////////////////////////////////     |
            |                                                                   |
            |            Developer Name : Simon Nganga Njoroge                  |
            |                     Email : theedushbag@gmail.com                 |
            |                   Library : theedushbag                           |
            |                  Language : C++                                   |
            |                                                                   |
            +-------------------------------------------------------------------+

        */

        /*convert a numeric string to an integer
        Remember to fill the template in*/
        template <typename Type>
        inline Type to_num(std::string str, std::string type = "double")
        {
            if (type == "float")
                return std::stof(str);
            else if (type == "long int")
                return std::stol(str);
            else if (type == "unsigned long")
                return std::stoul(str);
            else if (type == "long double")
                return std::stold(str);
            else
                return std::stod(str);
        }

        /*converts a numeric value to a string*/
        inline std::string to_str(double number)
        {
            return std::to_string(number);
        }
    }
}

#endif

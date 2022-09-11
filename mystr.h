#ifndef myStr_H
#define myStr_H

bool is_upper(char ch)
{
    if (ch >= 65)
        if (ch <= 91)
            return true;
    return false;
}

bool is_lower(char ch)
{
    if (ch >= (96))
        if (ch <= 122)
            return true;
    return false;
}

char to_upper_char(char ch)
{
    if (is_lower(ch))
        return (ch - 32);
    return ch;
}

char to_lower_char(char ch)
{
    if (is_upper(ch))
        return (ch + 32);
    return ch;
}

void upper(char *str)
{
    for (int i = 0; i < strlen(str); i++)
        str[i] = to_upper_char(str[i]);
}

void lower(char *str)
{
    for (int i = 0; i < strlen(str); i++)
        str[i] = to_lower_char(str[i]);
}


#endif
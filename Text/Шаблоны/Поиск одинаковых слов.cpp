bool comparison(const char* w1, const char* w2)
{
    for (int i = 0; i < strlen(w1); i++)
        if (w1[i] != w2[i]) return false;
    return true;
};
int separation(char text[200], char words[][20])
{
    char* token;
    char* txt;
    int i = 0;
    
    token = strtok_s(text, " ", &txt);

    while (token != NULL)
    {
		strcpy_s(words[i], token);
		i++;
		token = strtok_s(NULL, " ", &txt);
    }

    return i;
};
bool getValue(const char queryString[], const char name[], char value[])
{
        bool result = false;

        char* p = strstr(queryString, name);

         bool foundNameInQuery = (p != NULL);
         bool foundEqualAfterName = ( *(p + strlen(name)) == '=' );
         bool foundNameAtBeginingOfQuery = (p == queryString);
         bool foundAmpersanBeforeName = (*(p - 1) == '&');

        if( foundNameInQuery && foundEqualAfterName && (foundNameAtBeginingOfQuery || foundAmpersanBeforeName))
        {
                int indexOfName = (int)(p - queryString);
                result = true;

                int queryIndex = indexOfName + (int)strlen(name) + 1;
                int valueIndex = 0;
                while(queryString[queryIndex] != '&' && queryString[queryIndex] != '\0')
                {
                        value[valueIndex] = queryString[queryIndex];
                        queryIndex++;
                        valueIndex++;
                }
                value[valueIndex] = '\0';
        }

        return result;
}


void fixQueryString(char queryString[])
{
        for(int i = 0; i < strlen(queryString); i++)
        {
                if( queryString[i] == '+')
                {
                         queryString[i] = ' ';
                }

                if( queryString[i] == '%')
                {
                         char firstHexValue = queryString[i+1];
                         char secondHexValue = queryString[i+2];

                         int asciiValue = 0;
                         switch( firstHexValue )
                         {
                                case 'F':
                                        asciiValue += 16;
                                case 'E':
                                        asciiValue += 16;
                                case 'D':
                                        asciiValue += 16;
                                case 'C':
                                        asciiValue += 16;
                                case 'B':
                                        asciiValue += 16;
                                case 'A':
                                        asciiValue += 16;
                                case '9':
                                        asciiValue += 16;
                                case '8':
                                        asciiValue += 16;
                                case '7':
                                        asciiValue += 16;
                                case '6':
                                        asciiValue += 16;
                                case '5':
                                        asciiValue += 16;
                                case '4':
                                        asciiValue += 16;
                                case '3':
                                        asciiValue += 16;
                                case '2':
                                        asciiValue += 16;
                                case '1':
                                        asciiValue += 16;
                         }
                         switch( secondHexValue )
                         {
                                case 'F':
                                        asciiValue += 1;
                                case 'E':
                                        asciiValue += 1;
                                case 'D':
                                        asciiValue += 1;
                                case 'C':
                                        asciiValue += 1;
                                case 'B':
                                        asciiValue += 1;
                                case 'A':
                                        asciiValue += 1;
                                case '9':
                                        asciiValue += 1;
                                case '8':
                                        asciiValue += 1;
                                case '7':
                                        asciiValue += 1;
                                case '6':
                                        asciiValue += 1;
                                case '5':
                                        asciiValue += 1;
                                case '4':
                                        asciiValue += 1;
                                case '3':
                                        asciiValue += 1;
                                case '2':
                                        asciiValue += 1;
                                case '1':
                                        asciiValue += 1;
                         }
                        queryString[i] = (char)asciiValue;
                        strcpy(queryString + i + 1, queryString + i + 3);
                }
        }
}

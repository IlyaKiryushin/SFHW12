#include <iostream>
#include <string>

void computeLPS(std::string pat, int* lps)
{
    int j = 0;
    lps[0] = 0;
    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0) {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void IsKPeriodic(int K, const std::string& txt)
{
    if ((K < 1)||(txt.empty())||(K > txt.size()))
    {
        std::cout << "Ошибка ввода!" << std::endl;
    }
    else
    {
        std::string pat;
        for (int i = 0; i < K; ++i)
            pat.push_back(txt[i]);
        int* lps = new int[pat.size()];
        computeLPS(pat, lps);
        int i = 0;
        int j = 0;
        int value = 0;
        while (i < txt.size()) {
            if (pat[j] == txt[i])
            {
                j++;
                i++;
            }
            if (j == pat.size()) {
                value++;
                j = lps[j - 1];
            }
            else if (i < txt.size() && pat[j] != txt[i]) {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i = i + 1;
                }
            }
        }
        if (K * value == txt.size())
            std::cout << "строка " << txt << " кратна " << K << std::endl;
        else std::cout << "строка " << txt << " не кратна " << K << std::endl;
        delete[] lps;
    }
}
int main()
{
    setlocale(LC_ALL, "");
    std::string txt;
    int K;
    char ans;
    bool exit = false;
    do
    {
        std::cout << "Введите строку: " << std::endl;
        std::getline(std::cin, txt);
        std::cout << "Введите число периодичности (K): " << std::endl;
        std::cin >> K;
        IsKPeriodic(K, txt);
        std::cout << "\nTry again (Y/N)?" << std::endl;
        std::cin >> ans;
        std::cin.ignore(32767, '\n');
        if (ans == 'N' || ans == 'n')
            exit = true;
    } while (!exit);
    return 0;
}
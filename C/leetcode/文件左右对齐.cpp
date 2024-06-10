#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string fillWords(vector<string>& words, int bg, int ed, int maxWidth, bool lastLine = false)
{
    int wordCount = ed - bg + 1;
    int spaceCount = maxWidth + 1 - wordCount;  // ��ȥÿ������β���ո� + 1 �����һ�����ʵ�β���ո�����⴦��
    for (int i = bg; i <= ed; i++)
    {
        spaceCount -= words[i].size();  // ��ȥ���е��ʵĳ���
    }

    int spaceSuffix = 1;    // ��β�ո�
    int spaceAvg = (wordCount == 1) ? 1 : spaceCount / (wordCount - 1);     // ����ո��ƽ��ֵ
    int spaceExtra = (wordCount == 1) ? 0 : spaceCount % (wordCount - 1);   // ����ո������

    string ans;
    for (int i = bg; i < ed; i++)
    {
        ans += words[i];    // ���뵥��
        if (lastLine)   // ���⴦�����һ��
        {
            fill_n(back_inserter(ans), 1, ' ');
            continue;
        }
        fill_n(back_inserter(ans), spaceSuffix + spaceAvg + ((i - bg) < spaceExtra), ' ');  // ���ݼ��������Ͽո�
    }
    ans += words[ed];   // �������һ������
    fill_n(back_inserter(ans), maxWidth - ans.size(), ' '); // ������һ�����Ŀո�
    return ans;
}


vector<string> fullJustify(vector<string>& words, int maxWidth)
{
    vector<string> ans;
    int cnt = 0;
    int bg = 0;
    for (int i = 0; i < words.size(); i++)
    {
        cnt += words[i].size() + 1;

        if (i + 1 == words.size() || cnt + words[i + 1].size() > maxWidth)
        {   // ��������һ�����ʣ����߼�����һ���ʾͳ��������ˣ����ɴճ�һ��
            ans.push_back(fillWords(words, bg, i, maxWidth, i + 1 == words.size()));
            bg = i + 1;
            cnt = 0;
        }
    }
    return ans;
}
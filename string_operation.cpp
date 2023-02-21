#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    string str,post, pre, sub;
    string output1, output2, output3;
    int len,i=0,j,choice;

    cout<<"Enter\n1 for prefix\n2 for postfix\n3 for substring\n4 to exit: ";
    cin>> choice;

    while(1)
    {
        cout<<"\nEnter string: ";
        cin>> str;

        len = str.length();
        switch(choice)
        {
        case 1:
            cout<<"\nPrefix\n";
            pre = str;
            for(i=0;i<len;i++)
            {
                output1.append(1,pre[i]);
                cout<< output1 <<" ";
            }
            break;

        case 2:
            cout<<"\nPostfix\n";
            post = str;
            reverse(post.begin(), post.end());

            for(i=0;i<len;i++)
            {
                output2.append(1,post[i]);
                cout<< output2 <<" ";
            }
            break;

        case 3:
            cout<<"\nSubstring\n";
            sub = str;
            while(len!=0)
            {
                for(j=0;j<len;j++)
                {
                    output3.append(1,sub[j]);
                    cout<< output3 <<" ";
                }
                output3.clear();
                cout<<"\n";
                sub.erase(0,1);
                len=sub.length();
            }
            break;

        case 4:
            exit(0);

        default:
            exit(0);
        }
        cout<<"\n\nEnter\n1 for prefix\n2 for postfix\n3 for substring\n4 to exit: ";
        cin>> choice;
    }
}

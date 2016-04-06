#include <iostream>
#include <string.h>
using namespace std;

int backpack(int need[], int value[], const int N, const int M)
{
    int bp[M + 1];
    memset(bp, 0, sizeof(bp));
    for(int i = 0 ; i < N ; ++i)  
    {  
        for(int j = 1 ; j <= M; ++j)  
        {
            if(j >= need[i])
                bp[j] = max(bp[j] , bp[j-need[i]] + value[i]);  
        }  
    }
    return bp[M];
}

int main()
{
    int N, M;
    cin >> N >> M;
    
    int need[N];
    int value[N];
    for(int i = 0; i < N; ++i) 
    {
        cin >> need[i] >> value[i];
    }
    
    int res = backpack(need, value, N, M);
    cout << res << endl;
    return 0;
}

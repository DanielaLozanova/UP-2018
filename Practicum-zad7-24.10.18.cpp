#include <iostream>

using namespace std;

int main()
{
    bool flag=0;
    int k=0, cnt=1,s,n=5,cntStraight=0;
    int arr1[5]={0};
    int arr2[5]={0};

    for(int i=0;i<n;++i)
    {
        cin>>arr1[i];
    }
    for(int j=0;j<4;++j)
    {
        if(arr1[j]>arr1[j+1])
        {
            flag=1;
            ++cntStraight;
        }
    }

   for (int c = 0 ; c <n - 1; ++c)
  {
    for (int d = 0 ; d < n - c - 1; ++d)
    {
      if (arr1[d] > arr1[d+1])
      {
        s = arr1[d];
        arr1[d] = arr1[d+1];
        arr1[d+1] = s;
      }
    }
  }

  for(int w=0;w<4;++w)
  {
      if(arr1[w]==arr1[w+1])
      {
          ++cnt;
          arr2[k]=cnt;
      }
      else
        {
            cnt=1;
            ++k;
            arr2[k]=cnt;
        }
  }

  for (int t = 0 ; t <n - 1; ++t)
  {
    for (int y = 0 ; y < n - t - 1; ++y)
    {
      if (arr2[y] < arr2[y+1])
      {
        s = arr2[y];
        arr2[y] = arr2[y+1];
        arr2[y+1] = s;
      }
    }
  }

  if(flag==1 && cntStraight==4)
  {
      cout<<"Straight";
  }
  else
  {
      switch(arr2[0])
      {
          case 5: cout<<"Impossible"; break;
          case 4: cout<<"Four of a Kind"; break;
          case 3: if(arr2[1]==2) {cout<<"Full House";}
                  else {cout<<"Three of a Kind";}; break;
          case 2: if(arr2[1]==2) {cout<<"Two Pairs";}; break;
          default: cout<<"Nothing";
      }
  }
    return 0;
}

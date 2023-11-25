#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
int fir[400000],sec[400000],a[15][15][15];
double v[15],b[15][15];
int quadr(int p)
{
    int ret=0;
    while (p>0)
    {
        int cur=p%4;
        p/=4;
        if (cur==1) ret++;
    }
    return (ret%2);
}
int dot(int p, int q)
{
    int ret=0;
    while ((p>0) && (q>0))
    {
        int curp=p%4;
        int curq=q%4;
        p/=4; q/=4;
        if (curp==0) continue;
        if (curq==0) continue;
        if (curp==curq) continue;
        ret++;
    }
    return (ret%2);
}
int orbit(int p, int q)
{
    if (p==q)
    {
        return 0;
    }
    int cnt=dot(fir[p],fir[q])+dot(fir[p],sec[q])+dot(sec[p],fir[q])+dot(sec[p],sec[q]);
    if ((fir[p]==fir[q]) || (fir[p]==sec[q]) || (sec[p]==fir[q]) || (sec[p]==sec[q]))
    {
        if (cnt==0) return 1;
        else return 2;
    }
    if (cnt==0)
    {
        if (((fir[p]^fir[q])^(sec[p]^sec[q]))==0) return 3;
        else return 4;
    }
    if (cnt==1)
    {
        return 5;
    }
    if (cnt==3)
    {
        return 9;
    }
    if (cnt==4)
    {
        if (((fir[p]^fir[q])^(sec[p]^sec[q]))==0) return 10;
        else return 11;
    }
    if (cnt==2)
    {
        if ((dot(fir[p],fir[q])+dot(fir[p],sec[q])==1) && (dot(sec[p],fir[q])+dot(sec[p],sec[q])==1) &&
            (dot(fir[q],fir[p])+dot(fir[q],sec[p])==1) && (dot(sec[q],fir[p])+dot(sec[q],sec[p])==1)) return 6;
        if ((dot(fir[p],fir[q])+dot(fir[p],sec[q])==1) && (dot(sec[p],fir[q])+dot(sec[p],sec[q])==1)) return 7;
        else return 8;
    }
}
int main()
{
    freopen("lmatrix.txt", "w", stdout);
    int m,n,N1=0,i,j,k,p,q;
    m=10;
    n=(1 << m);
    for (i=1; i<n; i++)
        for (j=i+1; j<n; j++)
        {
            if (dot(i,j)) continue;
            if (quadr(i)==0) continue;
            if (quadr(j)==0) continue;
            fir[N1]=i;
            sec[N1]=j;
            N1++;
        }
    for (i=0; i<12; i++)
        for (j=0; j<12; j++)
            for (k=0; k<12; k++)
            {
                for (q=0; q<N1; q++)
                    if (orbit(0,q)==k) break;
                for (p=0; p<N1; p++)
                    if ((orbit(0,p)==i) && (orbit(p,q)==j)) a[k][i][j]++;
            }
    v[0]=1.0; v[1]=((double) 1)/8; v[2]=((double) 13)/256; v[3]=0.0; v[4]=0.0; v[5]=((double) 5)/256;
    v[6]=v[2]; v[7]=((double) 1)/64; v[8]=v[7]; v[9]=((double) 3)/128; v[10]=v[1]; v[11]=((double) 1)/32;
    for (k=0; k<12; k++)
        for (i=0; i<12; i++)
            for (j=0; j<12; j++)
                b[i][k]+=(v[j]*a[k][i][j]);
    cout<<"["<<endl;
    for (i=0; i<12; i++)
    {
        cout<<"[";
        for (j=0; j<12; j++)
        {
            cout<<b[i][j]*256<<"/256";
            if (j!=11) cout<<",";
            cout<<" ";
        }
        cout<<"]";
        if (i!=11) cout<<",";
        cout<<endl;
    }
    cout<<"]"<<endl;
    return 0;
}


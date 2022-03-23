void MergeSort(int v[], int st, int dr)
{
	if(st < dr)
	{
		int m = (st + dr) / 2;
		MergeSort(v, st , m);
		MergeSort(v, m + 1 , dr);
		//Interclasare
		int i = st, j = m + 1, k = 0;
		while( i <= m && j <= dr )
			if( v[i] < v[j])
				tmp[++k] = v[i++];
			else
				tmp[++k] = v[j++];
		while(i <= m)
			tmp[++k] = v[i++];
		while(j <= dr)
			tmp[++k] = v[j++];
		for(i = st , j = 1 ; i <= dr ; i ++ , j ++)
			v[i] = tmp[j];
	}
}
/// hanoi
#include <fstream>
#include <math.h>
using namespace std;

ifstream cin("hanoi.in");
ofstream cout("hanoi.out");

void hanoi(int n, char tstart, char tdest, char taux)
{
    if (n == 0) {
        return;
    }
    hanoi(n - 1, tstart, taux, tdest);
    cout<<tstart<<"->"<<tdest<<"\n";
    hanoi(n - 1, taux, tdest, tstart);
}

int main() {
    int n;
    cin>>n;
    cout<<pow(2, n) - 1<<"\n";
    hanoi(n, 'A', 'C', 'B');
}

/// Spectacole

#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("spectacole.in");
ofstream cout("spectacole.out");

int n , cnt;
struct poz
{
    int i , j;
}a[101];

bool comp(poz a , poz b)
{
    if(a.j < b.j) return 1;
    else if(a.j == b.j && a.i < b.i) return 1;
    else return 0;
}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i].i >> a[i].j;

    sort(a + 1 , a + n + 1 , comp);
    int ul = a[1].j;
    for(int i = 2 ; i <= n ; i++)
        if(ul <= a[i].i) cnt ++ , ul = a[i].j ;

    cout << cnt + 1;
}

/// Rucsac
#include <iostream>
#include <algorithm>
using namespace std;

struct obiect{

    int g,v;
};
int n, gmax;
obiect a[1005];

bool comp(obiect A, obiect B)
{
    return A.v * B.g > A.g * B.v;
}

int main()
{
    cin>>n>>gmax;
    for(int i=1;i<=n;++i)
        cin>>a[i].g>>a[i].v;
    sort(a+1,a+n+1,comp);
    int g = 0 , i = 1;
    double rez = 0;
    while(i <= n)
    {
        if(g + a[i].g <= gmax)
        {
            g += a[i].g;
            rez += a[i].v;
            i ++;
        }
        else if(gmax - g > 0)
            {
                double fractiune = 1.0 * (gmax - g) / a[i].g;
                g = gmax;
                rez += fractiune * a[i].v;
                i++;
            }
            else break;
    }
    cout << rez;
    return 0;
}

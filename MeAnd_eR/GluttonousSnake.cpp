#include<bits/stdc++.h>

#define ULK_SYC std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(0)
// unlock the standard CPP stream's synchronization to the standard C stream
#define rep(i, startLeft, endRight) for (int i = startLeft; i <= endRight; i++)
#define rrep(i, startRight, endLeft) for (int i = startRight; i >= endLeft; i--)
// loop
#define lli long long int
#define sot short
#define bol bool
#define dob double
#define stg string
// data types
#define puB push_back
#define poB pop_back
#define gC getchar
#define rvS reverse
#define frO front
#define beG begin
#define inS insert
// functions
#define nel '\n'
#define swt switch
#define cs case
#define wle while
#define brk break
#define rtn return
#define vct vector
#define quu queue
#define dqu deque
#define umap unordered_map
#define ummap unordered_multimap
#define uset unordered_set
#define umset unordered_multiset
using namespace std;

int uFRead()
{// "inline" is optional and limited
	int num = 0;
	int ch = gC();
	// if ch is not a decimal number
	wle ((ch < '0' || ch > '9') && ch != EOF) ch = gC();// absorb other characters
	// else
	wle (ch >= '0' && ch <= '9')
	{
		num = num * 10 + ch - '0';
		ch = gC();
	}
	rtn num;
}

int iFRead()
{// "inline" is optional and limited
	int num = 0;
	sot sign = 1;
	int ch = gC();
	// if ch is not a decimal number
	wle ((ch < '0' || ch > '9') && ch != EOF)
	{
		if (ch == '-') sign = -1;
		ch = gC();// absorb other characters
	}
	// else
	wle (ch >= '0' && ch <= '9')
	{
		num = num * 10 + ch - '0';
		ch = gC();
	}
	rtn num * sign;
}

vct<pair<int, int>> snk;

int main()
{
	int X, Y, ans=0,n = uFRead(), t = uFRead();
	rep(i, 0, n - 1)
	{
		X = iFRead(), Y = iFRead();
		pair<int, int> cdnt(X, Y);
		snk.puB(cdnt);
	}
	rvS(snk.begin(), snk.end());
	X = snk.back().first, Y = snk.back().second;
	rep(i, 0, t - 1)
	{
		swt (uFRead())
		{
		cs 0:
			X--;
			brk;
		cs 1:
			X++;
			brk;
		cs 2:
			Y--;
			brk;
		cs 3:
			Y++;
			brk;
		}
		pair<int, int> cdnt(X, Y);
		if (std::find(snk.begin() + i + 1, snk.end(), cdnt) == snk.end())
		{
			snk.puB(cdnt);
			ans++;
		}
		else brk;
	}
	cout << ans;
	rtn 0;
}
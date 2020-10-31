#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define nitro {std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);}
#define even(a) (!(a&1))
#define M 1000000007
#define push_back pb
#define first f
#define second s
#define make_pair mp
#define fori(a, b) for(int i=a; i<b; ++i)
#define forj(a, b) for(int j=a; j<b; ++j)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned long int ul;
typedef std::vector<ll> vi;
typedef std::unordered_map<ll, ll>  hmapi;
typedef std::pair<ll, ll> pairi;

int ans=0;

int row[8];
int col[8];
int diag1[16];
int diag2[16];

bool place_queen(char board[][8], int y, int i) {

	if(board[y][i] == '.' && row[y]==0 && col[i]==0 && diag1[i+y]==0 && diag2[7-y+i]==0) {
		row[y] = 1;
		col[i] = 1;
		diag1[i+y] = 1;
		diag2[7-y+i] = 1;

		return true;
	}
	else {
		return false;
	}
	
}

void remove_queen(int y, int i) {
	row[y] = 0;
	col[i] = 0;
	diag1[i+y] = 0;
	diag2[7-y+i] = 0;
}

void solve(char board[][8], int y) {

	if(y==8) {
		ans++;
		return;
	}
	for(int i=0;i<8;i++) {

		if(place_queen(board, y, i)) {
			solve(board, y+1);
			remove_queen(y, i);
		}
	
	}
}

int main() {
	nitro
	
	char board[8][8];

	fori(0, 8) {
		forj(0, 8) {
			cin>>board[i][j];
		}
	}

	solve(board, 0);

	cout<<ans<<endl;

	return 0;
}
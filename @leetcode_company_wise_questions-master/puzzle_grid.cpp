#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define maxn 3000

using namespace std;

int p[maxn*maxn];
int sizeOf[maxn*maxn];

int get( int x ) {
	if( p[x] != x ) {
		p[x] = get(p[x]);
	}
	return p[x];
}

void Union( int x, int y ) {
	x = get(x), y = get(y);
	
	if( x != y ) {
		if( sizeOf[x] < sizeOf[y] ) {
			swap(x, y);
		}
		
		p[y] = x;
		sizeOf[x] += sizeOf[y];
	}
}

void init( int n ) {
	for( int i = 0; i < n; i++ ) {
		p[i] = i;
		sizeOf[i] = 1;
	}
}

int grid[maxn][maxn];
vector<pair<int,int>> cells[1000001];
vector<int> s[1000001];


int main( void ) {
	int n, q;
	scanf("%i %i", &n, &q);
	
	const int max_num = 1000000;
	
	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < n; j++ ) {
			scanf("%i", &grid[i][j]);
			cells[grid[i][j]].push_back(make_pair(i,j));
		}
	}
		
	vector<int> X1(q), Y1(q), X2(q), Y2(q);
	vector<int> lo(q), hi(q), ans(q);
	
	for( int i = 0; i < q; i++ ) {
		scanf("%i %i %i %i", &X1[i], &Y1[i], &X2[i], &Y2[i]);
		lo[i] = 1, hi[i] = int(1e6)+1;
	}
	
	int lg = 21;
	while( lg-- ) {	
		for( int i = 0; i < q; i++ ) {
			if( lo[i] <= hi[i] ) {
				int mid = (lo[i] + hi[i]) / 2;
				s[mid].push_back(i);
			}
		}
		
		init(n*n);
		
		for( int e = 1; e <= max_num; e++ ) {
			if( !cells[e].empty() ) {
				for( auto cell : cells[e] ) {
					int dx[] = {0, 0, +1, -1};
					int dy[] = {+1, -1, 0, 0};
					
					int x = cell.first, y = cell.second;
					for( int c = 0; c < 4; c++ ) {
						int nx = x + dx[c], ny = y + dy[c];
						
						if( (nx >= 0) && (nx < n) && (ny >= 0) && (ny < n) ) {
							if( grid[nx][ny] <= grid[x][y] ) {
								int cellId0 = (x * n) + y;
								int cellId1 = (nx * n) + ny;
								Union(cellId0, cellId1);
							}
						}
					}
				}
			}
			
			if( !s[e].empty() ) {
				for( int idx : s[e] ) {
					int cellId0 = (X1[idx] * n) + Y1[idx];
					int cellId1 = (X2[idx] * n) + Y2[idx];
					
					if( get(cellId0) == get(cellId1) ) {
						ans[idx] = e;
						hi[idx] = e - 1;
					} else {
						lo[idx] = e + 1;
					}
				}
			}
		}
		
		for( int i = 1; i <= max_num; i++ ) {
			s[i].clear();
		}
	}
	
	for( int i = 0; i < q; i++ ) {
		printf("%i\n", ans[i]);
	}
	
	return 0;
}
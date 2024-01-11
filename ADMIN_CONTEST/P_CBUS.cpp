/*
Description
There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n). There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus). You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j (i, j = 0,1,…, 2n). Compute the shortest route for the bus, serving n passengers and coming back to point 0. 
Input

    Line 1 contains n and k (1≤n≤11,1≤k≤10)
     Line i+1 (i=1,2,…,2n+1) contains the (i−1)th line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).

Output

    Unique line contains the length of the shortest route.

Example
Input
3  2
0  8  5  1  10  5  9
9  0  5  6  6  2  8
2  2  0  3  8  7  2
5  3  4  0  3  2  7
9  6  8  7  0  9  10
3  8  10  6  5  0  2
3  4  4  5  2  2  0
Output
25
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = 40;

int n, k;
int distanceMin = 2147483647;
int distanceCur = 0;
int passengers = 0; // so hanh khach hien tai tren xe
int dist[MAX][MAX];
bool visited[MAX]; // danh dau
int X[MAX]; // luu tru vi tri duong di
int minDist;

/*input data*/
void inputData(){
    cin >> n >> k;
    for(int i=0; i<=2*n; i++)
        for(int j=0; j<=2*n; j++){
            cin >> dist[i][j];
        }
}

/*Find min dist*/
void findMin(){
    minDist = 2147483647;
    for(int i=0; i<=2*n; i++)
        for(int j=0; j<=2*n; j++){
            if(i!=j)
                minDist = min(minDist,dist[i][j]);
        }
    return;
}

bool check(int a, int i){
    if(passengers == k)
        if(i<=n) return false;
    if(dist[X[a-1]][i] == 0) return false; // Neu khong co duong di toi no -> false
    if(i>n)
        if(!visited[i-n]) return false;
    if(!visited[i]) return true;
    return false;
}

void solution(){
    distanceCur += dist[X[2*n]][0];
    distanceMin = min(distanceMin,distanceCur);
    distanceCur -= dist[X[2*n]][0];
}

void TRY(int a){
    for(int i=1; i<=2*n; i++){
        if(check(a,i)){
            X[a] = i;
            visited[i] = true;
            distanceCur += dist[X[a-1]][i];
            if(i<=n) passengers++;
            else passengers--;

            if(a == 2*n) solution();
            else
                if(distanceCur + (2*n - a)*minDist < distanceMin) TRY(a+1);

            if(i<=n) passengers--;
            else passengers++;
            visited[i] = false;
            distanceCur -= dist[X[a-1]][i];
        }
    }
}

int main(){
    inputData();
    findMin();
    X[0] = 0;
    TRY(1);
    cout << distanceMin;
    return 0;
}

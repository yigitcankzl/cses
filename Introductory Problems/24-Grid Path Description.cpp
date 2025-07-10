#include "bits/stdc++.h"
using namespace std;
#define int long long
int result = 0;
vector<pair<char, pair<int, int>>> directions = {{'U', {-1, 0}},{'D', {1, 0}},{'L', {0, -1}},{'R', {0, 1}}};
bool visited[7][7];

bool isValid(int x, int y) {
    return x >= 0 && x < 7 && y >= 0 && y < 7;
}

void dfs(int x, int y, int step, string s){
    if (step == 48){
        if ((x == 6 && y == 0)){
            result++;
        }
        return;
    }
    if ((x == 6 && y == 0)) return;
    if (step >= 48) return;
    
    int freeUp = (isValid(x-1, y) && !visited[x-1][y]) ? 1 : 0;
    int freeDown = (isValid(x+1, y) && !visited[x+1][y]) ? 1 : 0;
    int freeLeft = (isValid(x, y-1) && !visited[x][y-1]) ? 1 : 0;
    int freeRight = (isValid(x, y+1) && !visited[x][y+1]) ? 1 : 0;
    int freeHorizontal = freeLeft + freeRight;
    int freeVertical = freeUp + freeDown;
    
    if (x == 6 && y == 0) {
        if (freeHorizontal + freeVertical > 0) return;
    } else {
        if (freeHorizontal + freeVertical == 0) return;
    }
    
    if ((freeHorizontal == 0 && freeVertical == 2) || (freeVertical == 0 && freeHorizontal == 2)) return;
    
    visited[x][y] = true;
    
    bool shouldPrune = false;
    
    for (int dx = -1; dx <= 1; dx += 2) {
        for (int dy = -1; dy <= 1; dy += 2) {
            int nx = x + dx, ny = y + dy;
            if (isValid(nx, ny) && !visited[nx][ny]) {
                int diagFree = 0;
                if (isValid(nx-1, ny) && !visited[nx-1][ny]) diagFree++;
                if (isValid(nx+1, ny) && !visited[nx+1][ny]) diagFree++;
                if (isValid(nx, ny-1) && !visited[nx][ny-1]) diagFree++;
                if (isValid(nx, ny+1) && !visited[nx][ny+1]) diagFree++;
                if (diagFree < 2 && !(nx == 6 && ny == 0)) {
                    shouldPrune = true;
                    break;
                }
            }
        }
        if (shouldPrune) break;
    }
    
    if (!shouldPrune) {
        if (freeHorizontal == 2 && freeVertical == 0) {
            int leftX = x, leftY = y - 1;
            int rightX = x, rightY = y + 1;
            
            if (isValid(leftX, leftY) && !visited[leftX][leftY] && 
                isValid(rightX, rightY) && !visited[rightX][rightY]) {
                
                int leftNeighbors = 0, rightNeighbors = 0;
                if (isValid(leftX-1, leftY) && !visited[leftX-1][leftY]) leftNeighbors++;
                if (isValid(leftX+1, leftY) && !visited[leftX+1][leftY]) leftNeighbors++;
                if (isValid(leftX, leftY-1) && !visited[leftX][leftY-1]) leftNeighbors++;
                if (isValid(leftX, leftY+1) && !visited[leftX][leftY+1]) leftNeighbors++;
                if (isValid(rightX-1, rightY) && !visited[rightX-1][rightY]) rightNeighbors++;
                if (isValid(rightX+1, rightY) && !visited[rightX+1][rightY]) rightNeighbors++;
                if (isValid(rightX, rightY-1) && !visited[rightX][rightY-1]) rightNeighbors++;
                if (isValid(rightX, rightY+1) && !visited[rightX][rightY+1]) rightNeighbors++;
                if (leftNeighbors < 2 && rightNeighbors < 2 && 
                    !(leftX == 6 && leftY == 0) && !(rightX == 6 && rightY == 0)) {
                    shouldPrune = true;
                }
            }
        }
        
        if (!shouldPrune && freeVertical == 2 && freeHorizontal == 0) {
            int upX = x - 1, upY = y;
            int downX = x + 1, downY = y;
            
            if (isValid(upX, upY) && !visited[upX][upY] && 
                isValid(downX, downY) && !visited[downX][downY]) {
                
                int upNeighbors = 0, downNeighbors = 0;
                if (isValid(upX-1, upY) && !visited[upX-1][upY]) upNeighbors++;
                if (isValid(upX+1, upY) && !visited[upX+1][upY]) upNeighbors++;
                if (isValid(upX, upY-1) && !visited[upX][upY-1]) upNeighbors++;
                if (isValid(upX, upY+1) && !visited[upX][upY+1]) upNeighbors++;
                if (isValid(downX-1, downY) && !visited[downX-1][downY]) downNeighbors++;
                if (isValid(downX+1, downY) && !visited[downX+1][downY]) downNeighbors++;
                if (isValid(downX, downY-1) && !visited[downX][downY-1]) downNeighbors++;
                if (isValid(downX, downY+1) && !visited[downX][downY+1]) downNeighbors++;
                if (upNeighbors < 2 && downNeighbors < 2 && 
                    !(upX == 6 && upY == 0) && !(downX == 6 && downY == 0)) {
                    shouldPrune = true;
                }
            }
        }
    }
    
    if (shouldPrune) {
        visited[x][y] = false;
        return;
    }
    
    for (auto direction: directions){
        int next_x = x + direction.second.first;
        int next_y = y + direction.second.second;
        if (isValid(next_x, next_y) && !visited[next_x][next_y]) {
            if (s[step] == '?' || s[step] == direction.first){
                dfs(next_x, next_y, step+1, s);
            }
        }
    }
    visited[x][y] = false;
}

int32_t main() {
    string s;
    cin >> s;
    dfs(0,0,0,s);
    cout << result << endl;
    return 0;
}
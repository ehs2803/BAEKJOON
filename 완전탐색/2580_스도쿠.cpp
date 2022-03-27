#include<iostream>
using namespace std;

int map[9][9];
bool check_row[9][9];
bool check_col[9][9];
bool check_square[9][9];

void dfs(int row, int col)
{
	// 답 출력  
    if(row==9){
    	for(int i=0;i<9;i++){
    		for(int j=0;j<9;j++){
    			cout<<map[i][j]<<' ';
			}
			cout<<'\n';
		}
		exit(0); // 프로그램 종료.  
	}
	
    if (map[row][col] == 0){
        for (int i = 1; i <= 9; i++){
            if (check_row[row][i] == false && check_col[col][i] == false && check_square[(row / 3) * 3 + (col / 3)][i] == false){
                check_row[row][i] = true;
                check_col[col][i] = true;
                check_square[(row / 3) * 3 + (col / 3)][i] = true;
                map[row][col] = i;
                
                if(col==8) dfs(row+1,0);
    			else dfs(row, col+1);
    			
                check_row[row][i] = false;
                check_col[col][i] = false;
                check_square[(row / 3) * 3 + (col / 3)][i] = false;
                map[row][col] = 0;
            }
        }
    }
    else{
    	if(col==8) dfs(row+1,0);
    	else dfs(row, col+1);
	}
}

int main(){
	// 입력  
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++) {
			cin>>map[i][j];	
			if (map[i][j] != 0){
                check_row[i][map[i][j]] = true;
                check_col[j][map[i][j]] = true;
                check_square[(i / 3) * 3 + (j / 3)][map[i][j]] = true;
            }
		}
	}	
		
	dfs(0,0);
}

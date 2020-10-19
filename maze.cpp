#include<iostream>
using namespace std;
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
char block[64][64];
bool visited[64][64];
void solve_maze_DFS(int M,int N, int x, int y, int direction, int& path_num)
{
    
    visited[x][y]=1;
    //cout << block[x][y]<<endl;
    if(block[x][y] =='L')
    {
        if(x==0 && y==0)
        {
            if(N != 1)
            {
                //cout << "Hello"<<endl;
                solve_maze_DFS(M,N,x,y+1,RIGHT,path_num);
            }
            if(M != 1)
            {
                //cout << "Hello"<<endl;
                solve_maze_DFS(M,N,x+1,y,DOWN,path_num);
            }
        }
        else
        {
            if(direction == UP)
            {
                if(x!=0 && visited[x-1][y]!=1)
                solve_maze_DFS(M,N,x-1,y,UP,path_num);
            }
            else if(direction == DOWN)
            {
                if(x!=M-1 && visited[x+1][y]!=1)
                {
                    solve_maze_DFS(M,N,x+1,y,DOWN,path_num);
                }
                else if(x==M-1 && y==N-1)
                {
                    path_num++;
                }
            }
            else if (direction == LEFT)
            {
                if(y != 0 && visited[x][y-1]!=1)
                {
                    solve_maze_DFS(M,N,x,y-1,LEFT,path_num);
                }
            }
            else if (direction == RIGHT)
            {
                if(y != N-1 && visited[x][y+1]!=1)
                {
                    solve_maze_DFS(M,N,x,y+1,RIGHT,path_num);
                }
                else if(x == M-1 && y == N-1)
                {
                    path_num++;
                }
            }
        }
    }
    else if(block[x][y] == 'T')
    {
        if(direction == 0)
        {
            if(N != 1)solve_maze_DFS(M,N,x,y+1,RIGHT,path_num);
            if(M != 1)solve_maze_DFS(M,N,x+1,y,DOWN,path_num);
        }
        else if(direction == UP || direction == DOWN)
        {
            if(y != 0 && visited[x][y-1]!=1)
            {
                solve_maze_DFS(M,N,x,y-1,LEFT,path_num);
            }
            if(y != N-1 && visited[x][y+1]!=1)
            {
                solve_maze_DFS(M,N,x,y+1,RIGHT,path_num);
            }
            else if(x == M-1 && y == N-1)
            {
                path_num++;
            }
            
        }
        else if(direction == LEFT || direction == RIGHT)
        {
            if(x != 0 && visited[x-1][y]!=1)
            {
                solve_maze_DFS(M,N,x-1,y,UP,path_num);
            }
            if(x != M-1 && visited[x+1][y]!=1)
            {
                solve_maze_DFS(M,N,x+1,y,DOWN,path_num);
            }
            else if(x == M-1 && y == N-1)
            {
                path_num++;
            }
        }
    }
    visited[x][y]=0;
}
int main()
{
    int cas;
    cin >> cas;
    while(cas--)
    {
        int M,N;
        cin >> M >> N;
        for(int i = 0; i < M; i++)
         for(int j = 0; j < N; j++)
         {
             char ch;
             cin >> ch;
             block[i][j] = ch;
             visited[i][j] = 0;
         }
    int path_num = 0;
    if(N != 0 && M != 0)solve_maze_DFS(M,N,0,0,0,path_num);
    cout << "Number of legal solutions: " <<  path_num << endl;
    }
    return 0;
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int i, j, islands = 0, r, c, k;
        queue <pair<int,int>> todo;
        vector <int> offset_x{0,0,1,-1}, offset_y{1,-1,0,0};
        if(grid.size()==0)
            return islands;
        for(i=0;i<grid.size();i++){
            for(j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                   
                    grid[i][j] = '0';
                    islands++;
                    todo.push({i,j});
                    while(!todo.empty()){
                        pair <int,int> p;
                        p = todo.front();
                        todo.pop();
                        for(k=0;k<4;k++){
                            r = p.first;
                            c = p.second;
                            r = r + offset_x[k];
                            c = c + offset_y[k];
                            while(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c]=='1'){
                                grid[r][c]='0';
                                todo.push({r,c});
                                r = r + offset_x[k];
                                c = c + offset_y[k];
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};